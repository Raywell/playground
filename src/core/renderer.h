#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shadermanager.h"
#include "camera.h"

class Renderer
{
public:
    Renderer();
    virtual ~Renderer();

    Camera *camera; // TODO : move camera to statemanager

    void initData();
    void renderFrame(float alpha);
protected:
    ShaderManager *shadowM;

    glm::mat4 model;
    bool createRenderingWindow();
    unsigned int VAO = 0;
};

#endif
