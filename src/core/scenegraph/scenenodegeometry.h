#ifndef SCENENODEGEOMETRY_H
#define SCENENODEGEOMETRY_H

#include <list>
#include <string>

#include "scenenode.h"
#include "../assets/geometry.h"

class SceneNodeGeometry : public SceneNode
{
public:
    explicit SceneNodeGeometry(std::string name);
    virtual ~SceneNodeGeometry() { };

    void loadSelf();
    void updateSelf();

    void setGeometry(Geometry *_geometry);
    void setPitch(glm::vec3 _pitch);
    void setYaw(glm::vec3 _yaw);
    void setRoll(glm::vec3 _roll);

    Geometry* getGeometry() { return geometry; }
    glm::vec3 getPitch() { return pitch; }
    glm::vec3 getYaw() { return yaw; }
    glm::vec3 getRoll() { return roll; }

protected:
    Geometry *geometry;
    glm::vec3 pitch;
    glm::vec3 yaw;
    glm::vec3 roll;
private:
};

#endif
