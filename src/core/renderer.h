#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "statemanager.h"
#include "windowmanager.h"
#include "shadermanager.h"

class Renderer
{
public:
    Renderer(StateManager *stateManager, WindowManager *windowManager);
    virtual ~Renderer();

    Camera *camera; // TODO : move camera to statemanager

    void initData();
    void renderFrame(float alpha);
protected:
    StateManager *stateM;
    WindowManager *windowM;
    ShaderManager *shadowM;

    glm::mat4 model;
    bool createRenderingWindow();
    unsigned int VAO = 0;
};

#endif
