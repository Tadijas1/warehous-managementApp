#pragma once
#include <raylib.h>
#include <string>

#include "button_text.hpp"

class Game;

class Produkt
{
    Game* gameptr;

    //Buttons to managment
    Button_text addProdukt;
    Button_text removeProdukt;

    Rectangle rect;

    int id;
    int NOP_size;
    int NOP_width;
    
    Color name_color; 
    int name_width;
    
    public:
    std::string name;
    int numberOfProdukts;
    int price;
    int numberOfPicked;
    
    Produkt(Game* gameptr, std::string name = "produkt", int id = 0, int price = 0, int numberOfProdukts = 0);

    void NewPlace(int place);
    void resetNOP() {numberOfProdukts += numberOfPicked; numberOfPicked = 0;}

    void Input();
    void Update();
    void Draw();
    void TextsDraw();
};