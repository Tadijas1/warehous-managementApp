#include <iostream>

#include "game.hpp"

Game::Game()
:menu(this)
{
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

void Game::InputAll()
{
    menu.Input();
}

void Game::UpdateAll()
{
    menu.Update();
}

void Game::DrawAll()
{
    menu.Draw();
}
