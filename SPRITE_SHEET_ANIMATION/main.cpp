// to use Texture2D and a sprite sheet for animation
#include "raylib.h"

int main()
{
    // dimensions of window
    const int window_width{720};
    const int window_height{400};
    //initialize window   
    InitWindow(window_width, window_height, "PLANET EARTH");

    // loading textures and defining parameters
    Texture2D earth = LoadTexture("textures/earth.png");
    Rectangle earthRec;
    earthRec.width = earth.width/50;
    earthRec.height = earth.height;
    earthRec.x = 0;
    earthRec.y = 0;
    Vector2 earthPos;
    earthPos.x = window_width/2 - earthRec.width/2;
    earthPos.y = window_height/2 - earthRec.height/2;
    // aniamtions frames
    int frame{};

    //constant do define how fast frmes changes
    const float updateTime{1.0/12.0};
    float runningTime{};

    SetTargetFPS(60);
    

    while(!WindowShouldClose())
    {
        BeginDrawing();
        //clear background every frame
        ClearBackground(BLACK);
        // implementing delta time to solve frame problem
        const float dT{GetFrameTime()};

        runningTime += dT;

        if (runningTime >= updateTime)
        {
            runningTime =0;

            //updating animation frame

            earthRec.x = frame * earthRec.width;
            frame ++ ;
            if (frame > 50)
            {
                frame = 0;
            }
        }
              
        // draw texture
        DrawTextureRec(earth, earthRec, earthPos, WHITE);



        EndDrawing();

    }
    UnloadTexture(earth);
    CloseWindow();
}