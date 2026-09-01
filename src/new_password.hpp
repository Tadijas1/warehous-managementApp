#pragma once

#include "button_type.hpp"
#include "button_text.hpp"
#include "hover.hpp"

class Profile;
class Game;

class New_password
{
    Game* gameptr;
    Profile* profileptr;

    Hover hover;

    Button_type typingPlace;
    Button_text confirm;

    bool IsTyping;

    public:
    New_password(Game* gameptr);

    void Input();
    void Update();
    void Draw();
};