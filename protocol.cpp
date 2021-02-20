#include "protocol.h"

std::string handle_request(std::string request, std::map<boost::uuids::uuid, User> &users)
{
    boost::trim(request);
    std::cout << "Request received " << request << std::endl;
    auto space = request.find(" ");
    if( space == std::string::npos)
    {
        // No space found single word
        if(request == "LIST")
        {
            // List 
            return list(users);
        }else if(request == "DONE")
        {
            // Close connection
            return "Need to close the connection here";
        }else{
            return "Unknown command";
        }
    }else{
        std::string command = request.substr(0,space);
        std::string arg = request.substr(space+1);
        if(command == "REGISTER")
        {
            return register_user(arg, users);
        }else if(command == "AGE")
        {
            return "Need to set age here: "+ arg;
        }else if(command == "COUNTRY")
        {
            return "Need to set country here: "+ arg;
        }else if(command == "UNREGISTER")
        {
            return "Need unregister user with id: "+ arg;
        }else{
            return "Unknown command";
        }
    }
}


std::string register_user(std::string name, std::map<boost::uuids::uuid, User> &users)
{
    boost::uuids::random_generator gen;
    boost::uuids::uuid u = gen();
    users.insert({u, User(name)});
    std::stringstream ss;
    ss << u;
    return ss.str();
}

std::string list(std::map<boost::uuids::uuid, User> &users)
{
    if (users.empty()) return "No registered users yet.";
    std::string output;
    for(const auto& user: users)
    {
        std::stringstream ss;
        ss << user.first;
        output+=ss.str()+":"+ user.second.to_string()+"\n";
    }
    return output;
}
