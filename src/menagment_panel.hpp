#pragma once
#include <vector>

#include "produkt.hpp"
#include "button_text.hpp"
#include "new_produkt.hpp"

class Game;
class Profile;

class Menagment_panel
{
    Game* gameptr;
    Profile* currentProfileptr;

    
    //reading produkts data form file
    void ReadingData();

    

    //Produkts valables
    int fromThereShow;
    int whichProduktMarked;
    std::vector<Produkt> produkts;
    
    Button_text addProdukt_button;

    Button_text confirm;
    
    public:
    //saving produkts data to file
    void SaveingData();

    Menagment_panel(Game* gameptr);
    
    void AddProdukt(std::string name, int howMany, int price);
    void AddLoggedInProfile(Profile* profileptr) {currentProfileptr = profileptr;}
    void SortProdukts();

    void Input();
    void Update();
    void Draw();
    void markedDraw();
};