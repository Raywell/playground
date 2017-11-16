#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <chrono>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "windowmanager.h"
#include "inputmanager.h"
#include "renderer.h"
#include "statemanager.h"

using namespace std::literals;

extern InputManager *inputM;
extern WindowManager *windowM;
extern StateManager *stateM;
extern Renderer *R;

class Engine
{
public:
    typedef std::chrono::high_resolution_clock Clock;

    Engine();
    virtual ~Engine();

    void release() { delete this; }

    StateManager* getStateManager() {
        return stateM;
    }

    WindowManager* getWindowManager() {
        return windowM;
    }

    Renderer* getRenderer() {
        return R;
    }

    void run();

protected:
private:
    const std::chrono::nanoseconds frametime = 16ms;

    void loop();
};

#endif
