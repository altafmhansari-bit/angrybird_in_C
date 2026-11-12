#include "slingshot.h"

void SlingshotInit(Slingshot * slingshot){
    slingshot->position = (Vector2){140 , 440};
    slingshot ->scale = 0.3f;
slingshot -> texture = LoadTexture("assets/slingshot/slingshot.png");
}

void  SlingshotDraw(Slingshot * slingshot){
DrawTextureEx(slingshot->texture ,
slingshot->position, 0.0f , 
slingshot->scale , 
WHITE);
}

void SlingshotUnload(Slingshot * slingshot){
    UnloadTexture(slingshot->texture);
}

void SlingshotDrawBands(Slingshot * slingshot , Vector2 birdPosition){
    Vector2 upperFork = {
        190.0f, 445.0f
    };
    Vector2 lowerFork= {
        190.0f , 475.0f
    };
    DrawLineEx(upperFork , birdPosition , 4.0f, BROWN);
    DrawLineEx(lowerFork , birdPosition , 4.0f , BROWN);
}