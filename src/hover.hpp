#pragma once
#include <raylib.h>

#include "button.hpp"

class Hover
{
    public:
    void HoverButton(Button* ptr)
    {
        if(ptr -> IsHover(GetMousePosition())) { if(!ptr ->IsHovered) {ptr -> ChangeColor(-30);} ptr -> IsHovered = true;}
        else if(ptr -> IsHovered == true) { ptr -> ChangeColor(30); ptr -> IsHovered = false; }
    }
};  