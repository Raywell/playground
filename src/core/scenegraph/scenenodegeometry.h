#ifndef SCENENODEGEOMETRY_H
#define SCENENODEGEOMETRY_H

#include <list>
#include <string>

#include "scenenode.h"

class SceneNodeGeometry : public SceneNode
{
public:
    SceneNodeGeometry(std::string name);
    virtual ~SceneNodeGeometry() { };

    void update();

protected:
private:
};

#endif
