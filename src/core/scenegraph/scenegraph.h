#ifndef SCENEGRAPH_H
#define SCENEGRAPH_H

#include <ireleasable.h>
#include "scenenode.h"

class SceneGraph : public IReleasable
{
public:
    SceneGraph();
    virtual ~SceneGraph() { destroy(); }

    SceneNode* getRoot() {
        return root;
    }

    void init();
    void update();

    void debug_printGraphObjects();

protected:
    void destroy();
private:
    SceneNode *root;
};

#endif
