#include <iostream>
#include "profile.hpp"

Profile::Profile(std::string name, std::string surname, int id, int type_of_profile)
{
    this -> name = name;
    this -> surname = surname;
    this -> id = id;
    this -> type_of_profile = type_of_profile;
    
    std::string text;
    if(type_of_profile == 0) text = "admin";
    else if(type_of_profile == 1) text = "deliverer";
    else if(type_of_profile == 2) text = "seller";
    login = text + "@" + std::to_string(id);
    password = "password";
}

bool Profile::IsMatch(std::string written_login, std::string written_password)
{
    if(login == written_login && password == written_password) return true;
    return false;
}