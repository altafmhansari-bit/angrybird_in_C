#ifndef SLINGSHOT_H
#define SLINGSHOT_H
#include "raylib.h"

typedef struct 
{
    /* data */
    Vector2 position;
    float scale ; 
    Texture2D texture ;

}Slingshot;


void SlingshotInit(Slingshot * slingshot);
void SlingshotDraw(Slingshot * slingshot);
void SlingshotUnload(Slingshot * slingshot);
void SlingshotDrawBands(Slingshot * slinshot ,
Vector2 birdPosition);


#endif