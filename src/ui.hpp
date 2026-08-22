#pragma once
#include <raylib.h>
#include <ctime>

#include <button.hpp>
#include <button_texture.hpp>
#include <button_text.hpp>

class Ui
{
    Button_texture exit;
    Button_text show_time;
    // Button date;
    int day;
    int mount;
    int year;
    int hour;
    int minute;
    int second;

    public:
    Ui();

    void Update();
    void Draw();
};