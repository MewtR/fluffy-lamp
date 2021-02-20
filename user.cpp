#include "user.h"

User::User(std::string name): name(name), age(0){}

void User::set_age(int age)
{
    age = age;
}

void User::set_country(std::string country)
{
    country = country;
}

std::string User::to_string() const
{
    std::string output;
    output+="name="+name;
    if(age) output+=",age="+std::to_string(age);
    if(!country.empty()) output+=",country="+country;
    return output;
}
