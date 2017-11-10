#include <chrono>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "engine.h"

// Globals
InputManager *inputM;
WindowManager *windowM;
StateManager *stateM;
Renderer *R;
Camera *camera;

using namespace std::literals::chrono_literals;

Engine::Engine()
{
    glfwInit();

    inputM = new InputManager();

    windowM = new WindowManager(800,600);
    windowM->init();

    camera = new Camera(
        45.0f,
        windowM->width,
        windowM->height
    );

    inputM->registerCamera(camera);

    stateM = new StateManager();
    R = new Renderer();
    R->camera = camera; // TODO : remove (move camera to statemanager)
}

Engine::~Engine() {
    delete inputM;
    delete camera;
    delete windowM;
    delete stateM;
    delete R;
    glfwTerminate();
}

void Engine::run() {
    R->initData();
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
        inputM->handleAllInput();

        while (timelag >= frametime) {
            timelag -= frametime;

            stateM->update();
        }

        float alpha = (float) timelag.count() / frametime.count();

        R->renderFrame(alpha);
    }
}
