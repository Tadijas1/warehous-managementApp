#pragma once
#include <raylib.h>
#include <vector>
#include "button_type.hpp"
#include "button_text.hpp"

class Game;
class Menagment_panel;

class New_produkt
{   
    Game* gameptr;
    Menagment_panel* panelptr;

    std::vector<Button_type> typing_places;

    // Button_type name_typingPlace;    STILL DON'T WHICH METOD IS BETER :(
    // Button_type howMany_typingPlace;
    // Button_type price_typingPlace;

    Button_text confirm;

    int isTyping;
    
    bool IsEmpty();

    public:
    New_produkt(Game* gameptr, Menagment_panel* panelptr);

    void Input();
    void Update();
    void Draw();
};