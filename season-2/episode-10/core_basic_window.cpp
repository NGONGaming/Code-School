/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

#include "player.h"
#include "enemies.h"

int main(int argc, char* argv[])
{
    int screenWidth = 800;
    int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "episode10");

    SetTargetFPS(60);
    
    Player bob(0, 0);
    Enemies enemies(5000);

    while (!WindowShouldClose())
    {
        bob.OnKeyTyped();
        bob.OnKeyReleased();

        bob.Update(nullptr, 0);
        enemies.Update(bob.myBullets, bob.myBulletCount);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        bob.Draw();
        enemies.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}