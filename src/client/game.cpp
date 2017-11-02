#include <core/engine.h>
#include "game.h"

Game::Game() {
}

void Game::run() {
    Engine *engine = new Engine();
    engine->run();

    delete engine;
}

