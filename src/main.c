#include "raylib.h"
#include "background/background.h"
#include "slingshot/slingshot.h"
#include "bird/bird.h"
#include "targets/target.h"
#include "blocks/blocks.h"
#include "pillars/pillars.h"
#include "physics/physics.h"
#include "game/game.h"

int main() {
    InitWindow(1280 , 720 , "Angry bird in C");
    SetTargetFPS(60);
    Background background = {0};
    Slingshot slingshot = {0};
    Bird bird = {0};
    Targets targets = {0};
    Block block = {0};
    Pillars pillars = {0};
    Physics physics ={0};
    Game game = {0};
    GameInit(&game , &targets);
    PhysicsInit(&physics);
    BackgroundInit(&background);
    SlingshotInit(&slingshot);
    BirdInit(&bird);
    TargetInit(&targets);
    BlockInit(&block);
    PillarsInit(&pillars);
    while (!WindowShouldClose())
    {
        /* code */
        if (game.state == GAME_PLAYING)
        {
            /* code */
            PhysicsUpdate(&physics , & bird);
            TargetsCheckCollision(&targets , &bird);
                    BlockCheckCollision(&block , &bird , &physics);
        PillarCheckCollision(&bird , &physics , &pillars);
  GameUpdate(&game , &targets , &physics);
        }
        //restart logic
        if (game.state != GAME_PLAYING && IsKeyPressed(KEY_R))
        {
            /* code */
            GameReset(&game , &bird , &physics , &targets , &block , &pillars);
        }
        
      BeginDrawing();
      ClearBackground(RAYWHITE);
        BackgroundDraw(&background);
SlingshotDraw(&slingshot);
BirdDraw(&bird);
SlingshotDrawBands(&slingshot , bird.position);
TargetDraw(&targets);
BlockDraw(&block);
PillarsDraw(&pillars);
DrawLine(
    0,
    (int)physics.groundY,
    1280,
    (int)physics.groundY,
    DARKGREEN
);
        DrawText("AngryBird In C" , 500 ,50 , 34 , BLACK);
        GameDraw(&game);
        EndDrawing();

    }

    
        BackgroundUnload(&background);
        SlingshotUnload(&slingshot);
        BirdUnload(&bird);
        TargetUnload(&targets);
        BlockUnload(&block);
        pillarsUnload(&pillars);
    CloseWindow();

  
    return 0 ;
    
}