#pragma once
#include <raylib.h>
#include <string>
#include "button.hpp"

class Button_text :public Button
{
    void DrawTextInside();

    protected:
    Color textColor;
    int textSize;
    
    public:
    std::string text;
    Button_text(float width, float height, Color color, bool doCenter, Vector2 offset = {0, 0}, int textsize = 10, Color textColor = WHITE, std::string text = "");

    void Draw();
};