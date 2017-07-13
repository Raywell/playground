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
                case GLFW_KEY_W:
                    camera->c_pos += camera->speed * camera->front;
                    camera->t_pos = camera->c_pos + camera->front;
                break;
                case GLFW_KEY_S:
                    camera->c_pos -= camera->speed * camera->front;
                    camera->t_pos = camera->c_pos + camera->front;
                break;
                case GLFW_KEY_A:
                    camera->c_pos -= glm::normalize(glm::cross(camera->front, camera->up)) * camera->speed;
                    camera->t_pos = camera->c_pos + camera->front;
                break;
                case GLFW_KEY_D:
                    camera->c_pos += glm::normalize(glm::cross(camera->front, camera->up)) * camera->speed;
                    camera->t_pos = camera->c_pos + camera->front;
                break;
            }
        }
    }
}

void InputManager::registerCamera(Camera* c) {
    camera = c;
}
