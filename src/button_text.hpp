#pragma once
#include <raylib.h>
#include <string>
#include "button.hpp"

class Button_text :public Button
{
    int textSize;
    void DrawTextInside();
    
    public:
    std::string text;
    Button_text(float width, float height, Color color, bool doCenter, Vector2 offset = {0, 0}, int textsize = 10, std::string text = "");

    void Draw();
};