#include <iostream>
#include "game.hpp"
#include "menagment_panel.hpp"
#include "produkt.hpp"
#include "new_produkt.hpp"

bool New_produkt::IsEmpty()
{
    for(auto& element : typing_places) {
        if(element.text.empty()) return true;
    }
    return false;
}

New_produkt::New_produkt(Game *gameptr, Menagment_panel *panelptr)
: confirm(300, 50, LIME, true, {0, 360}, 30, BLACK, "CONFIRM")
{
    typing_places.push_back(Button_type{600, 75, WHITE, true, {0, -240}, 50, BLACK, "name:"});
    typing_places.push_back(Button_type{600, 75, WHITE, true, {0, -45}, 50, BLACK, "how many:", true});
    typing_places.push_back(Button_type{600, 75, WHITE, true, {0, 160}, 50, BLACK, "price:", true});

    isTyping = 0;

    this -> gameptr = gameptr;
    this -> panelptr = panelptr;
}

void New_produkt::Input()
{
    // Hovering buttons
    gameptr -> hover.HoverButton(&confirm);
    for(auto& button : typing_places) gameptr -> hover.HoverButton(&button);

    //Unmakeing buttons red afer wrong loginning
    for(auto& element : typing_places) if(isTyping != 0) {element.UnWrongInput();}

    // Checking which place is now typing
    for(int i = 0; i < typing_places.size(); i++)   if(typing_places[i].IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) isTyping = i+1;

    // TAB
    if(IsKeyPressed(KEY_TAB) && IsKeyDown(KEY_LEFT_SHIFT) && isTyping > 1) isTyping--;
    else if(IsKeyPressed(KEY_TAB) && !IsKeyDown(KEY_LEFT_SHIFT) && isTyping < typing_places.size()) isTyping++; 

    //confirm button
    if((confirm.IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) || (IsKeyPressed(KEY_ENTER))) && !IsEmpty()) {
        panelptr -> AddProdukt(typing_places[0].text, stoi(typing_places[1].text), stoi(typing_places[2].text));

        //Setting everything to prevouse setting
        for(auto& element : typing_places) element.text = "";
        for(auto& element : typing_places) if(isTyping != 0) {element.UnWrongInput();}

        isTyping = 0;
        gameptr -> place = 2;
    } else if((confirm.IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) || (IsKeyPressed(KEY_ENTER))) && IsEmpty()) {
        // Makeing red typing_buttons
        for(auto& element : typing_places) element.wrongInput();
        isTyping = 0;
    }
}

void New_produkt::Update()
{
    for(int i = 0; i < typing_places.size(); i++) if(isTyping == i+1) typing_places[i].Update();
}

void New_produkt::Draw()
{
    confirm.Draw();

    for(int i = 0; i < typing_places.size(); i++) {typing_places[i].Draw(); if(i+1 == isTyping) typing_places[i].DrawLine();}
}
