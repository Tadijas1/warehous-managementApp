#include <string>
#include <iostream>

#include "menu.hpp"
#include "game.hpp"

Menu::Menu(Game* gameptr)
:exit("textures/cross.png", 0.03, 25, 25, RED ,false, {1890, 2}), login(600, 75, WHITE, true, {0, -120}, 50, BLACK, "Login:"), password(600, 75, WHITE, true, {0, 120}, 50, BLACK,"Password:"), confirm(300, 50, LIME, true, {0, 300}, 30, BLACK, "CONFIRM")
{
    this -> gameptr = gameptr;
    isTyping = 0;
}

void Menu::Hover(Button* ptr)
{
    if(ptr -> IsHover(GetMousePosition())) { if(!ptr ->IsHovered) {ptr -> ChangeColor(-30);} ptr -> IsHovered = true;}
    else if(ptr -> IsHovered == true) { ptr -> ChangeColor(30); ptr -> IsHovered = false; }
}

void Menu::Input()
{
    //Hover buttons
    Hover(&exit);
    Hover(&login);
    Hover(&password);
    Hover(&confirm);


    //Mouse input
    if(exit.IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) CloseWindow();

    if(confirm.IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) || (IsKeyPressed(KEY_ENTER) && isTyping == 2)) {
        //click on "confirm" or enter
        if(gameptr -> Checking_profile(login.text, password.text) != nullptr) gameptr -> Checking_profile(login.text, password.text) -> print();
        else std::cout<<"nie udało się zalogować"<<std::endl;

        //czyszczenie pól textowych
        login.text = "";
        password.text = "";
        isTyping = 0;
    }

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        //login and password buttons
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
    confirm.Draw();

    //login buttons drawing
    login.Draw(); login.DrawTextUp();
    password.Draw(); password.DrawTextUp();
    if(isTyping == 1) login.DrawLine();
    if(isTyping == 2) password.DrawLine();
}
