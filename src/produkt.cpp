#include "produkt.hpp"
#include "game.hpp"

Produkt::Produkt(Game* gameptr, std::string name, int id, int price, int numberOfProdukts)
:addProdukt(50, 50, LIME, false, {1850, rect.y + (rect.height - 50)/2}, 20, BLACK, "+"),
removeProdukt(50, 50, RED, false, {1720, rect.y + (rect.height - 50)/2}, 20, BLACK, "-")
{
    this -> gameptr = gameptr;
    this -> name = name;
    this -> name[0] = std::toupper(name[0]);
    this -> id = id;
    this -> price = price;
    this -> numberOfProdukts = numberOfProdukts;

    numberOfPicked = 0;
    name_color = BLACK;
    NOP_size = 50;
    NOP_width = 0;
    name_width = MeasureText(name.c_str(), 30);
}

void Produkt::NewPlace(int place)
{
    rect = Rectangle{0, 100.0f * place - 69, GetScreenWidth() * 1.0f, 100};
    addProdukt.ChangePosicion(1850, rect.y + (rect.height - 50)/2);
    removeProdukt.ChangePosicion(1720, rect.y + (rect.height - 50)/2);
}

void Produkt::Input()
{
    //hover buttons
    gameptr -> hover.HoverButton(&addProdukt);
    gameptr -> hover.HoverButton(&removeProdukt);   

    //clicking buttons
    if(addProdukt.IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) numberOfPicked++;
    if(removeProdukt.IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) if(numberOfProdukts + numberOfPicked > 0) numberOfPicked--;
}

void Produkt::Update()
{
    //numbers of picked color
    if(numberOfPicked < 0) name_color = RED;
    else if(numberOfPicked == 0) name_color = BLACK;
    else name_color = GREEN;

    //Numbers of picked size
    NOP_width = MeasureText(std::to_string(numberOfPicked).c_str(), NOP_size);
    while (NOP_width > 130) { NOP_size--; NOP_width = MeasureText(std::to_string(numberOfPicked).c_str(), NOP_size); }
}

void Produkt::Draw()
{
    DrawRectangle(rect.x, rect.y - 1, GetScreenWidth(), rect.height - 2, Color{70, 70, 70, 255});
    addProdukt.Draw();
    removeProdukt.Draw();
    TextsDraw();
}

void Produkt::TextsDraw()
{
    //Draw name
    DrawText(name.c_str(), rect.x + 10, rect.y + (rect.height - 20)/2, 30, WHITE);
    std::string text = "IN STORE: "+std::to_string(numberOfProdukts);

    //Draw number of produkts and price
    DrawText(text.c_str(), rect.x + 30 + name_width, rect.y + (rect.height - 20)/2 - 18, 20, BLACK);
    text = "PRICE: "+std::to_string(price)+"$";
    DrawText(text.c_str(), rect.x + 30 + name_width, rect.y + (rect.height - 20)/2 + 18, 20, BLACK);

    //Drawing number of pick
    DrawText(std::to_string(numberOfPicked).c_str(), 1770 + (80 - NOP_width)/2, rect.y + (rect.height - NOP_size)/2, NOP_size, name_color);
}
