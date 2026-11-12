#ifndef BIRD_H
#define BIRD_H

#include "raylib.h"

typedef struct 
{
    /* data */
    Vector2 position;
    float scale ; 
    float rotation;
    Texture2D texture ;

}Bird;


void BirdInit(Bird * bird);
void BirdDraw(Bird * bird);
void BirdUnload(Bird * bird);


#endif