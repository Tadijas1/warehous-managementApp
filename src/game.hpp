#pragma once
#include <raylib.h>
#include <vector>

#include "hover.hpp"
#include "topbar.hpp"
#include "new_password.hpp"
#include "profile.hpp"
#include "menu.hpp"

class Game
{
    Topbar topbar;
    
    Menu menu;
    New_password newPassword;
    // Kategoris
    // Warehous
    std::vector<Profile> profiles;
    
    
    public:
    Profile* loggedInProfile;
    Hover hover;
    int place; //0 - menu, 1 - katalogs, 2 - produkts, 3 - new password

    Game();

    Profile* Checking_profile(std::string written_login, std::string written_password);
    void AddProfiles(); //tests

    void InputAll();
    void UpdateAll();
    void DrawAll();
};