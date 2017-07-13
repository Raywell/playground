#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <vector>
#include <GLFW/glfw3.h>
#include "windowmanager.h"
#include "camera.h"

class InputManager
{
public:
    InputManager(WindowManager* wm);
    virtual ~InputManager();

    void handle();
    void registerCamera(Camera c);
protected:
private:
    WindowManager* WM;
    std::vector<int> registeredKeys = {
        GLFW_KEY_ESCAPE,
        GLFW_KEY_W,
        GLFW_KEY_A,
        GLFW_KEY_S,
        GLFW_KEY_D
    };
};

#endif
