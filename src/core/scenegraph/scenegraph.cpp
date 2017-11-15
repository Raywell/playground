#include "scenegraph.h"

SceneGraph::SceneGraph()
{
    root = new SceneNode("root");
}

SceneGraph::~SceneGraph() {
    delete root;
}

void SceneGraph::init() {
}

void SceneGraph::update() {
    // Update all nodes
    root->update();
}
