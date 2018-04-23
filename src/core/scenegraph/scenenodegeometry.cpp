#include "scenenodegeometry.h"
#include <iostream>

SceneNodeGeometry::SceneNodeGeometry(std::string name) :
SceneNode(name)
{
}

void SceneNodeGeometry::loadSelf() {
    geometry->load();
}

void SceneNodeGeometry::updateSelf() {
    // Self updating
    
}

void SceneNodeGeometry::setGeometry(Geometry *_geometry) {
    geometry = _geometry;
    setUpdatedFlg();
}

void SceneNodeGeometry::setPitch(glm::vec3 _pitch) {
    pitch = _pitch;
    setUpdatedFlg();
}

void SceneNodeGeometry::setYaw(glm::vec3 _yaw) {
    yaw = _yaw;
    setUpdatedFlg();
}

void SceneNodeGeometry::setRoll(glm::vec3 _roll) {
    roll = _roll;
    setUpdatedFlg();
}
