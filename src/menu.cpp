#include <string>
#include <iostream>

#include "menu.hpp"
#include "game.hpp"

Menu::Menu(Game* gameptr)
:login(600, 75, WHITE, true, {0, -120}, 50, BLACK, "Login:"), password(600, 75, WHITE, true, {0, 120}, 50, BLACK,"Password:"), confirm(300, 50, LIME, true, {0, 300}, 30, BLACK, "CONFIRM")
{
    this -> gameptr = gameptr;
    isTyping = 0;
}

void Menu::Input()
{
    //Hover buttons
    gameptr -> hover.HoverButton(&login);
    gameptr -> hover.HoverButton(&password);
    gameptr -> hover.HoverButton(&confirm);

    //Unmakeing buttons red afer wrong loginning
    if(login.isWrong && isTyping != 0) login.UnWrongInput();
    if(password.isWrong && isTyping != 0) password.UnWrongInput();

    //confirm button or enter
    if(confirm.IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) || (IsKeyPressed(KEY_ENTER))) {

        //some actions with logged profile pointers
        Profile* profileptr = gameptr -> Checking_profile(login.text, password.text);
        if(profileptr != nullptr) {
            gameptr -> loggedInProfile = profileptr;
            gameptr -> AddProfileToPanel(profileptr);
            login.UnWrongInput();
            password.UnWrongInput();

            // Loggining for first time of not
            if(profileptr -> password == "password") gameptr -> place = 3;
            else gameptr -> place = 2;

            //czyszczenie pól textowych
            login.text = "";
            password.text = "";
        } else {
            login.wrongInput();
            password.wrongInput();
        }
        
        isTyping = 0;
    }

    //login and password buttons
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if(login.IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) { isTyping = 1; }
        else if(password.IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) { isTyping = 2; }
        else isTyping = 0;
    }

    //Keyboard
    if(IsKeyPressed(KEY_TAB)) {isTyping++; if(isTyping == 3) isTyping = 1;}
}

void Menu::Update()
{
    if(isTyping == 1) login.Update();
    if(isTyping == 2) password.Update();
}

void Menu::Draw()
{
    confirm.Draw();

    //login buttons drawing
    login.Draw();
    password.Draw();
    if(isTyping == 1) login.DrawLine();
    if(isTyping == 2) password.DrawLine();
}