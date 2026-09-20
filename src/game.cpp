#include "game.hpp"

Game::Game()
    : menu(this), newPassword(this), panel(this), topbar(this)
{
    // Backgroung texture load
    background_texture = LoadTexture("textures/background.png");
    background_scale = static_cast<float>(GetScreenWidth()) / background_texture.width;

    place = 1;
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
