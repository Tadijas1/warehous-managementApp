#pragma once
#include <raylib.h>

#include <date_and_time.hpp>
#include <button.hpp>
#include <button_texture.hpp>
#include <button_type.hpp>

class Menu
{
    Date_and_time time;

    Button_texture exit;
    Button_type login;
    Button_type password;
    Button_text confirm;
    int isTyping;

    public:
    Menu();

    void Hover(Button* ptr);
    void Input();
    void Update();
    void Draw();
};