#include "bird.h"

void BirdInit(Bird * bird){
    bird->position = (Vector2){200, 475};
    bird->rotation = 0.0f;
    bird->scale = 0.22f;
    bird->texture = LoadTexture("assets/birds/chuck.png");
    bird->texture = LoadTexture("assets/birds/red.png");
}

void BirdDraw(Bird * bird){
    Rectangle source = {
        0,0, (float)bird->texture.width,
        (float)bird->texture.height
    };

    Rectangle destination = {
        bird->position.x,
        bird->position.y,
        bird->texture.width*bird->scale,
        bird->texture.height*bird->scale
    };
   Vector2 origin = {
        destination.width/2,
        destination.height/2
    };
    


    DrawTexturePro(
        bird->texture, source , destination ,origin , bird->rotation , WHITE 
    );
    
 
}

void BirdUnload(Bird * bird){
    UnloadTexture(bird->texture);
}