#ifndef SCENEGRAPH_H
#define SCENEGRAPH_H

#include "scenenode.h"

class SceneGraph
{
public:
    SceneGraph();
    virtual ~SceneGraph();

    SceneNode* getRoot() {
        return root;
    }

    void init();
    void update();
protected:
private:
    SceneNode *root;
};

#endif
