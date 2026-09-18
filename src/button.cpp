#include "button.hpp"

#include <iostream>
#include <raymath.h>

Button::Button(float width, float height, Color color, bool doCenter, Vector2 offset)
{    
    //Get rectangle
    if(doCenter) hitbox = Rectangle{Vector2Add(GetCenterPosicion(), offset).x - width/2, Vector2Add(GetCenterPosicion(), offset).y - height/2, width, height};
    else hitbox = Rectangle{offset.x, offset.y, width, height};

    //Other things
    IsHovered= false;
    this -> color = color;
}

bool Button::IsPressd(Vector2 mousePosicion, bool mousePressed)
{
    if(CheckCollisionPointRec(mousePosicion, hitbox) && mousePressed) return true;
    return false;
}

bool Button::IsHover(Vector2 mousePosicion)
{
    if(CheckCollisionPointRec(mousePosicion, hitbox)) return true;
    return false;
}

void Button::ChangeColor(int value)
{
    //Changign color, but color valure always will by 0-255
    
    if(color.r + value >= 0) {
        if(color.r + value <= 255) color.r += value;
        else color.r = 255;
    }
    else color.r = 0;

    if(color.g + value >= 0) {
        if(color.g + value <= 255) color.g += value;
        else color.g = 255;
    }
    else color.g = 0;

    if(color.b + value >= 0) {
        if(color.b + value <= 255) color.b += value;
        else color.b = 255;
    }
    else color.b = 0;
}

void Button::ChangePosicion(int new_x, int new_y)
{
    hitbox.x = new_x;
    hitbox.y = new_y;
}

Vector2 Button::GetCenterPosicion()
{
    float withCenter = (GetScreenWidth() - hitbox.width)/2;
    float heightCenter = (GetScreenHeight() - hitbox.height)/2;

    return {withCenter, heightCenter};
}

void Button::Draw()
{
    DrawRectangle(hitbox.x, hitbox.y, hitbox.width, hitbox.height, color);
}
