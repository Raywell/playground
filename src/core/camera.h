#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/ext.hpp>

#include "scenegraph/scenenode.h"

class Camera : public SceneNode
{
public:
    Camera(float _fov);
    virtual ~Camera();

    // Override
    void update();

    glm::mat4 getView();
    glm::mat4 getProjection();

    void makeWASDEBindings(); // Temporary convenience
protected:
private:
    glm::vec3 c_pos; // Camera position
    glm::vec3 target; // Target position
    glm::vec3 up; // Up vector
    glm::vec3 front;

    glm::vec3 movement; // Movement vector. Front : y. Right: x. Up: z.
    float speed;
    float fov; // In degrees

    glm::vec2 mouse_offset;

    glm::mat4 projection;
    glm::mat4 view;

    void updateView();

    void lookAtCenter();
    void setMoveForward(float val);
    void setMoveStrafe(float val);
};

#endif
