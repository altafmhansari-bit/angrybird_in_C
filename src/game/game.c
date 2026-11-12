
#include "game.h"

void GameInit(Game *game, Targets *targets)
{
    game->score = 0;
    game->previousPigCount = 0;
    game->state = GAME_PLAYING;

    // Count currently active pigs
    for (int i = 0; i < targets->count; i++)
    {
        if (targets->target[i].active)
        {
            game->previousPigCount++;
        }
    }
}

void GameUpdate(
    Game *game,
    Targets *targets,
    Physics *physics
)
{
    if (game->state != GAME_PLAYING)
    {
        return;
    }

    int currentPigCount = 0;

    // Count remaining pigs
    for (int i = 0; i < targets->count; i++)
    {
        if (targets->target[i].active)
        {
            currentPigCount++;
        }
    }

    // Award 100 points for each newly destroyed pig
    if (currentPigCount < game->previousPigCount)
    {
        int destroyedPigs =
            game->previousPigCount - currentPigCount;

        game->score += destroyedPigs * 100;
    }

    game->previousPigCount = currentPigCount;

    // Check win condition first
    if (currentPigCount == 0)
    {
        game->state = GAME_WON;
        return;
    }

    // Check lose condition
    if (physics->hasStopped)
    {
        game->state = GAME_LOST;
    }
}

void GameDraw(Game *game)
{
    // Display score
    DrawText(
        TextFormat("Score: %d", game->score),
        30,
        25,
        30,
        WHITE
    );

    if (game->state == GAME_WON)
    {
        DrawRectangle(
            0, 0, 1280, 720,
            Fade(BLACK, 0.6f)
        );

        DrawText(
            "YOU WIN!",
            500, 280, 55, GREEN
        );

        DrawText(
            TextFormat("Final Score: %d", game->score),
            515, 350, 25, WHITE
        );

        DrawText(
            "Press R to Restart",
            520, 410, 25, WHITE
        );
    }

    else if (game->state == GAME_LOST)
    {
        DrawRectangle(
            0, 0, 1280, 720,
            Fade(BLACK, 0.6f)
        );

        DrawText(
            "GAME OVER",
            480, 280, 55, RED
        );

        DrawText(
            TextFormat("Final Score: %d", game->score),
            515, 350, 25, WHITE
        );

        DrawText(
            "Press R to Restart",
            520, 410, 25, WHITE
        );
    }
}

void GameReset(
    Game *game,
    Bird *bird,
    Physics *physics,
    Targets *targets,
    Block *block,
    Pillars *pillars
)
{
    // Reset physics values
    PhysicsInit(physics);

    // Return bird to slingshot
    bird->position = physics->anchor;
    bird->rotation = 0.0f;

    // Restore all pigs
    for (int i = 0; i < targets->count; i++)
    {
        targets->target[i].active = true;
    }

    // Restore the block
    block->active = true;

    // Restore all pillars
    for (int i = 0; i < pillars->count; i++)
    {
        pillars->pillar[i].active = true;
    }

    // Reset score and game state
    GameInit(game, targets);
}
