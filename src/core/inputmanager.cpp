#include "inputmanager.h"

InputManager::InputManager(WindowManager* wm) :
    WM(wm)
{
}

InputManager::~InputManager() {
}

void InputManager::handle() {
    for (std::vector<int>::iterator key = registeredKeys.begin() ; key != registeredKeys.end(); ++key) {
        if(WM->getKeyState(*key) == GLFW_PRESS) {
            switch (*key) {
                case GLFW_KEY_ESCAPE:
                    WM->closeWindow();
                break;
            }
        }
    }
}

void InputManager::registerCamera(Camera c) {
}
