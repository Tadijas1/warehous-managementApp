#pragma once

#include <raylib.h>
#include "date_and_time.hpp"
#include "button_texture.hpp"

class Game;
class Menagment_panel;

class Topbar
{
    Game* gameptr;
    
    Date_and_time time;
    Button_texture exit;
    
    public:
    Menagment_panel* panelptr;

    Topbar(Game* gameptr);

    void Input();
    void Update();
    void Draw();
};