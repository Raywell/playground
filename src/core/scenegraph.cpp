#include "scenegraph.h"
#include "camera.h"
extern Camera *camera;

SceneGraph::SceneGraph()
{
    root = new SceneNode("root");

    // TODO : temporary assigining camera as node from here
    root->addChild(camera);
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
