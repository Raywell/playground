#include <GLFW/glfw3.h>
#include "camera.h"

Camera::Camera(float _fov, float w_h_ratio) :
    c_pos(glm::vec3(0.0f, 0.0f, 3.0f)),
    target(glm::vec3(0.0f, 0.0f, 0.0f)),
    up(glm::vec3(0.0f, 1.0f, 0.0f)),
    front(glm::vec3(0.0f, 0.0f, -1.0f)),
    speed(0.1),
    fov(_fov)
{
    projection = glm::perspective(glm::radians(fov), w_h_ratio, 0.1f, 100.0f);
    view = glm::lookAt(c_pos, target, up);
}

Camera::~Camera() {
}

glm::mat4 Camera::getView() {
    return view;
}

glm::mat4 Camera::getProjection() {
    return projection;
}

void Camera::handleInput(int key) {
    switch (key) {
        case GLFW_KEY_E: // Look at the center
            front = glm::normalize(glm::vec3(0.0f, 0.0f, 0.0f) - c_pos);
        break;
        case GLFW_KEY_W:
            c_pos += speed * front;
        break;
        case GLFW_KEY_S:
            c_pos -= speed * front;
        break;
        case GLFW_KEY_A:
            c_pos -= glm::normalize(glm::cross(front, up)) * speed;
        break;
        case GLFW_KEY_D:
            c_pos += glm::normalize(glm::cross(front, up)) * speed;
        break;
    }

    target = c_pos + front;
    view = glm::lookAt(c_pos, target, up);
}
