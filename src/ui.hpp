#pragma once
#include <raylib.h>

#include <date_and_time.hpp>
#include <button.hpp>
#include <button_texture.hpp>

class Ui
{
    Button_texture exit;
    Date_and_time time;

    public:
    Ui();

    void Update();
    void Draw();
};