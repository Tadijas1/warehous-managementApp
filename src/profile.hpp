#pragma once
#include <raylib.h>
#include <string>

class Profile
{
    std::string name;
    std::string surname;
    int id;
    int type_of_profile; //0 admin, 1 deliverer, 2 seller
    std::string login;
    
    
    public:
    std::string password;

    Profile(std::string name = "", std::string surname = "", int id = 0, int type_of_profile = 0);
    
    bool IsMatch(std::string written_login, std::string written_password);
};