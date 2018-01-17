#include "scenenode.h"
#include <iostream>

SceneNode::SceneNode(std::string _name) :
name(_name)
{
}

void SceneNode::updateSelf() {
}

void SceneNode::updateAll() {
    if (has_changed) {
        updateSelf();
        has_changed = false;
    }

    for(auto const& child : children) {
        child->updateAll();
    }
}

void SceneNode::addChild(SceneNode* new_child) {
    new_child->setParent(this);
    children.push_back(new_child);
}

void SceneNode::debug_printObject(int level) {
    std::string prefix(level, ' ');

    std::cout << prefix << level << "." << name;

    if (!children.empty()) {
        std::cout << " {" << std::endl;
        for (auto i = children.begin(); i != children.end(); i++ ) {
            (*i)->debug_printObject(level+1);
        }
        std::cout << prefix << "}" << std::endl;
    } else {
        std::cout << "," << std::endl;
    }
}
