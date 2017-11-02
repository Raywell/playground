#include <GLFW/glfw3.h>
#include "camera.h"

#include "inputmanager.h"

extern InputManager *inputM;

Camera::Camera(float _fov, int Wwidth, int Wheight) :
    c_pos(glm::vec3(0.0f, 0.0f, 3.0f)),
    target(glm::vec3(0.0f, 0.0f, 0.0f)),
    up(glm::vec3(0.0f, 1.0f, 0.0f)),
    front(glm::vec3(0.0f, 0.0f, -1.0f)),
    speed(0.1),
    fov(_fov)
{
    mouse_offset = glm::vec2((float)Wwidth / 2, (float)Wheight / 2);
    projection = glm::perspective(glm::radians(fov), (float)Wwidth/(float)Wheight, 0.1f, 100.0f);
    view = glm::lookAt(c_pos, target, up);

    makeWASDEBindings();
}

Camera::~Camera() {
}

glm::mat4 Camera::getView() {
    return view;
}

glm::mat4 Camera::getProjection() {
    return projection;
}

void Camera::makeWASDEBindings() {
    inputM->registerCallback(GLFW_KEY_W, GLFW_PRESS, [this]() {
        moveForward();
    });
    inputM->registerCallback(GLFW_KEY_A, GLFW_PRESS, [this]() {
        moveLeft();
    });
    inputM->registerCallback(GLFW_KEY_S, GLFW_PRESS, [this]() {
        moveBackwards();
    });
    inputM->registerCallback(GLFW_KEY_D, GLFW_PRESS, [this]() {
        moveRight();
    });
    inputM->registerCallback(GLFW_KEY_E, GLFW_PRESS, [this]() {
        lookAtCenter();
    });
}

void Camera::updateView() {
    target = c_pos + front;
    view = glm::lookAt(c_pos, target, up);
}

void Camera::lookAtCenter() {
    front = glm::normalize(glm::vec3(0.0f, 0.0f, 0.0f) - c_pos);
    updateView();
}

void Camera::moveForward() {
    c_pos += speed * front;
    updateView();
}

void Camera::moveBackwards() {
    c_pos -= speed * front;
    updateView();
}

void Camera::moveLeft() {
    c_pos -= glm::normalize(glm::cross(front, up)) * speed;
    updateView();
}

void Camera::moveRight() {
    c_pos += glm::normalize(glm::cross(front, up)) * speed;
    updateView();
}
