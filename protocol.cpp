#include "protocol.h"

void handle_request(std::string request)
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
            std::cout << "Need to list users here" << std::endl;
        }else if(request == "DONE")
        {
            // Close connection
            std::cout << "Need to close the connection here" << std::endl;
        }else{
            std::cout << "Unknown command" << std::endl;
        }
    }else{
        std::string command = request.substr(0,space);
        std::string arg = request.substr(space+1);
        std::cout << "Command is: "<< command << std::endl;
        if(command == "REGISTER")
        {
            std::cout << "Need to register users here: "<< arg << std::endl;
        }else if(command == "AGE")
        {
            std::cout << "Need to set age here: "<< arg << std::endl;
        }else if(command == "COUNTRY")
        {
            std::cout << "Need to set country here: "<< arg << std::endl;
        }else if(command == "UNREGISTER")
        {
            std::cout << "Need unregister user with id: "<< arg << std::endl;
        }
    }
}
