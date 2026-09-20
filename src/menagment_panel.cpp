#include <iostream>
#include <cctype>
#include <fstream>
#include <string>

#include "menagment_panel.hpp"
#include "game.hpp"

bool SwapProdukts(Produkt a, Produkt b, int letter)
{
    if(letter >= a.name.size() || letter >= b.name.size()) return false;

    char letter1 = *(a.name.begin() + letter);
    char letter2 = *(b.name.begin() + letter);

    if(letter2 < letter1) return true;
    else if(letter1 == letter2) if(SwapProdukts(a, b, letter + 1)) {return true;}
    return false;
}

void Menagment_panel::SortProdukts()
{
    for (int i = 0; i < produkts.size() - 1; i++) for (int j = 0; j < produkts.size() - 1; j++)
    {
        if(SwapProdukts(produkts[j], produkts[j + 1], 0)) {
            Produkt bufor = produkts[j];
            produkts[j] = produkts[j + 1];
            produkts[j + 1] = bufor;
        }
    }
    for(int i = 0; i < produkts.size(); i++) {produkts[i].NewPlace(i + 1);}
}

Menagment_panel::Menagment_panel(Game* gameptr)
:confirm(300, 50, LIME, true, {0, 485}, 30, BLACK, "CONFIRM ALL")
{
    this -> gameptr = gameptr;

    //giving pointer to topbar
    gameptr -> topbar.panelptr = this;

    fromThereShow = 0;
    whichProduktMarked = 1;
    ReadingData();
}

void Menagment_panel::ReadingData()
{
    std::ifstream plik("appFiles/produkts.txt");

    if(!plik.is_open()) return;


    std::string line;
    std::string name;
    int price, howMany;
    int i = 0;

    while(std::getline(plik, line))
    {
        if(i%3 == 0) name = line;
        if(i%3 == 1) howMany = std::stoi(line);
        if(i%3 == 2) {
            price = std::stoi(line);
            Produkt p(gameptr, name, i/3, price, howMany);
            produkts.push_back(p);
        }

        i++;
    }
    plik.close();

    SortProdukts();
}

void Menagment_panel::SaveingData()
{
    std::ofstream plik("appFiles/produkts.txt");

    for(auto& produkt : produkts)
    {
        plik << produkt.name<<"\n";
        plik << produkt.numberOfProdukts<<"\n";
        plik << produkt.price<<"\n";
    }

    plik.close();
}

void Menagment_panel::Input()
{
    //hover
    gameptr -> hover.HoverButton(&confirm);

    // produkts input
    for(auto& produkt : produkts) { produkt.Input(); }

    //arrow up and down
    if(IsKeyPressed(KEY_DOWN) && produkts.size() - fromThereShow > 10) fromThereShow++;
    if(IsKeyPressed(KEY_UP) && fromThereShow > 0) fromThereShow--;

    for(int i = 0; i < produkts.size(); i++) {produkts[i].NewPlace(i + 1 - fromThereShow);}

    //confirm button or enter
    if(confirm.IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) or IsKeyPressed(KEY_ENTER)) {
        for(auto& produkt : produkts) { produkt.resetNOP(); }
    }

    //moving between produkts with TAB
    if(((IsKeyPressed(KEY_TAB) && IsKeyDown(KEY_LEFT_SHIFT)) or IsKeyPressed(KEY_UP)) && whichProduktMarked > 1) whichProduktMarked--;
    else if((IsKeyPressed(KEY_TAB) && !IsKeyDown(KEY_LEFT_SHIFT)) or IsKeyPressed(KEY_DOWN)) if(whichProduktMarked < produkts.size()) whichProduktMarked++;

    //changing numbersOfPicked
    if(IsKeyPressed(KEY_LEFT)) produkts[whichProduktMarked - 1].numberOfPicked--;
    if(IsKeyPressed(KEY_RIGHT)) produkts[whichProduktMarked - 1].numberOfPicked++;
}

void Menagment_panel::Update()
{
    for(auto& produkt : produkts) { produkt.Update(); }
}
void Menagment_panel::markedDraw()
{
    DrawRectangle(0, 100.0f * whichProduktMarked - 70, GetScreenWidth() * 1.0f, 102, YELLOW);
}

void Menagment_panel::Draw()
{
    markedDraw();
    for(auto it = produkts.begin() + fromThereShow; it != produkts.end(); it++) {it -> Draw();}
    confirm.Draw();

}