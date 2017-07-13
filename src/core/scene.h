#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shadermanager.h"
#include "windowmanager.h"
#include "camera.h"
#include "inputmanager.h"

class Scene
{
public:
    Scene();
    virtual ~Scene();

    void run();

    void beforeRun();
    // Rendering
    void render();

    // Handle user input
    void handleInput();

protected:
    Camera *camera;
    WindowManager *WM;
    ShaderManager *SM;
    InputManager *IM;
    glm::mat4 model,projection;
    bool createRenderingWindow();
    unsigned int VAO = 0;
};

#endif
