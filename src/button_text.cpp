#include "button_text.hpp"

void Button_text::DrawTextInside()
{
    int textWidth = MeasureText(text.c_str(), textSize);
    
    DrawText(text.c_str(), hitbox.x + (hitbox.width - textWidth)/2, hitbox.y + (hitbox.height - textSize)/2, textSize, WHITE);
    text = "";
}

Button_text::Button_text(float width, float height, Color color, bool doCenter, Vector2 offset, int textsize, std::string text)
:Button(width, height, color, doCenter, offset)
{
    textSize = textsize;
    this -> text = text;
}

void Button_text::Draw()
{
    DrawRectangle(hitbox.x, hitbox.y, hitbox.width, hitbox.height, color);
    DrawTextInside();
}
