#pragma once
#include <vector>

#include "produkt.hpp"

class Menagment_panel
{
    int fromThereShow;
    std::vector<Produkt> produkts;

    public:
    Menagment_panel() {AddProdukts(); fromThereShow = 0;};

    void AddProdukts(); // for tests
    void SortProdukts();

    void Input();
    void Draw();
};