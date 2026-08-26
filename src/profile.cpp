#include <iostream>
#include "profile.hpp"

Profile::Profile(std::string name, std::string surname, int id, int type_of_profile)
{
    this -> name = name;
    this -> surname = surname;
    this -> id = id;
    this -> type_of_profile = type_of_profile;
    login = name + "@" + std::to_string(id);
    password = "";
}

bool Profile::IsMatch(std::string written_login, std::string written_password)
{
    if(login == written_login && password == written_password) return true;
    return false;
}

void Profile::print()
{
    std::cout<<"name: "<<name<<std::endl;   
    std::cout<<"surname: "<<surname<<std::endl;   
    std::cout<<"id: "<<id<<std::endl;   
    std::cout<<"type_of_profile: "<<type_of_profile<<std::endl;   
}
