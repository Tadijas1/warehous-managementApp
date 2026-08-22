#pragma once
#include <raylib.h>
#include "button.hpp"

class Button_texture :public Button
{
    Texture2D texture;
    
    public:
    Button_texture(const char *imagePath, float scale, float width, float height, Color color, bool doCenter, Vector2 offset);
    ~Button_texture();

    void Draw();
};