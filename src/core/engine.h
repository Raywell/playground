#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <chrono>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "windowmanager.h"
#include "camera.h"
#include "inputmanager.h"
#include "renderer.h"
#include "statemanager.h"

using namespace std::literals;

class Engine
{
public:
    typedef std::chrono::high_resolution_clock Clock;

    Engine();
    virtual ~Engine();

    void run();

protected:
    Camera *camera;
    WindowManager *windowM;
    InputManager *inputM;
    StateManager *stateM;
    Renderer *R;
private:
    const std::chrono::nanoseconds frametime = 16ms;

    void loop();
};

#endif
