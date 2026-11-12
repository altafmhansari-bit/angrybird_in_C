#ifndef TARGET_H
#define TARGET_H
#include "raylib.h"
#include "../bird/bird.h"
#define MAX_TARGET 10

typedef struct 
{
    /* data */
    Vector2 position ;
    float scale ;
    bool active ; //this is to check how many active pigs are there like if one got hit then he will will be removed and the active will be false
}Target;

typedef struct 
{
    /* data */
    Texture2D texture ;
    Target target[MAX_TARGET];
    int count;
}Targets;

void TargetsCheckCollision(Targets* targets , Bird * bird);
void  TargetInit(Targets * targets);
void TargetDraw(Targets * targets);
void TargetUnload(Targets * targets);



#endif