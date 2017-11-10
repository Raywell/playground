#include "scenenode.h"
#include <iostream>

SceneNode::SceneNode(std::string name) :
name(name)
{
}

SceneNode::~SceneNode() {
}

void SceneNode::update() {
    for(auto const& child : children) {
        child->update();
    }
}

void SceneNode::addChild(SceneNode* new_child) {
    children.push_back(new_child);
}
