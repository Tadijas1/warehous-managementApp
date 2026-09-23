#include <raylib.h>
#include <game.hpp>

const int screenWidth = 1920;
const int screenHeight = 1080;

int main()
{
    
    //Initing window
    InitWindow(screenWidth, screenHeight, "warehous-managementApp");
    
    //Setting FPS
    SetTargetFPS(60);
    
    //Creating objects
    Game game = Game();

    while (!WindowShouldClose())
    {
        //Input
        game.InputAll();
        
        // Update
        game.UpdateAll();

        BeginDrawing();
            ClearBackground(Color{40, 40, 40, 255});
            
            // Draw
            game.DrawAll();
        EndDrawing();
    }
    
    CloseWindow();
}