#include <iostream>
#include <GLFW/glfw3.h>
#include "scenenodetransform.h"

SceneNodeTransform::SceneNodeTransform(std::string name) :
SceneNode(name)
{
}

SceneNodeTransform::SceneNodeTransform(std::string name, glm::mat4 t_mat) :
SceneNode(name),
transform_matrix(t_mat)
{
}

void SceneNodeTransform::update() {
    // TODO : add to matrix stack

    SceneNode::update();

    // TODO : pop from matrix stack
}
