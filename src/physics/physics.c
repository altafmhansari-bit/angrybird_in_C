
#include "physics.h"
#include "raymath.h"
void PhysicsInit(Physics *physics)
{
    // Original bird position
    physics->anchor.x = 220.0f;
physics->anchor.y = 500.0f;

    // Maximum pulling distance
    physics->maxPullDistance = 100.0f;

    physics->isDragging = false;
    physics->isLaunched = false;
    physics->velocity = (Vector2){0.0f , 0.0f};
    physics->gravity = 0.45f;
    physics->launchPower = 0.20f;
    physics->groundY = 620.0f;
physics->hasStopped = false;
}

void PhysicsUpdate(Physics *physics, Bird *bird)
{
    Vector2 mouse = GetMousePosition();

    float birdRadius =
        bird->texture.width * bird->scale / 2.0f;

    // 1. Detect click on bird
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)
        && !physics->isLaunched)
    {
        float distance = Vector2Distance(
            mouse,
            bird->position
        );

        if (distance <= birdRadius)
        {
            physics->isDragging = true;
        }
    }

    // 2. Handle dragging
    if (physics->isDragging)
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            float distance = Vector2Distance(
                mouse,
                physics->anchor
            );

            if (distance > physics->maxPullDistance)
            {
                Vector2 direction = Vector2Normalize(
                    Vector2Subtract(mouse, physics->anchor)
                );

                bird->position = Vector2Add(
                    physics->anchor,
                    Vector2Scale(
                        direction,
                        physics->maxPullDistance
                    )
                );
            }
            else
            {
                bird->position = mouse;
            }
        }

        // 3. Calculate launch velocity on release
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            physics->isDragging = false;
            physics->isLaunched = true;

            physics->velocity.x =
                (physics->anchor.x - bird->position.x)
                * physics->launchPower;

            physics->velocity.y =
                (physics->anchor.y - bird->position.y)
                * physics->launchPower;
        }
    }

    // 4. Projectile motion MUST be outside dragging condition
   if (physics->isLaunched && !physics->hasStopped)
{
    // Move bird
    bird->position.x += physics->velocity.x;
    bird->position.y += physics->velocity.y;

    // Apply gravity
    physics->velocity.y += physics->gravity;

    // Rotate bird
    bird->rotation += 5.0f;

    // Calculate bird radius
    float birdRadius =
        bird->texture.height * bird->scale / 2.0f;

    // Detect ground collision
    if (bird->position.y + birdRadius >= physics->groundY)
    {
        // Place bird exactly on the ground
        bird->position.y =
            physics->groundY - birdRadius;

        // Stop movement
        physics->velocity = (Vector2){0.0f, 0.0f};

        physics->hasStopped = true;
    }
}
}