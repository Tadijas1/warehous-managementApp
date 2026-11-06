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
:confirm(300, 50, LIME, true, {0, 485}, 30, BLACK, "CONFIRM ALL"), addProdukt_button(0, 0, BLACK, true)
{
    this -> gameptr = gameptr;

    //giving pointer to topbar
    gameptr -> topbar.panelptr = this;

    fromThereShow = 0;
    whichProduktMarked = 1;
    ReadingData();
    if(produkts.size() < 10) addProdukt_button = Button_text{GetScreenWidth() - 4.0f, 98, DARKGREEN, false, {2, 100.f * (produkts.size()+1) - 68}, 100, BLACK, "+"};
    else addProdukt_button = Button_text{GetScreenWidth() - 4.0f, 98, DARKGREEN, false, {2, 100.f * 11 - 68}, 100, BLACK, "+"};
}

void Menagment_panel::AddProdukt(std::string name, int howMany, int price)
{
    Produkt p{gameptr, name, produkts.size(), price, howMany};
    produkts.push_back(p);

    // New posicion of addProdukt_button
    if(produkts.size() < 10) addProdukt_button.ChangePosicion(2, 100.f * (produkts.size()+1) - 68);
    else addProdukt_button.ChangePosicion(2, 100.f * 11 - 68);
    SortProdukts();
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

    //moving between produkts with TAB and arrows
    if(((IsKeyPressed(KEY_TAB) && IsKeyDown(KEY_LEFT_SHIFT)) || IsKeyPressed(KEY_K) || IsKeyPressed(KEY_UP)) && fromThereShow + whichProduktMarked != 1) whichProduktMarked--;
    else if(((IsKeyPressed(KEY_TAB) && !IsKeyDown(KEY_LEFT_SHIFT)) || IsKeyPressed(KEY_J) || IsKeyPressed(KEY_DOWN)) && fromThereShow + whichProduktMarked < produkts.size()) whichProduktMarked++;
    else if(((IsKeyPressed(KEY_TAB) && !IsKeyDown(KEY_LEFT_SHIFT)) || IsKeyPressed(KEY_J) || IsKeyPressed(KEY_DOWN)) && fromThereShow + whichProduktMarked == produkts.size() && currentProfileptr -> type_of_profile == 0) {
        whichProduktMarked++;
        addProdukt_button.ChangePosicion(2, 100.f * 10 - 68);
    }

    //arrow up and down
    if(whichProduktMarked > 10) {fromThereShow++; whichProduktMarked--;}
    if(whichProduktMarked < 1) {fromThereShow--; whichProduktMarked++;}
    for(int i = 0; i < produkts.size(); i++) {produkts[i].NewPlace(i + 1 - fromThereShow);}
    
    //changing numbersOfPicked
    if(currentProfileptr -> type_of_profile == 0) {
        if(whichProduktMarked+fromThereShow <= produkts.size()) {
            if(IsKeyPressed(KEY_LEFT) && produkts[whichProduktMarked+fromThereShow - 1].numberOfProdukts + produkts[whichProduktMarked+fromThereShow - 1].numberOfPicked > 0) produkts[whichProduktMarked+fromThereShow - 1].numberOfPicked--;
            if(IsKeyPressed(KEY_RIGHT)) produkts[whichProduktMarked+fromThereShow - 1].numberOfPicked++;
        }
    }
    else if(currentProfileptr -> type_of_profile == 1) {
        if(IsKeyPressed(KEY_LEFT) && produkts[whichProduktMarked+fromThereShow - 1].numberOfPicked > 0) produkts[whichProduktMarked+fromThereShow - 1].numberOfPicked--;    
        if(IsKeyPressed(KEY_RIGHT)) produkts[whichProduktMarked+fromThereShow - 1].numberOfPicked++;
    } else {
        if(IsKeyPressed(KEY_LEFT) && produkts[whichProduktMarked+fromThereShow - 1].numberOfProdukts + produkts[whichProduktMarked+fromThereShow - 1].numberOfPicked > 0) produkts[whichProduktMarked+fromThereShow - 1].numberOfPicked--;
        if(IsKeyPressed(KEY_RIGHT) && produkts[whichProduktMarked+fromThereShow -1].numberOfPicked < 0) produkts[whichProduktMarked+fromThereShow - 1].numberOfPicked++; 
    }

    // What do to if click enter
    if(IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
        //Adding produkts
        if(currentProfileptr -> type_of_profile == 0 && whichProduktMarked+fromThereShow == produkts.size() + 1) {
            addProdukt_button.IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT));
            gameptr -> place = 4;
        }
        //confirm button or enter
        else {
            for(auto& produkt : produkts) { produkt.resetNOP(); }
        }
    }

    if(confirm.IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
        for(auto& produkt : produkts) { produkt.resetNOP(); }
    }

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
    if(currentProfileptr -> type_of_profile == 0) addProdukt_button.Draw();
    for(auto it = produkts.begin() + fromThereShow; it != produkts.end(); it++) {it -> Draw();}
    confirm.Draw();
}