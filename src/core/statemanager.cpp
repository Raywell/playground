#include "statemanager.h"

extern SceneGraph *sceneGraph;

StateManager::StateManager()
{
}

void StateManager::init() {
}

void StateManager::update() {
    // 1. Backup current to previous
    // 2. Update the scenegraph
    sceneGraph->update();
}
