#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/ext.hpp>

class Camera
{
public:
    Camera(float _fov, int Wwidth, int Wheight);
    virtual ~Camera();
    glm::mat4 getView();
    glm::mat4 getProjection();

    void makeWASDEBindings(); // Temporary convenience
protected:
private:
    glm::vec3 c_pos; // Camera position
    glm::vec3 target; // Target position
    glm::vec3 up; // Up vector
    glm::vec3 front;

    float speed;
    float fov; // In degrees

    glm::vec2 mouse_offset;

    glm::mat4 projection;
    glm::mat4 view;

    void updateView();

    void lookAtCenter();
    void moveForward();
    void moveBackwards();
    void moveLeft();
    void moveRight();
};

#endif
