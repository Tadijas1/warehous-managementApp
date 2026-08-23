#pragma once

#include "button_text.hpp"

class Date_and_time
{
    Button_text show_time;
    Button_text date;

    int day;
    int mounth;
    int year;
    int hour;
    int minute;
    int second;

    public:
    Date_and_time();

    void Update();
    void Draw();
};