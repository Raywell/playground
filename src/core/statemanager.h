#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "scenegraph/scenegraph.h"

class StateManager
{
public:
    StateManager();
    virtual ~StateManager();

    SceneGraph* getSceneGraph() {
        return sgraph;
    }

    void init();
    void update();
protected:
    SceneGraph *sgraph;
private:
};

#endif
