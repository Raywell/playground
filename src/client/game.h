#ifndef GAME_H
#define GAME_H

#include <core/engine.h>

class Game
{
public:
    Game();
    ~Game();
    void run();

    void addDonut(SceneNode *node);

protected:
    Engine *engine;
};

#endif
