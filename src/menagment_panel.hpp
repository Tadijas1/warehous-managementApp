#pragma once
#include <vector>

#include "produkt.hpp"
#include "button_text.hpp"

class Game;

class Menagment_panel
{
    
    Game* gameptr;

    int fromThereShow;
    std::vector<Produkt> produkts;

    Button_text confirm;

    public:
    Menagment_panel(Game* gameptr) 
    :confirm(300, 50, LIME, true, {0, 485}, 30, BLACK, "CONFIRM ALL") { AddProdukts(gameptr); fromThereShow = 0; this -> gameptr = gameptr; }

    void AddProdukts(Game* gameptr); // for tests
    void SortProdukts();

    void Input();
    void Update();
    void Draw();
};