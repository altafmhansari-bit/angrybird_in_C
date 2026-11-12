#ifndef BACKGROUND_H 
#define BACKGROUND_H 
#include "raylib.h"

typedef struct 
{
    /* data */
    Texture2D Texture ;

}Background ;

void BackgroundInit(Background * background);
void BackgroundDraw(Background * background);
void BackgroundUnload(Background * background);

#endif