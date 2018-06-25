#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <ireleasable.h>
#include "shadermanager.h"
#include "camera.h"

class Renderer : public IReleasable
{
public:
    Renderer();
    virtual ~Renderer();

    // TODO - move to statemanager ?
    void registerCamera(Camera *_camera) {
        camera = _camera;
    }

    void init();
    void renderFrame(float alpha);
protected:
    Camera *camera; // TODO : move camera to statemanager

    glm::mat4 model;
};

#endif
