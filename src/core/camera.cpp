#include "camera.h"

Camera::Camera() :
    c_pos(glm::vec3(0.0f, 0.0f, 3.0f)),
    t_pos(glm::vec3(0.0f, 0.0f, 0.0f)),
    up(glm::vec3(0.0f, 1.0f, 0.0f)),
    speed(0.05f),
    front(glm::vec3(0.0f, 0.0f, -1.0f))
{
}

Camera::~Camera() {
}

glm::mat4 Camera::lookAt() {
    return glm::lookAt(c_pos, t_pos, up);
}
