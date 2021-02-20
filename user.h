#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>

class User{
    public:
        std::string to_string() const;
        User(std::string);
        void set_age(int);
        void set_country(std::string);
    private:
        std::string name;
        int age;
        std::string country;
};

#endif /* USER_H */

