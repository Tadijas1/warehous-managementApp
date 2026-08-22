#pragma once
#include <raylib.h>
#include <vector>

class Button
{
    bool haveText;
    int textSize;
    void DrawTextInside(const char* text, int textSize);
    
    protected:
    Rectangle hitbox;
    bool IsClicked;
    Vector2 GetCenterPosicion();

    public:
    Button(float width, float height, bool doCenter, Vector2 offset = {0, 0}, bool haveText = false,  int textsize = 10);
    
    bool IsPressd(Vector2 mousePosicion, bool mousePressed);
    void Draw();
};