#pragma once
#include <raylib.h>
#include <vector>

#include "profile.hpp"
#include "menu.hpp"

class Game
{
    Menu menu;
    std::vector<Profile> profiles;
    // Kategoris
    // Warehous

    public:
    Game();

    Profile* Checking_profile(std::string written_login, std::string written_password);
    void AddProfile() {profiles.push_back(Profile("Kamil", "Bielicki", 1, 0));}

    void InputAll();
    void UpdateAll();
    void DrawAll();
};