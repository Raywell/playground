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

    void handleAllInput();
    void registerCamera(Camera* c);
protected:
private:
    Camera *camera = NULL;
    WindowManager* WM;
    std::vector<int> registeredKeys = {
        GLFW_KEY_ESCAPE,
        GLFW_KEY_W,
        GLFW_KEY_A,
        GLFW_KEY_S,
        GLFW_KEY_D
    };

    double mouse_speed;
    double mouse_x_pos;
    double mouse_y_pos;
};

#endif
