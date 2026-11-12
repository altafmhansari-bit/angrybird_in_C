
#ifndef BLOCKS_H
#define BLOCKS_H

#include "raylib.h"
#include "../bird/bird.h"
#include "../physics/physics.h"

typedef struct
{
    Texture2D texture;
    Vector2 position;
    float scale;
    bool active;
} Block;

void BlockInit(Block *block);
void BlockDraw(Block *block);
void BlockUnload(Block *block);

void BlockCheckCollision(
    Block *block,
    Bird *bird,
    Physics *physics
);

#endif
