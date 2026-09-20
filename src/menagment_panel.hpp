#pragma once
#include <vector>

#include "produkt.hpp"
#include "button_text.hpp"

class Game;

class Menagment_panel
{
    Game* gameptr;

    //reading data form file
    void ReadingData();
    
    int fromThereShow;
    std::vector<Produkt> produkts;
    
    Button_text confirm;
    
    public:
    //saving data to file
    void SaveingData();

    Menagment_panel(Game* gameptr);
    
    void SortProdukts();

    void Input();
    void Update();
    void Draw();
};