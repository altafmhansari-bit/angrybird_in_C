#ifndef PILLAR_H
#define PILLAR_H
#define MAX_PILLARS 10
#include "raylib.h"
#include "../bird/bird.h"
#include "../physics/physics.h"

typedef enum {
    PILLAR_HORIZONTAL ,
    PILLAR_VERTICLE
}PillarType;

typedef struct 
{
    /* data */
    Vector2 position ;
    float scale ;
    bool active ; //this is to check how many active pillars are there like if one got hit then he will will be removed and the active will be false
PillarType type;
}Pillar;

typedef struct 
{
    /* data */
    Texture2D texture ;
    Texture2D texture2 ;
    Pillar pillar[MAX_PILLARS];
    int count;
}Pillars;


void PillarsInit(Pillars * pillars);
void PillarsDraw(Pillars * pillars);
void PillarCheckCollision(Bird * bird  , Physics * physics , Pillars * pillars);

void pillarsUnload(Pillars * pillars);

#endif


