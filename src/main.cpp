#include <raylib.h>
#include <button.hpp>
#include <button_tex.hpp>

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
    Button start = Button(200, 100, true, {0, 0}, true, 30);
    
    Button_tex exit = Button_tex("textures/cross.png", 0.03, 25, 25, false, {1890, 2});

    while (!WindowShouldClose())
    {
        //Input
        
        // Update
        
        BeginDrawing();
            ClearBackground(GRAY);
            // Draw
            DrawTextureEx(background_texture, (Vector2){0, 30}, 0.0f, background_scale, WHITE);
            start.Draw();
            exit.Draw();
        EndDrawing();
    }
    
    CloseWindow();
}