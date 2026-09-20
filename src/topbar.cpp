#include <iostream>
#include "topbar.hpp"
#include "game.hpp"

Topbar::Topbar(Game *game)
:exit("textures/cross.png", 0.03, 25, 25, RED, false, {1890, 2}) { this->gameptr = gameptr; this -> panelptr = panelptr;}

void Topbar::Input() 
{ 
    gameptr -> hover.HoverButton(&exit);
    if(exit.IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) { panelptr -> SaveingData(); CloseWindow(); }
}

void Topbar::Update() { time.Update(); }

void Topbar::Draw() { DrawRectangle(0, 0, GetScreenWidth(), 30, GRAY); time.Draw(); exit.Draw(); }