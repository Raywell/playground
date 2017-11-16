#ifndef SCENEGRAPH_H
#define SCENEGRAPH_H

#include "scenenode.h"

class SceneGraph
{
public:
    SceneGraph();
    virtual ~SceneGraph() { destroy(); }

    void destroy();
    void release() { delete this; }

    SceneNode* getRoot() {
        return root;
    }

    void init();
    void update();

    void debug_printGraphObjects();

protected:
private:
    SceneNode *root;
};

#endif
