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
    //hover buttons
    hover.HoverButton(&typingPlace);
    hover.HoverButton(&confirm);

    //Unmakeing button red afer wrong loginning
    if(typingPlace.isWrong && IsTyping) typingPlace.UnWrongInput();

    //Mouse input
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if(typingPlace.IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) IsTyping = true;
        else IsTyping = 0;
    }

    //TAB button
    if(IsKeyPressed(KEY_TAB)) {IsTyping = true;}


    //Confirm button
    if(confirm.IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) || (IsKeyPressed(KEY_ENTER))) {
        if(typingPlace.text == "password" or typingPlace.text.empty()) {
            typingPlace.wrongInput();
            IsTyping = false;
        } else {
            profileptr = gameptr -> loggedInProfile;
            profileptr -> password = typingPlace.text;
            gameptr -> place = 1;
        }
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
