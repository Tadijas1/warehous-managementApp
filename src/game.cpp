#include <iostream>

#include "game.hpp"

Game::Game()
:menu(this), newPassword(this), topbar(this)
{
    place = 0;
}

Profile* Game::Checking_profile(std::string written_login, std::string written_password)
{
    for(auto it = profiles.begin(); it != profiles.end();)
    {
        if(it -> IsMatch(written_login, written_password)) return &(*it);
        else it++;
    }
    return nullptr;
}

void Game::AddProfiles()
{
    profiles.push_back(Profile("Kamil", "Bielicki", 0, 0));
    profiles.push_back(Profile("Tomasz", "Kalecki", 1, 1));
    profiles.push_back(Profile("Joanna", "Oczarska", 2, 2));
}

void Game::InputAll()
{
    topbar.Input();

    if(place == 0) menu.Input();
    else if(place == 2) std::cout<<loggedInProfile -> password<<std::endl;
    else if(place == 3) newPassword.Input();
    // else if(place == 1)
}

void Game::UpdateAll()
{
    topbar.Update();

    if(place == 0) menu.Update();
    else if(place == 2) std::cout<<loggedInProfile -> password<<std::endl;
    else if(place == 3) newPassword.Update();
    // else if(place == 1)
}

void Game::DrawAll()
{
    topbar.Draw();

    if(place == 0) menu.Draw();
    else if(place == 2) std::cout<<loggedInProfile -> password<<std::endl;
    else if(place == 3) newPassword.Draw();
    // else if(place == 1)
}
