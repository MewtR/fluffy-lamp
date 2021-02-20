#include "server.h"
#include "protocol.h"
#include "user.h"

int main()
{
    std::map<boost::uuids::uuid, User> users;
    struct sockaddr_in address;
    address.sin_port = htons(PORT);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    int address_length = sizeof(address);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == 0)
    {
        std::cout << "Unable to create socket" << std::endl;
        exit(EXIT_FAILURE);
    }

    if ((bind(sockfd, (struct sockaddr*)(&address), address_length) < 0))
    {
        std::cout << "Unable to bind" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    if (listen(sockfd, 8) < 0) // Maximum connections is 8
    {
        std::cout << "Unable to listen" << std::endl;
        exit(EXIT_FAILURE);
    }

    while(true)
    {
    int new_socket = accept(sockfd, (sockaddr *)(&address), (socklen_t *)&address_length);
    if(new_socket < 0)
    {
        std::cout << "Unable to accept new connection" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::thread([new_socket, &users]() mutable {
    // needs to be in a thread
    while(true)
    {
        int received;
        char buffer[1024] = {0};
        received = read(new_socket, buffer, 1024);
        if (received <= 0) break;
        std::string copy(buffer);
        std::memset(buffer, 0, sizeof(buffer));
        std::string msg = handle_request(copy, users);
        send(new_socket, msg.c_str(), msg.length(), 0);
        if(msg == "DONE") break;
    } }).detach();
    }
    return 0;
}
