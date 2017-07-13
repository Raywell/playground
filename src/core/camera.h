#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/ext.hpp>

class Camera
{
public:
    Camera();
    virtual ~Camera();
    glm::mat4 lookAt();

    glm::vec3 c_pos; // Camera position
    glm::vec3 t_pos; // Target position
    glm::vec3 up; // Up vector
    float speed;
    glm::vec3 front;
protected:
private:
};

#endif
