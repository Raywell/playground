#include "scenenode.h"
#include <iostream>

SceneNode::SceneNode(std::string name, int level) :
name(name),
level(level)
{
}

void SceneNode::update() {
    for(auto const& child : children) {
        child->update();
    }
}

void SceneNode::addChild(SceneNode* new_child) {
    new_child->setParent(this);
    new_child->setLevel(level+1);
    children.push_back(new_child);
}

void SceneNode::setLevel(int new_level) {
    int diff = new_level - level;
    addLevel(diff);
}

void SceneNode::addLevel(int diff) {
    level += diff;

    for (auto i = children.begin(); i != children.end(); i++ ) {
        (*i)->addLevel(diff);
    }
}

void SceneNode::debug_printObject() {
    std::string prefix(level, ' ');

    std::cout << prefix << level << "." << name;

    if (!children.empty()) {
        std::cout << " {" << std::endl;
        for (auto i = children.begin(); i != children.end(); i++ ) {
            (*i)->debug_printObject();
        }
        std::cout << prefix << "}" << std::endl;
    } else {
        std::cout << "," << std::endl;
    }
}
