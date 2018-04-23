#include "scenegraph.h"

SceneGraph::SceneGraph()
{
    root = new SceneNode("root");
}

void SceneGraph::destroy() {
    root->release();
}

void SceneGraph::load() {
    root->loadAll();
}

void SceneGraph::update() {
    // Update all nodes
    root->updateAll();
}

void SceneGraph::debug_printGraphObjects() {
    root->debug_printObject();
}
