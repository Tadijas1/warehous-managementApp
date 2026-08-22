#include <raylib.h>
#include <ui.hpp>

const int screenWidth = 1920;
const int screenHeight = 1080;

int main()
{
    //local variables
    Texture2D background_texture;
    float background_scale;
    
    //Initing window
    InitWindow(screenWidth, screenHeight, "werehous-managementApp");

    //loading and scalling background_texture
    background_texture = LoadTexture("textures/background.png");
    background_scale = static_cast<float>(GetScreenWidth()) / background_texture.width;
    
    //Setting FPS
    SetTargetFPS(60);
    
    //Creating objects
    Ui ui = Ui();

    while (!WindowShouldClose())
    {
        //Input
        
        // Update
        ui.Update();

        BeginDrawing();
            ClearBackground(GRAY);
            // Draw
            DrawTextureEx(background_texture, (Vector2){0, 30}, 0.0f, background_scale, WHITE);
            ui.Draw();
        EndDrawing();
    }
    
    CloseWindow();
}