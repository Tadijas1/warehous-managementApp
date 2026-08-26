#include "button_type.hpp"

Button_type::Button_type(float width, float height, Color color, bool doCenter, Vector2 offset, int textsize, Color textColor, std::string textUp)
:Button_text(width, height, color, doCenter, offset, textsize, textColor, "")
{
    this -> textUp = textUp;
}

void Button_type::Update()
{
    int key = GetCharPressed();

    while(key > 0)
    {
        if(key >= 32 && key <= 126) text += (char)key;
        key = GetCharPressed();
    }

    //Backspace
    if(IsKeyPressed(KEY_BACKSPACE) && !text.empty()) text.pop_back();

    //Counting text width
    textWidth = MeasureText(text.c_str(), textSize);

    //If text is too big
    if(textWidth > hitbox.width - 10) { text.pop_back(); textWidth = MeasureText(text.c_str(), textSize); }
}

void Button_type::DrawTextUp()
{
    DrawText(textUp.c_str(), hitbox.x, hitbox.y - 35, 20, {228, 228, 228, 255});
}

void Button_type::DrawLine()
{
    DrawRectangle(hitbox.x + 15 + textWidth, hitbox.y + 10, 3, hitbox.height - 20, BLACK);
}

void Button_type::Draw()
{
    DrawRectangle(hitbox.x - 5, hitbox.y - 5, hitbox.width + 10, hitbox.height + 10, PURPLE); // purple arownd rectangle
    DrawRectangle(hitbox.x, hitbox.y, hitbox.width, hitbox.height, color); //place to type
    DrawText(text.c_str(), hitbox.x + 10, hitbox.y + 15, textSize, textColor); //text
}
