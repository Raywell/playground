#include "statemanager.h"

StateManager::StateManager()
{
    sgraph = new SceneGraph();
}

StateManager::~StateManager() {
    delete sgraph;
}

void StateManager::init() {
    sgraph->init();
}

void StateManager::update() {
    // 1. Backup current to previous
    // 2. Update the scenegraph
    sgraph->update();
}
