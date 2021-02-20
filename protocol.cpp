#include "protocol.h"

std::string handle_request(std::string request)
{
    boost::uuids::random_generator gen;
    boost::uuids::uuid u = gen();
    std::cout << "My uuid " << u << std::endl;
    boost::trim(request);
    std::cout << "Request received " << request << std::endl;
    auto space = request.find(" ");
    if( space == std::string::npos)
    {
        // No space found single word
        if(request == "LIST")
        {
            // List 
            return "Need to list users here";
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
            return "Need to register users here: "+ arg;
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
