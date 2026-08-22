#include <string>
#include <iostream>
#include "ui.hpp"

Ui::Ui()
:exit("textures/cross.png", 0.03, 25, 25, RED ,false, {1890, 2}), show_time(130, 25, GRAY , true, {0, -524}, 20)
{
}

void Ui::Update()
{
    time_t t = time(0);
    tm* now = localtime(&t);

    hour = now -> tm_hour;
    minute = now -> tm_min;
    second = now -> tm_sec;

    show_time.text += std::to_string(hour);
    show_time.text += " : ";
    show_time.text += std::to_string(minute);
    show_time.text += " : ";
    show_time.text += std::to_string(second);
}

void Ui::Draw()
{
    //Time drawing
    show_time.Draw();
    // date.Draw();

    //Button drawing
    exit.Draw();
}
