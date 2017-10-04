#include <iostream>
#include <stdexcept>
#include <glad/glad.h>
#include "windowmanager.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

WindowManager::WindowManager(int wRes, int hRes) :
width(wRes),
height(hRes)
{
}

WindowManager::~WindowManager() {
}

void WindowManager::init() {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    if (!this->createRenderingWindow()) {
        throw std::runtime_error("Unable to create rendering window");
    }
}

bool WindowManager::createRenderingWindow() {;
    this->window = glfwCreateWindow(width, height, "MyProgram", NULL, NULL);
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
    glfwSetFramebufferSizeCallback(this->window, framebuffer_size_callback);

    return true;
}

bool WindowManager::windowShouldClose() {
    return glfwWindowShouldClose(this->window);
}

void WindowManager::swapBuffers() {
        glfwSwapBuffers(this->window);
}

void WindowManager::closeWindow() {
    glfwSetWindowShouldClose(window, true);
}

int WindowManager::getKeyState(int key) {
    return glfwGetKey(window, key);
}
