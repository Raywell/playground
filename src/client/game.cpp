#include <core/engine.h>
#include "game.h"

Game::Game() {
}

void Game::run() {
    Engine *engine = new Engine(); // Creating Engine

    WindowManager *windowM = engine->getWindowManager();

    windowM->createRenderingWindow("My Game",800,600); // Create Window
    windowM->bindCloseWindowKeyAction(GLFW_KEY_ESCAPE, GLFW_PRESS); // Close button binding

    Camera *camera = new Camera(45.0f); // Creating Camera

    Renderer *R = engine->getRenderer();
    R->registerCamera(camera); // Registering Camera // TODO restructure

    StateManager *stateM = engine->getStateManager();
    SceneGraph *sGraph = stateM->getSceneGraph();
    SceneNode *root = sGraph->getRoot();

    // Building scenegraph
    root->addChild(camera); // Adding camera to root

    sGraph->debug_printGraphObjects(); // DEBUG : Printing names of objects in grap

    engine->run();

    engine->release();
}

