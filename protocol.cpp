#include "protocol.h"

std::mutex users_mutex; // protects users

std::string uuid_to_string(boost::uuids::uuid u)
{
        std::stringstream ss;
        ss << u;
        return ss.str();
}
boost::uuids::uuid string_to_uuid(std::string s)
{
        boost::uuids::uuid result;
        std::stringstream ss;
        ss << s;
        ss >> result;
        return result;
}
std::string handle_request(std::string request, std::map<boost::uuids::uuid, User> &users)
{
    boost::trim(request);
    std::cout << "Request received " << request << std::endl;
    auto space = request.find(" ");
    if( space == std::string::npos)
    {
        // No space found single word
        if(request == "LIST") { return list(users); }
        else if(request == "DONE") { return "DONE"; }
        else{ return "Unknown command";}
    }else{
        std::string command = request.substr(0,space);
        std::string arg = request.substr(space+1);
        if(command == "REGISTER") { return register_user(arg, users); }
        else if(command == "AGE") { return age(arg, users); }
        else if(command == "COUNTRY") { return country(arg, users); }
        else if(command == "UNREGISTER") { return unregister(arg, users); }
        else{ return "Unknown command";}
    }
}


std::string register_user(std::string name, std::map<boost::uuids::uuid, User> &users)
{
    boost::uuids::random_generator gen;
    boost::uuids::uuid u = gen();

    std::lock_guard<std::mutex> lock(users_mutex);
    users.insert({u, User(name)});
    return uuid_to_string(u);
}

std::string list(std::map<boost::uuids::uuid, User> &users)
{
    std::lock_guard<std::mutex> lock(users_mutex);
    if (users.empty()) return "No registered users yet.";
    std::string output;
    for(const auto& user: users)
    {
        std::string uuid = uuid_to_string(user.first);
        output+=uuid+":"+ user.second.to_string()+"\n";
    }
    return output;
}

std::string age(std::string arg, std::map<boost::uuids::uuid, User> &users)
{
    boost::trim(arg);
    auto space = arg.find(" ");
    if( space == std::string::npos) return "Wrong number of arguments";
    std::string u = arg.substr(0,space);
    std::string str_age = arg.substr(space+1); 
    if(str_age.find_first_not_of("0123456789") != std::string::npos) return "Age needs to be a number";

    int age = std::stoi(str_age);
    boost::uuids::uuid uuid = string_to_uuid(u);

    std::lock_guard<std::mutex> lock(users_mutex);
    auto user = users.find(uuid);
    if(user == std::end(users))
    {
        return "No User with such an id";
    }else{
        user->second.set_age(age);
        return user->second.to_string();
    }
}
std::string country(std::string arg, std::map<boost::uuids::uuid, User> &users)
{
    boost::trim(arg);
    auto space = arg.find(" ");
    if( space == std::string::npos) return "Wrong number of arguments";
    std::string u = arg.substr(0,space);
    std::string country = arg.substr(space+1); 
    boost::uuids::uuid uuid = string_to_uuid(u);
    std::lock_guard<std::mutex> lock(users_mutex);
    auto user = users.find(uuid);
    if(user == std::end(users))
    {
        return "No User with such an id";
    }else{
        user->second.set_country(country);
        return user->second.to_string();
    }
}
std::string unregister(std::string arg, std::map<boost::uuids::uuid, User> &users)
{
    boost::trim(arg);
    auto space = arg.find(" ");
    if( space != std::string::npos) return "Wrong number of arguments";
    boost::uuids::uuid uuid = string_to_uuid(arg);

    std::lock_guard<std::mutex> lock(users_mutex);
    auto user = users.find(uuid);
    if(user == std::end(users))
    {
        return "No User with such an id";
    }else{
        users.erase(user);
        return "User remove successfully";
    }
}
