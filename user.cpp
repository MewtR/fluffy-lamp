#include "user.h"

User::User(std::string name): name(name), age(0){}

void User::set_age(int a)
{
    age = a;
}

void User::set_country(std::string c)
{
    country = c;
}

std::string User::to_string() const
{
    std::string output;
    output+="name="+name;
    if(age) output+=",age="+std::to_string(age);
    if(!country.empty()) output+=",country="+country;
    return output;
}
