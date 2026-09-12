#include "produkt.hpp"

Produkt::Produkt(std::string name, int id, int price, int numberOfProdukts)
:addProdukt(50, 50, LIME, false, {1880, rect.y + 50}, 20, BLACK, "+"),
removeProdukt(50, 50, RED, false, {1880, rect.y + 50}, 20, BLACK, "-")
{
    this -> name = name;
    this -> name[0] = std::toupper(name[0]);
    this -> id = id;
    this -> price = price;
    this -> numberOfProdukts = numberOfProdukts;
}

void Produkt::NewPlace(int place)
{
    rect = Rectangle{0, 100.0f * place - 69, GetScreenWidth() * 1.0f, 100};
}

void Produkt::Draw()
{
    DrawRectangle(rect.x, rect.y - 1, GetScreenWidth(), rect.height - 2, Color{70, 70, 70, 255});
    DrawText(name.c_str(), rect.x + 10, rect.y + (rect.height - 20)/2, 20, WHITE);
}
