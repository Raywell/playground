#include "scenegraph.h"

SceneGraph::SceneGraph()
{
    root = new SceneNode("root");
}

void SceneGraph::destroy() {
    root->release();
}

void SceneGraph::init() {
}

void SceneGraph::update() {
    // Update all nodes
    root->update();
}

void SceneGraph::debug_printGraphObjects() {
    root->debug_printObject();
}
