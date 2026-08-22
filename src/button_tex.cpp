#include "button_tex.hpp"

Button_tex::Button_tex(const char *imagePath, float scale, float width, float height, bool doCenter, Vector2 offset)
:Button(width, height, doCenter, offset)
{
    Image image = LoadImage(imagePath);
    
    int newWidth = static_cast<int>(image.width * scale);
    int newHeight = static_cast<int>(image.height * scale);
    
    ImageResize(&image, newWidth, newHeight);
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
}

Button_tex::~Button_tex()
{
    UnloadTexture(texture);
}

void Button_tex::Draw()
{
    DrawRectangle(hitbox.x, hitbox.y, hitbox.width, hitbox.height, RED);
    DrawTexture(texture, hitbox.x + (hitbox.width - texture.width)/2, hitbox.y + (hitbox.height - texture.height)/2, WHITE);
}
