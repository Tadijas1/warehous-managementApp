#include "button.hpp"

#include <iostream>
#include <raymath.h>

Button::Button(float width, float height, Color color, bool doCenter, Vector2 offset)
{    
    //Get rectangle
    if(doCenter) hitbox = Rectangle{Vector2Add(GetCenterPosicion(), offset).x - width/2, Vector2Add(GetCenterPosicion(), offset).y - height/2, width, height};
    else hitbox = Rectangle{offset.x, offset.y, width, height};

    //Other things
    IsClicked = false;
    this -> color = color;
}

bool Button::IsPressd(Vector2 mousePosicion, bool mousePressed)
{
    if(CheckCollisionPointRec(mousePosicion, hitbox) && mousePressed) return true;
    return false;
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
