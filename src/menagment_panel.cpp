#include <iostream>
#include <cctype>
#include "menagment_panel.hpp"

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

void Menagment_panel::AddProdukts()
{
    // In 11 objets, boards are out of screen
    produkts.push_back(Produkt{"peceb", 0, 1000, 5});
    produkts.push_back(Produkt{"butelka", 1, 3, 300});
    produkts.push_back(Produkt{"ananas", 2, 10, 1150});
    SortProdukts();
}

void Menagment_panel::Input()
{
    //arrow up and down
    if(IsKeyPressed(KEY_DOWN) && produkts.size() - fromThereShow > 10) fromThereShow++;
    if(IsKeyPressed(KEY_UP) && fromThereShow > 0) fromThereShow--;

    for(int i = 0; i < produkts.size(); i++) {produkts[i].NewPlace(i + 1 - fromThereShow);}
}

void Menagment_panel::Draw()
{
    for(auto it = produkts.begin() + fromThereShow; it != produkts.end(); it++) {it -> Draw();}
}
