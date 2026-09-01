#include <iostream>

#include "profile.hpp"
#include "game.hpp"
#include "new_password.hpp"


New_password::New_password(Game* gameptr)
:typingPlace(600, 75, WHITE, true, {0, -120}, 50, BLACK, "new password:"), confirm(300, 50, LIME, true, {0, 120}, 30, BLACK, "CONFIRM")
{
    IsTyping = false;
    this -> gameptr = gameptr;
}
void New_password::Input()
{
    hover.HoverButton(&typingPlace);
    hover.HoverButton(&confirm);

    //Mouse input
    if(typingPlace.IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) IsTyping = true;

    if((confirm.IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) || (IsKeyPressed(KEY_ENTER) && IsTyping)) && !typingPlace.text.empty() && typingPlace.text != "password") {
        profileptr = gameptr -> loggedInProfile;
        profileptr -> password = typingPlace.text;
        gameptr -> place = 2;
    }
}

void New_password::Update()
{
    typingPlace.Update();
}

void New_password::Draw()
{
    typingPlace.Draw();
    if(IsTyping) typingPlace.DrawLine();

    confirm.Draw();
}
