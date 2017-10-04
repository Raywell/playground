#include "camera.h"

Camera::Camera(float _fov, float w_h_ratio) :
    c_pos(glm::vec3(0.0f, 0.0f, 3.0f)),
    t_pos(glm::vec3(0.0f, 0.0f, 0.0f)),
    up(glm::vec3(0.0f, 1.0f, 0.0f)),
    front(glm::vec3(0.0f, 0.0f, -1.0f)),
    speed(0)
{
    fov = _fov;
    projection = glm::perspective(glm::radians(fov), w_h_ratio, 0.1f, 100.0f);
}

Camera::~Camera() {
}

glm::mat4 Camera::lookAt(glm::vec3 target) {
    return glm::lookAt(c_pos, target, up);
}
