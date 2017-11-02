#include <iostream>
#include <functional>
#include <stdexcept>
#include <glad/glad.h>
#include "windowmanager.h"

#include "inputmanager.h"

std::vector<std::function<void(int,int)>> g_keyHandlers;

extern InputManager *inputM;

WindowManager::WindowManager(int wRes, int hRes) :
width(wRes),
height(hRes)
{
    using namespace std::placeholders;
    addKeyHandler(std::bind(&InputManager::keyCallback, inputM, _1, _2));
}

WindowManager::~WindowManager() {
}

void WindowManager::init() {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    bindCloseWindowKeyAction(GLFW_KEY_ESCAPE, GLFW_PRESS);

    if (!this->createRenderingWindow()) {
        throw std::runtime_error("Unable to create rendering window");
    }
}

bool WindowManager::createRenderingWindow() {;
    this->window = glfwCreateWindow(width, height, "Main Window", NULL, NULL);
    if (this->window == NULL)
    {
        std::cout << "Failed to create GLFW this->window" << std::endl;
        glfwTerminate();
        return false;
    }
    
    glfwMakeContextCurrent(this->window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
    }

    glViewport(0, 0, width, height);

    auto framebuffer_size_callback = [](GLFWwindow* w, int width, int height)
    {
        glViewport(0, 0, width, height);
    };
    glfwSetFramebufferSizeCallback(this->window, framebuffer_size_callback);

    auto key_callback = [](GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        for(auto const& keyHandle : g_keyHandlers) {
            keyHandle(key, action);
        }
    };
    glfwSetKeyCallback(window, key_callback);

    return true;
}

bool WindowManager::windowShouldClose() {
    return glfwWindowShouldClose(this->window);
}

void WindowManager::swapBuffers() {
    glfwSwapBuffers(this->window);
}

void WindowManager::frameAction() {
    double mouse_x_pos, mouse_y_pos;
    glfwGetCursorPos(window, &mouse_x_pos, &mouse_y_pos); 
    glfwSetCursorPos(window, width/2, height/2);
    inputM->setMousePos(mouse_x_pos, mouse_y_pos);
}

void WindowManager::bindCloseWindowKeyAction(int key, int action) {
    inputM->registerCallback(key, action, [this]() {
        glfwSetWindowShouldClose(window, true);
    });
}
