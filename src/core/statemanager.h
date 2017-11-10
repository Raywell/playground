#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "scenegraph.h"

class StateManager
{
public:
    StateManager();
    virtual ~StateManager();

    void init();
    void update();
protected:
    SceneGraph *sgraph;
private:
};

#endif
