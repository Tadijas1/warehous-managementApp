#include <fstream>
#include <iostream>

#include "game.hpp"

void Game::ReadingData()
{
    std::ifstream plik("appFiles/profiles.txt");

    if(!plik.is_open()) return;

    std::string line;
    int i = 0;

    std::string name, surname, password;
    int id, type_of_profile;

    while(std::getline(plik, line))
    {
        if(i%5 == 0) name = line;
        if(i%5 == 1) surname = line;
        if(i%5 == 2) id = std::stoi(line);
        if(i%5 == 3) type_of_profile = std::stoi(line);
        if(i%5 == 4) {
            password = line;
            Profile p(name, surname, id, type_of_profile, password);
            profiles.push_back(p);
        }

        i++;
    }

    plik.close();
}

void Game::SaveingData()
{
    std::ofstream plik("appFiles/profiles.txt");

    for(auto& profile : profiles)
    {
        plik << profile.name<<"\n";
        plik << profile.surname<<"\n";
        plik << profile.id<<"\n";
        plik << profile.type_of_profile<<"\n";
        plik << profile.password<<"\n";
    }

    plik.close();
}

Game::Game()
: menu(this), newPassword(this), panel(this), topbar(this)
{
    // Backgroung texture load
    background_texture = LoadTexture("textures/background.png");
    background_scale = static_cast<float>(GetScreenWidth()) / background_texture.width;

    place = 1;

    ReadingData();
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
    topbar.Input();

    if(place == 1) menu.Input();
    else if(place == 2) panel.Input();
    else if(place == 3) newPassword.Input();
}

void Game::UpdateAll()
{
    topbar.Update();

    if(place == 1) menu.Update();
    else if(place == 2) panel.Update();
    else if(place == 3) newPassword.Update();
}

void Game::DrawAll()
{
    topbar.Draw();

    //Background texture drawing
    if(place != 2) DrawTextureEx(background_texture, (Vector2){0, 30}, 0.0f, background_scale, WHITE);

    if(place == 1) menu.Draw();
    else if(place == 2) {panel.Draw();}
    else if(place == 3) newPassword.Draw();
}
