#pragma once
#include <raylib.h>
#include <vector>

class Button
{
    protected:
    Rectangle hitbox;

    Color color;
    
    Vector2 GetCenterPosicion();
    
    public:
    bool IsHovered;

    Button(float width, float height, Color color, bool doCenter, Vector2 offset = {0, 0});
    
    bool IsPressd(Vector2 mousePosicion, bool mousePressed);
    bool IsHover(Vector2 mousePosicion);
    void ChangeColor(int value);
    void ChangePosicion(int new_x, int new_y);

    void Draw();
};