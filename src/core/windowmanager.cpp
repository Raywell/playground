#include <iostream>
#include <functional>
#include <stdexcept>
#include <glad/glad.h>
#include "windowmanager.h"

#include "inputmanager.h"
#include "renderer.h"
#include "engine.h"

std::vector<std::function<void(int,int)>> g_keyHandlers;

extern InputManager *inputM;
extern Renderer *R;
extern ShaderManager *shaderM;

WindowManager::WindowManager(Engine* _E) :
E(_E)
{
    using namespace std::placeholders;
    addKeyHandler(std::bind(&InputManager::keyCallback, inputM, _1, _2));

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

WindowManager::~WindowManager() {
}

void WindowManager::setWidthHeight(float _width, float _height) {
    width = _width;
    height = _height;
    glfwSetWindowSize(window, width, height);
}

void WindowManager::createRenderingWindow(std::string window_title, float _width, float _height) {
    width = _width;
    height = _height;

    this->window = glfwCreateWindow(width, height, window_title.c_str(), NULL, NULL);
    if (this->window == NULL)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        throw std::runtime_error("Unable to create rendering window");
    }
    
    glfwMakeContextCurrent(this->window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        throw std::runtime_error("Unable to create rendering window");
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

    glEnable(GL_DEPTH_TEST);
    E->initOnWindowCreation();
}

void WindowManager::closeWindow() {
    shaderM->deleteProgram();
    glfwSetWindowShouldClose(window, true);
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
        closeWindow();
    });
}
