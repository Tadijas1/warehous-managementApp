#pragma once
#include <raylib.h>
#include <vector>

#include "hover.hpp"
#include "topbar.hpp"
#include "new_password.hpp"
#include "profile.hpp"
#include "menu.hpp"
#include "menagment_panel.hpp"

class Game
{
    // Texture valables
    Texture2D background_texture;
    float background_scale;
    
    
    // menu
    Menu menu;
    New_password newPassword;
    
    // menagment panel
    Menagment_panel panel;
    std::vector<Profile> profiles;
    
    public:
    Topbar topbar;
    Profile* loggedInProfile;
    Hover hover;
    int place; //1 - menu, 2 - produkts, 3 - new password
    
    Game();
    
    Profile* Checking_profile(std::string written_login, std::string written_password);
    void AddProfiles(); //tests

    void InputAll();
    void UpdateAll();
    void DrawAll();
};