#pragma once
#include <raylib.h>
#include <string>
#include "button_text.hpp"

class Button_type :public Button_text
{
    std::string textUp;
    int textWidth;

    public:
    Button_type(float width, float height, Color color, bool doCenter, Vector2 offset = {0, 0}, int textsize = 10, Color textColor = BLACK, std::string textUp = "");

    void Update();
    void DrawTextUp();
    void DrawLine();
    void Draw();
};