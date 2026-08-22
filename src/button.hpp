#pragma once
#include <raylib.h>
#include <vector>

class Button
{
    protected:
    Rectangle hitbox;
    Color color;
    bool IsClicked;
    Vector2 GetCenterPosicion();

    public:
    Button(float width, float height, Color color, bool doCenter, Vector2 offset = {0, 0});
    
    bool IsPressd(Vector2 mousePosicion, bool mousePressed);
    void Draw();
};