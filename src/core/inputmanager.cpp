#include "inputmanager.h"

InputManager::InputManager(WindowManager* wm) :
    WM(wm),
    mouse_speed(0.05f)
{
}

InputManager::~InputManager() {
}

void InputManager::handleAllInput() {
    glfwGetCursorPos(WM->getWindow(), &mouse_x_pos, &mouse_y_pos);
    glfwSetCursorPos(WM->getWindow(), WM->width/2, WM->height/2);

    for (std::vector<int>::iterator key = registeredKeys.begin() ; key != registeredKeys.end(); ++key) {
        if(WM->getKeyState(*key) == GLFW_PRESS) {
            switch (*key) {
                case GLFW_KEY_ESCAPE:
                    WM->closeWindow();
                break;
                case GLFW_KEY_W:
                    camera->c_pos += camera->speed * camera->front;
                break;
                case GLFW_KEY_S:
                    camera->c_pos -= camera->speed * camera->front;
                break;
                case GLFW_KEY_A:
                    camera->c_pos -= glm::normalize(glm::cross(camera->front, camera->up)) * camera->speed;
                break;
                case GLFW_KEY_D:
                    camera->c_pos += glm::normalize(glm::cross(camera->front, camera->up)) * camera->speed;
                break;

                camera->t_pos = camera->front;
            }
        }
    }
}

void InputManager::registerCamera(Camera* c) {
    camera = c;
}
