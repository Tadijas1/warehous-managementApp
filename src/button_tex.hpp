#pragma once
#include <raylib.h>
#include "button.hpp"

class Button_tex :public Button
{
    Texture2D texture;
    
    public:
    Button_tex(const char *imagePath, float scale, float width, float height, bool doCenter, Vector2 offset);
    ~Button_tex();

    void Draw();
};