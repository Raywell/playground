#include <chrono>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "engine.h"

// Managers as globals
InputManager *inputM = NULL;
WindowManager *windowM = NULL;
StateManager *stateM = NULL;
Renderer *R = NULL;
SceneGraph *sceneGraph = NULL;
AssetManager *assetM = NULL;
BufferObjectManager *bufferObjectM = NULL;
ShaderManager *shaderM = NULL;

using namespace std::literals::chrono_literals;

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

Engine::Engine()
{
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    inputM = new InputManager();
    windowM = new WindowManager(this);
    stateM = new StateManager();
    R = new Renderer();
    sceneGraph = new SceneGraph();
    assetM = new AssetManager();
    bufferObjectM = new BufferObjectManager();
    shaderM = new ShaderManager();

    R->init();
    stateM->init();
}

Engine::~Engine() {
    delete shaderM;
    bufferObjectM->release();
    assetM->release();
    sceneGraph->release();
    R->release();
    stateM->release();
    windowM->release();
    inputM->release();
    glfwTerminate();
}

void Engine::initOnWindowCreation() {
    bufferObjectM->init();
}

void Engine::run() {
    loop();
}

void Engine::loop() {
    using clock = std::chrono::high_resolution_clock;

    std::chrono::nanoseconds timelag(0ns);
    auto time_start = clock::now();

    // Game loop
    while(!windowM->windowShouldClose())
    {
        auto delta_time = clock::now() - time_start;
        time_start = clock::now();
        timelag += std::chrono::duration_cast<std::chrono::nanoseconds>(delta_time);

        windowM->frameAction();

        while (timelag >= frametime) {
            timelag -= frametime;

            stateM->update();
        }

        float alpha = (float) timelag.count() / frametime.count();

        R->renderFrame(alpha);
    }
}
