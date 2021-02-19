#include "server.h"

int main()
{
    struct sockaddr_in address;
    address.sin_port = PORT;
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

    int new_socket = accept(sockfd, (sockaddr *)(&address), (socklen_t *)&address_length);
    if(new_socket < 0)
    {
        std::cout << "Unable to accept new connection" << std::endl;
        exit(EXIT_FAILURE);
    }

    return 0;
}
