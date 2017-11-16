#ifndef SCENENODETRANSFORM_H
#define SCENENODETRANSFORM_H

#include <list>
#include <string>

#include "scenenode.h"

class SceneNodeTransform : public SceneNode
{
public:
    SceneNodeTransform(std::string name);
    SceneNodeTransform(std::string name, glm::mat4 t_mat);
    virtual ~SceneNodeTransform() { };

    void setTransformMatrix(glm::mat4 t_mat) { transform_matrix = t_mat; }
        
    void update();

protected:
private:
    glm::mat4 transform_matrix;
};

#endif
