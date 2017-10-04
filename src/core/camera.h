#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/ext.hpp>

class Camera
{
public:
    Camera(float _fov, float w_h_ratio);
    virtual ~Camera();
    glm::mat4 lookAt(glm::vec3 target);

    glm::vec3 c_pos; // Camera position
    glm::vec3 t_pos; // Target position
    glm::vec3 up; // Up vector
    glm::vec3 front;

    float speed;
    float fov; // In degrees
    glm::mat4 projection;
protected:
private:
};

#endif
