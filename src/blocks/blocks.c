
#include "blocks.h"

void BlockInit(Block *block)
{
    block->position = (Vector2){820.0f, 480.0f};

    block->texture = LoadTexture(
        "assets/blocks/block.png"
    );

    block->scale = 0.19f;
    block->active = true;
}

void BlockDraw(Block *block)
{
    if (!block->active)
    {
        /* code */
        return;
    }
    
    DrawTextureEx(
        block->texture,
        block->position,
        0.0f,
        block->scale,
        WHITE
    );
}

void BlockCheckCollision(
    Block *block,
    Bird *bird,
    Physics *physics
)
{
    float birdRadius =
        bird->texture.width * bird->scale / 2.0f;

    float blockWidth =
        block->texture.width * block->scale;

    float blockHeight =
        block->texture.height * block->scale;

    // Block rectangle: position is its top-left corner
    Rectangle blockRect = {
        block->position.x,
        block->position.y,
        blockWidth,
        blockHeight
    };
    if (!block->active)
    {
        /* code */
        return;
    }
    

    // Detect circle-rectangle collision
    if (
        CheckCollisionCircleRec(
            bird->position,
            birdRadius,
            blockRect
        )
        && physics->isLaunched
    )
    {
        block->active = false;
        physics->velocity = (Vector2){0.0f, 0.0f};
        physics->hasStopped = true;
    }
}

void BlockUnload(Block *block)
{
    UnloadTexture(block->texture);
}
