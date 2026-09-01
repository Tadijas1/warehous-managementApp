#pragma once
#include <raylib.h>

#include "button.hpp"
#include "button_type.hpp"

class Game;

class Menu
{
    Game* gameptr;

    Button_type login;
    Button_type password;
    
    Button_text confirm;
    
    int isTyping;

    public:
    Menu(Game* gameptr);

    void Input();
    void Update();
    void Draw();
};