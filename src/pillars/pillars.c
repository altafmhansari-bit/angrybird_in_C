#include "pillars.h"
void PillarsInit(Pillars * pillars){
    pillars->texture = LoadTexture("assets/block/horizontal.png");
    pillars->texture2 = LoadTexture("assets/blocks/verticle.png");
 pillars->count = 3;

//Initializing First Pig We Will Totally Spawn Three Pigs In the Map

pillars->pillar[0].scale = 0.4f;
pillars->pillar[0].active = true;
pillars->pillar[0].position = (Vector2) {850 , 450};

//SECOND PILLAR  HERE 

pillars->pillar[1].scale = 0.5f;
pillars->pillar[1].active = true;
pillars->pillar[1].position = (Vector2) {950 , 550};
//THIRD PILLAR
pillars->pillar[2].scale = 0.45f;
pillars->pillar[2].active = true;
pillars->pillar[2].position = (Vector2) {750 , 680};

}

void PillarsDraw(Pillars * pillars){
    //PLACING A LOOP TO INTERATE THE PIGSSSSS
    for (int i = 0; i < pillars->count; i++)
    {
        /* code */
        if (!pillars->pillar[i].active)
      continue;
      Pillar * pillar = &pillars->pillar[i];
      Texture2D texture ;
      if (pillar->type == PILLAR_HORIZONTAL)
      {
        /* code */
        texture = pillars->texture;
      }else{
        texture = pillars->texture2;
      }
      

      Rectangle source = {
        0,0,(float)pillars->texture.width, (float)pillars->texture.height
      };

    Rectangle destination = {
        pillar->position.x,
        pillar->position.y,
        pillars->texture.width*pillar->scale,
        pillars->texture.height*pillar->scale
    };
    

           Vector2 origin = {
        destination.width/2,
        destination.height/2
    };


          DrawTexturePro(pillars->texture ,source , destination , origin , 0.0f ,WHITE);

    }

    
}
void PillarCheckCollision(Bird * bird  , Physics * physics , Pillars * pillars){
float birdRadius = bird->texture.width * bird->scale / 2.0f;
for ( int i  = 0; i < pillars->count; i++)
{
    /* code */
    if(!pillars->pillar[i].active){
        continue;
    }
    Pillar *pillar = &pillars->pillar[i];
    Texture2D texture ;
    if (pillar->type == PILLAR_VERTICLE)
    {
        /* code */
        texture = pillars->texture;
    }else
    {
        
        texture = pillars->texture2;
    }
    float width = texture.width * pillar->scale ;
    float height = texture.height * pillar->scale;

    Rectangle pillarRect = {
        pillar->position.x - width/2.0f,
        pillar->position.y - width/2.0f,
        width ,
        height
    };
    if (CheckCollisionCircleRec(bird->position ,birdRadius , pillarRect) && physics->isLaunched)
    {
        /* code */
        pillar->active = false;
        physics->velocity = (Vector2){0.0f , 0.0f};
        physics->hasStopped = true;
        break;
    }
    
    
    
}

}


void pillarsUnload(Pillars * pillars){
    UnloadTexture(pillars->texture);
        UnloadTexture(pillars->texture2);
}
