#include "scenenode.h"
#include <iostream>

SceneNode::SceneNode(std::string _name) :
name(_name),
children({}),
update_required(true),
load_required(false)
{
}

void SceneNode::destroy() {
    for (auto i = children.begin(); i != children.end(); i++ ) {
        (*i)->release();
    }
  
    children.clear();
}

void SceneNode::updateSelf() {
}

void SceneNode::loadAll() {
    if (load_required) {
        loadSelf();
        load_required = false;
    }

    for(auto const& child : children) {
        child->loadAll();
    }
}

void SceneNode::updateAll() {
    if (update_required) {
        updateSelf();
        update_required = false;
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
