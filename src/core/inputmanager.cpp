#include "inputmanager.h"

InputManager::InputManager(WindowManager* wm) :
    WM(wm)
{
}

InputManager::~InputManager() {
}

void InputManager::handleAllInput() {
    glfwGetCursorPos(WM->getWindow(), &mouse_x_pos, &mouse_y_pos);
    glfwSetCursorPos(WM->getWindow(), WM->width/2, WM->height/2);

    for (std::vector<int>::iterator key = registeredKeys.begin() ; key != registeredKeys.end(); ++key) {
        if(WM->getKeyState(*key) == GLFW_PRESS) {
            camera->handleInput(*key);
            switch (*key) {
                case GLFW_KEY_ESCAPE:
                    WM->closeWindow();
                break;
            }
        }
    }
}

void InputManager::registerCamera(Camera* c) {
    camera = c;
}
