
#ifndef GAME_H
#define GAME_H

#include "raylib.h"

#include "../bird/bird.h"
#include "../physics/physics.h"
#include "../targets/target.h"
#include "../blocks/blocks.h"
#include "../pillars/pillars.h"

typedef enum
{
    GAME_PLAYING,
    GAME_WON,
    GAME_LOST

} GameState;

typedef struct
{
    int score;
    int previousPigCount;
    GameState state;

} Game;

void GameInit(Game *game, Targets *targets);

void GameUpdate(
    Game *game,
    Targets *targets,
    Physics *physics
);

void GameDraw(Game *game);

void GameReset(
    Game *game,
    Bird *bird,
    Physics *physics,
    Targets *targets,
    Block *block,
    Pillars *pillars
);

#endif
