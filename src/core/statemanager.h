#ifndef STATEMANAGER_H
#define STATEMANAGER_H

class StateManager
{
public:
    StateManager();
    virtual ~StateManager();

    void init();
    void update(); // Save current state. Calculate new state
protected:
private:
};

#endif
