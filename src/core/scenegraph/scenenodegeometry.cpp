#include "scenenodegeometry.h"
#include <iostream>

SceneNodeGeometry::SceneNodeGeometry(std::string name) :
SceneNode(name)
{
}

void SceneNodeGeometry::update() {
    // Update self

    // Update default
    SceneNode::update();
}
