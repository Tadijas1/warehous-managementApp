#pragma once
#include <raylib.h>
#include <string>
#include "button_text.hpp"

class Button_type :public Button_text
{
    std::string textUp;

    int textWidth;
    
    public:
    bool isWrong;

    Button_type(float width, float height, Color color, bool doCenter, Vector2 offset = {0, 0}, int textSize = 10, Color textColor = BLACK, std::string textUp = "");

    void Update();
    void wrongInput() {if(!isWrong) {color.g -= 100; color.b -= 100; isWrong = true;}}
    
    void DrawTextUp();
    void DrawLine();
    void Draw();
};