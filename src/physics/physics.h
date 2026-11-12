
#ifndef PHYSICS_H
#define PHYSICS_H

#include "raylib.h"
#include "../bird/bird.h"

typedef struct
{
    Vector2 anchor;
    Vector2 velocity;

    float maxPullDistance;
    float gravity;
    float launchPower;
    float groundY;

    bool isDragging;
    bool isLaunched;
    bool hasStopped;

} Physics;
void PhysicsInit(Physics *physics);

void PhysicsUpdate(
    Physics *physics,
    Bird *bird
);

#endif
