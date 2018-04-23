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
BufferManager *bufferM = NULL;

using namespace std::literals::chrono_literals;

Engine::Engine()
{
    glfwInit();

    inputM = new InputManager();
    windowM = new WindowManager();
    stateM = new StateManager();
    R = new Renderer();
    sceneGraph = new SceneGraph();
    assetM = new AssetManager();
    bufferM = new BufferManager();
}

Engine::~Engine() {
    bufferM->release();
    assetM->release();
    sceneGraph->release();
    R->release();
    stateM->release();
    windowM->release();
    inputM->release();
    glfwTerminate();
}

void Engine::run() {
    R->initData(); // TODO remove
    stateM->init();

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
