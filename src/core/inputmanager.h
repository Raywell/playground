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

#include <ireleasable.h>

class InputManager : public IReleasable
{
public:
    InputManager();
    virtual ~InputManager();

    void registerCallback(int key, int action, std::function<void(void)> callback);
    void keyCallback(int key, int action);

    void setMousePos(double xpos, double ypos);
protected:
private:
    // Associate to a pair KEY/ACTION a callback function list
    std::map<std::pair<int,int>, std::vector<std::function<void(void)>>> key_callbacks;

    glm::vec2 mouse_pos;
};

#endif
