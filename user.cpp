#include "user.h"

User::User(std::string name): name(name){}

void User::set_age(int age)
{
    age = age;
}

void User::set_country(std::string country)
{
    country = country;
}

std::string User::to_string()
{
    return "name="+name+",age="+std::to_string(age)+",country="+country;
}
