#include "scenenodegeometry.h"
#include <iostream>

SceneNodeGeometry::SceneNodeGeometry(std::string name) :
SceneNode(name)
{
}

void SceneNodeGeometry::updateSelf() {
    // Self updating
    
}

void SceneNodeGeometry::setGeometry(Geometry *_geometry) {
    geometry = _geometry;
    setChanged();
}

void SceneNodeGeometry::setPitch(glm::vec3 _pitch) {
    pitch = _pitch;
    setChanged();
}

void SceneNodeGeometry::setYaw(glm::vec3 _yaw) {
    yaw = _yaw;
    setChanged();
}

void SceneNodeGeometry::setRoll(glm::vec3 _roll) {
    roll = _roll;
    setChanged();
}
