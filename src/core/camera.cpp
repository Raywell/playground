#include <GLFW/glfw3.h>
#include "camera.h"

#include "inputmanager.h"
#include "windowmanager.h"

extern InputManager *inputM;
extern WindowManager *windowM;

Camera::Camera(float _fov) :
    SceneNode("camera"),
    c_pos(glm::vec3(0.0f, 0.0f, 3.0f)),
    target(glm::vec3(0.0f, 0.0f, 0.0f)),
    up(glm::vec3(0.0f, 1.0f, 0.0f)),
    front(glm::vec3(0.0f, 0.0f, -1.0f)),
    movement(glm::vec3(0.0f, 0.0f, 0.0f)),
    speed(0.1f),
    fov(_fov)
{
    float width = windowM->getWidth();
    float height = windowM->getHeight();
    mouse_offset = glm::vec2((float)width / 2, (float)height / 2);
    projection = glm::perspective(glm::radians(fov), (float)width/(float)height, 0.1f, 100.0f);
    view = glm::lookAt(c_pos, target, up);

    makeWASDEBindings();
}

Camera::~Camera() {
}

glm::mat4 Camera::getView() {
    updateView(); // TODO - move elsewhere
    return view;
}

glm::mat4 Camera::getProjection() {
    return projection;
}

void Camera::makeWASDEBindings() {
    inputM->registerCallback(GLFW_KEY_W, GLFW_PRESS, [this]() {
        setMoveForward(1.0f);
    });
    inputM->registerCallback(GLFW_KEY_W, GLFW_RELEASE, [this]() {
        setMoveForward(-1.0f);
    });
    inputM->registerCallback(GLFW_KEY_A, GLFW_PRESS, [this]() {
        setMoveStrafe(-1.0f);
    });
    inputM->registerCallback(GLFW_KEY_A, GLFW_RELEASE, [this]() {
        setMoveStrafe(1.0f);
    });
    inputM->registerCallback(GLFW_KEY_S, GLFW_PRESS, [this]() {
        setMoveForward(-1.0f);
    });
    inputM->registerCallback(GLFW_KEY_S, GLFW_RELEASE, [this]() {
        setMoveForward(1.0f);
    });
    inputM->registerCallback(GLFW_KEY_D, GLFW_PRESS, [this]() {
        setMoveStrafe(1.0f);
    });
    inputM->registerCallback(GLFW_KEY_D, GLFW_RELEASE, [this]() {
        setMoveStrafe(-1.0f);
    });
    inputM->registerCallback(GLFW_KEY_E, GLFW_PRESS, [this]() {
        lookAtCenter();
    });
}

/* Called every frame */
void Camera::update() {
    c_pos += speed * front * movement.y;
    c_pos += glm::normalize(glm::cross(front, up)) * speed * movement.x;
}

void Camera::updateView() {
    target = c_pos + front;
    view = glm::lookAt(c_pos, target, up);
}

void Camera::lookAtCenter() {
    front = glm::normalize(glm::vec3(0.0f, 0.0f, 0.0f) - c_pos);
}

void Camera::setMoveForward(float val) {
    movement.y += val;
}

void Camera::setMoveStrafe(float val) {
    movement.x += val;
}
