#include <raylib.h>
#include <game.hpp>

const int screenWidth = 1920;
const int screenHeight = 1080;

int main()
{
    //local variables
    Texture2D background_texture;
    float background_scale;
    
    //Initing window
    InitWindow(screenWidth, screenHeight, "warehous-managementApp");

    //loading and scalling background_texture
    background_texture = LoadTexture("textures/background.png");
    background_scale = static_cast<float>(GetScreenWidth()) / background_texture.width;
    
    //Setting FPS
    SetTargetFPS(60);
    
    //Creating objects
    Game game = Game();
    game.AddProfiles();

    while (!WindowShouldClose())
    {
        //Input
        game.InputAll();
        
        // Update
        game.UpdateAll();

        BeginDrawing();
            ClearBackground(GRAY);
            
            // Draw
            DrawTextureEx(background_texture, (Vector2){0, 30}, 0.0f, background_scale, WHITE);
            game.DrawAll();
        EndDrawing();
    }
    
    CloseWindow();
}