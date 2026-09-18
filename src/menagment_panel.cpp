#include <iostream>
#include <cctype>

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

void Menagment_panel::AddProdukts(Game* gameptr)
{
    // In 11 objets, boards are out of screen
    produkts.push_back(Produkt{gameptr, "peceb", 0, 1000, 5});
    produkts.push_back(Produkt{gameptr, "butelka", 1, 3, 300});
    produkts.push_back(Produkt{gameptr, "ananas", 2, 10, 1150});
    SortProdukts();
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

    //confirm button
    if(confirm.IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
        for(auto& produkt : produkts) { produkt.resetNOP(); }
    }
}

void Menagment_panel::Update()
{
    for(auto& produkt : produkts) { produkt.Update(); }
}

void Menagment_panel::Draw()
{
    for(auto it = produkts.begin() + fromThereShow; it != produkts.end(); it++) {it -> Draw();}
    confirm.Draw();
}
