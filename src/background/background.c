#include "background.h"

void BackgroundInit(Background * background){
background -> Texture = LoadTexture("assets/background.png");
}
void BackgroundDraw(Background * backgroud){
    DrawTexturePro(
backgroud -> Texture ,
(Rectangle) {
    0, 0 , (float)backgroud->Texture.width , 
    (float)backgroud->Texture.height
},
(Rectangle){
    0,0,1280 , 720
} , 
(Vector2){0,0},
 0.0f , WHITE
    );
}

void BackgroundUnload(Background * backgroud){
UnloadTexture(backgroud->Texture);
}