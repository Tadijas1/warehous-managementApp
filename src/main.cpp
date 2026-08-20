#include <raylib.h>

const int screenWidth = 612;
const int screenHeight = 438;

int main()
{
    //local variables
    Texture2D background_texture;
    float background_scale;
    
    //Initing window
    InitWindow(screenWidth, screenHeight, "magazine-managementApp");

    //loading and scalling background_texture
    background_texture = LoadTexture("textures/background.png");
    background_scale = static_cast<float>(GetScreenWidth()) / background_texture.width;
    
    //Setting FPS
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        //Input
        
        // Update
        
        BeginDrawing();
            ClearBackground(GRAY);
            // Draw
            DrawTextureEx(background_texture, (Vector2){0, 30}, 0.0f, background_scale, WHITE);
        EndDrawing();
    }
    
    CloseWindow();
}