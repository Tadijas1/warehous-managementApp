#include <string>
#include <iostream>
#include "menu.hpp"

Menu::Menu()
:exit("textures/cross.png", 0.03, 25, 25, RED ,false, {1890, 2}), login(600, 75, WHITE, true, {0, -140}, 50, BLACK, "Login:"), password(600, 75, WHITE, true, {0, 140}, 50, BLACK,"Password:")
{
    isTyping = 0;
}

void Menu::Input()
{
    //Mouse
    if(exit.IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) CloseWindow();

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if(login.IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) isTyping = 1;
        else if(password.IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) isTyping = 2;
        else isTyping = 0;
    }

    //Keyboard
    if(IsKeyPressed(KEY_TAB) && isTyping != 0) {isTyping++; if(isTyping == 3) isTyping = 1;}
}

void Menu::Update()
{
    time.Update();
    if(isTyping == 1) login.Update();
    if(isTyping == 2) password.Update();
}

void Menu::Draw()
{
    //Time drawing
    time.Draw();

    //Button drawing
    exit.Draw();

    //login buttons drawing
    login.Draw(); login.DrawTextUp();
    password.Draw(); password.DrawTextUp();
    if(isTyping == 1) login.DrawLine();
    if(isTyping == 2) password.DrawLine();
}
