#pragma once
#include <raylib.h>
#include <string>

#include "button_text.hpp"

class Produkt
{
    //Buttons to managment
    Button_text addProdukt;
    Button_text removeProdukt;

    Rectangle rect;

    int id;
    int price;
    int numberOfProdukts;
    
    public:
    std::string name;
    
    Produkt(std::string name = "produkt", int id = 0, int price = 0, int numberOfProdukts = 0);

    void NewPlace(int place);

    void Draw();
};