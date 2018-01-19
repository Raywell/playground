#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <chrono>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <ireleasable.h>
#include "windowmanager.h"
#include "inputmanager.h"
#include "renderer.h"
#include "statemanager.h"

using namespace std::literals;

extern InputManager *inputM;
extern WindowManager *windowM;
extern StateManager *stateM;
extern Renderer *R;
extern SceneGraph *sceneGraph;

class Engine : public IReleasable
{
public:
    typedef std::chrono::high_resolution_clock Clock;

    Engine();
    virtual ~Engine();

    WindowManager* getWindowManager() {
        return windowM;
    }

    StateManager* getStateManager() {
        return stateM;
    }

    Renderer* getRenderer() {
        return R;
    }

    SceneGraph* getSceneGraph() {
        return sceneGraph;
    }

    void run();

protected:
private:
    const std::chrono::nanoseconds frametime = 16ms;

    void loop();
};

#endif
