#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <vector>
#include <map>
#include <functional>
#include <utility>

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/ext.hpp>

#include "camera.h"

class InputManager
{
public:
    InputManager();
    virtual ~InputManager();

    void handleAllInput();
    void registerCallback(int key, int action, std::function<void(void)> callback);
    void keyCallback(int key, int action);
    void registerCamera(Camera* c); // TODO delete

    void setMousePos(double xpos, double ypos);
protected:
private:
    Camera *camera = NULL;
    
    // Associate to a pair KEY/ACTION a callback function list
    std::map<std::pair<int,int>, std::vector<std::function<void(void)>>> key_callbacks;

    glm::vec2 mouse_pos;
};

#endif
