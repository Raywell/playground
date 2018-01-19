#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <ireleasable.h>
#include "scenegraph/scenegraph.h"

class StateManager : public IReleasable
{
public:
    StateManager();
    virtual ~StateManager() {};

    void init();
    void update();
protected:
private:
};

#endif
