#include <raylib.h>
#include <string>
#include <ctime>
#include "date_and_time.hpp"

Date_and_time::Date_and_time()
:show_time(130, 25, GRAY , true, {0, -524}, 20), date(130, 25, GRAY, false, {15, 3}, 20, DARKBLUE, "")
{
}

void Date_and_time::Update()
{
    time_t t = time(0);
    tm* now = localtime(&t);
    
    //Geting time values
    hour = now -> tm_hour;
    hour = now -> tm_hour;
    minute = now -> tm_min;
    second = now -> tm_sec;
    
    //Import it to show_time class
    show_time.text += std::to_string(hour);
    show_time.text += " : ";
    show_time.text += std::to_string(minute);
    show_time.text += " : ";
    show_time.text += std::to_string(second);
    
    //Geting time values
    day = now -> tm_mday;
    mounth = now -> tm_mon;
    year = now -> tm_year;
    
    //Import it to date class
    date.text += std::to_string(day);
    date.text += " : ";
    date.text += std::to_string(mounth + 1);
    date.text += " : ";
    date.text += std::to_string(year + 1900);
}

void Date_and_time::Draw()
{
    show_time.Draw();
    show_time.text = "";
    date.Draw();
    date.text = "";
}
