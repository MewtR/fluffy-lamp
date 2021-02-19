#ifndef USER_H
#define USER_H
#include <string>

class User{
    public:
        std::string to_string();
        User(std::string);
        void set_age(int);
        void set_country(std::string);
    private:
        std::string name;
        int age;
        std::string country;
};

#endif /* USER_H */

