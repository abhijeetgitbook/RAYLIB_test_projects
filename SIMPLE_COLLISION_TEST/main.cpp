#include <cstdio>
#include "raylib.h"

int main()
{
    printf("Hello, this is my first program in Raylib c++");

    // window dimensions
    int width {800};
    int height {400};
    InitWindow(width, height, "SIMPLE COLLISION TEST");
    

    // circle coordinates
    int circle_x{175};
    int circle_y{100};
    int circle_radius{25};

    //circle edges
    int l_circle_x{circle_x - circle_radius};
    int r_circle_x{circle_x + circle_radius};
    int u_circle_y{circle_y - circle_radius};
    int d_circle_y{circle_y + circle_radius};

    // rectangle coordinates
    int posx{300};
    int posy{0};

    //rectangle dimensions
    int rec_width{50};
    int rec_height{50};

    //rectangle edges
    int l_rec_x {posx};
    int r_rec_x {posx + rec_width};
    int u_rec_y {posy};
    int d_rec_y {posy + rec_height};

    // collison bool
    bool collison_with_rec = 
                           d_rec_y >= u_circle_y &&
                           u_rec_y <= d_circle_y &&
                           l_rec_x <= r_circle_x &&
                           r_rec_x >= l_circle_x;

    int direction1{5};

    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        // clear background every frame
        ClearBackground(RED);
        
        //collison_with_rec
        if(collison_with_rec)
        {
            DrawText("GAME OVER", 400, 200, 20, WHITE);
            
        }
        else
        {
            // Game logic begins

            //update the edges
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            d_circle_y = circle_y + circle_radius;

            l_rec_x = posx;
            r_rec_x = posx + rec_width;
            u_rec_y = posy;
            d_rec_y = posy + rec_height;

            //update collision_with_rec
            collison_with_rec = 
                           d_rec_y >= u_circle_y &&
                           u_rec_y <= d_circle_y &&
                           l_rec_x <= r_circle_x &&
                           r_rec_x >= l_circle_x;

            DrawCircle(circle_x, circle_y, 25, WHITE);

            if (IsKeyDown(KEY_D) && circle_x < width)
            {
                circle_x = circle_x + 10;
            }
            if (IsKeyDown(KEY_A) && circle_x > 0)
            {
                circle_x = circle_x - 10;
            }
            if (IsKeyDown(KEY_S) && circle_y < height )
            {
                circle_y = circle_y +10;
            }
            if (IsKeyDown(KEY_W) && circle_y > 0)
            {
                circle_y = circle_y -10;
            }

            //rectangle 1

            DrawRectangle(posx, posy, rec_width, rec_height, GREEN);
            //move the rectangle 
            posy += direction1;
            if (posy > height || posy < 0)
            {
                direction1 = -direction1;
            }

            //rectangle 2
            DrawRectangle(posx + rec_height*2, posy - rec_height*5, rec_width, rec_height, GREEN);
            //move the rectangle 
            
            if (posy > height || posy < 0)
            {
                direction1 = direction1;
            }
            // Game logic end

        }



        
        EndDrawing();

    }
    CloseWindow();
    

}