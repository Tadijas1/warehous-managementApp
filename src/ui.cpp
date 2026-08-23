#include <string>
#include <iostream>
#include "ui.hpp"

Ui::Ui()
:exit("textures/cross.png", 0.03, 25, 25, RED ,false, {1890, 2})
{
}

void Ui::Update()
{
    time.Update();
}

void Ui::Draw()
{
    //Time drawing
    time.Draw();

    //Button drawing
    exit.Draw();
}
