#ifndef SCENENODEGEOMETRY_H
#define SCENENODEGEOMETRY_H

#include <list>
#include <string>

#include "scenenode.h"
#include "mesh.h"

class SceneNodeGeometry : public SceneNode
{
public:
    explicit SceneNodeGeometry(std::string name);
    virtual ~SceneNodeGeometry() { };

    void updateSelf();

    void setMesh(Mesh *_mesh) { mesh = _mesh; }
    void setPitch(glm::vec3 _pitch) { pitch = _pitch; }
    void setYaw(glm::vec3 _yaw) { yaw = _yaw; }
    void setRoll(glm::vec3 _roll) { roll = _roll; }

    Mesh* getMesh() { return mesh; }
    glm::vec3 getPitch() { return pitch; }
    glm::vec3 getYaw() { return yaw; }
    glm::vec3 getRoll() { return roll; }

protected:
    Mesh *mesh;
    glm::vec3 pitch;
    glm::vec3 yaw;
    glm::vec3 roll;
private:
};

#endif
