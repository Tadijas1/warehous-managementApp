#include <raylib.h>

const int screenWidth = 1000;
const int screenHeight = 1000;

int main()
{
    //Initing window
    InitWindow(screenWidth, screenHeight, "magazine-managementApp");
    
    //Setting FPS
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        //Input
        
        // Update
        
        BeginDrawing();
            ClearBackground(GREEN);
            // Draw

        EndDrawing();
    }
    
    CloseWindow();
}