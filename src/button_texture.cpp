#include "button_texture.hpp"

Button_texture::Button_texture(const char *imagePath, float scale, float width, float height, Color color, bool doCenter, Vector2 offset)
:Button(width, height, color, doCenter, offset)
{
    Image image = LoadImage(imagePath);
    
    int newWidth = static_cast<int>(image.width * scale);
    int newHeight = static_cast<int>(image.height * scale);
    
    ImageResize(&image, newWidth, newHeight);
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
}

Button_texture::~Button_texture()
{
    UnloadTexture(texture);
}

void Button_texture::Draw()
{
    DrawRectangle(hitbox.x, hitbox.y, hitbox.width, hitbox.height, color);
    DrawTexture(texture, hitbox.x + (hitbox.width - texture.width)/2 + 1, hitbox.y + (hitbox.height - texture.height)/2, WHITE);
}
