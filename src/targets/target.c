#include "target.h"
#include "raymath.h"
void TargetInit(Targets * targets){
targets->texture = LoadTexture("assets/targets/pg1.png");
targets->count = 3;

//Initializing First Pig We Will Totally Spawn Three Pigs In the Map

targets->target[0].scale = 0.1f;
targets->target[0].active = true;
targets->target[0].position = (Vector2) {850 , 450};

//SECOND PIG  HERE 

targets->target[1].scale = 0.1f;
targets->target[1].active = true;
targets->target[1].position = (Vector2) {950 , 550};

//THIRD PIG
targets->target[2].scale = 0.1f;
targets->target[2].active = true;
targets->target[2].position = (Vector2) {750 , 500};

}

void TargetDraw(Targets * targets){
    //PLACING A LOOP TO INTERATE THE PIGSSSSS
    for (int i = 0; i < targets->count; i++)
    {
        /* code */
        if (!targets->target[i].active)
      continue;
      Target * target = &targets->target[i];

      Rectangle source = {
        0,0,(float)targets->texture.width, (float)targets->texture.height
      };

    Rectangle destination = {
        target->position.x,
        target->position.y,
        targets->texture.width*target->scale,
        targets->texture.height*target->scale
    };
           Vector2 origin = {
        destination.width/2,
        destination.height/2
    };
      DrawTexturePro(targets->texture ,source , destination , origin , 0.0f ,WHITE);
    }

    
}
void TargetsCheckCollision(Targets * targets , Bird * bird){
  float birdRadius = bird->texture.width * bird->scale /2.0f;
  float pigRadius = targets->texture.width * 0.35f /2.0f ;
  for (int i = 0; i < targets->count; i++)
  {
    /* code */
    if(!targets->target[i].active){
      continue;
    }
    DrawTextureEx(targets->texture , targets->target[i].position , 0.0f , targets->target[i].scale , WHITE);
    float distance = Vector2Distance(bird->position , targets->target[i].position);
    if (distance <= birdRadius + pigRadius)
    {
      /* code */
      targets->target[i].active = false;

      //this will stop the bird after hitting the target
      bird->position.x = bird->position.x;
    }
    
  }
  
}

void TargetUnload(Targets * targets){
    UnloadTexture(targets->texture);
}