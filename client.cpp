#include "server.h"
#include <arpa/inet.h>
#include <cstdlib>
#include <netinet/in.h>

int main()
{
    int received;
    std::string msg = "Hello from client";
    char buffer[1024] = {0};
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        std::cout << "Unable to create socket" << std::endl;
        exit(EXIT_FAILURE);
    }
    if(inet_pton(AF_INET, "127.0.0.1", &address.sin_addr) <=0)
    {
        std::cout << "Invalid address" << std::endl;
        exit(EXIT_FAILURE);
    }

    if(connect(sockfd, (struct sockaddr*)&address, sizeof(address)) < 0)
    {
        std::cout << "Connection failed" << std::endl;
        exit(EXIT_FAILURE);
    }

    send(sockfd, msg.c_str(), msg.length(), 0);
    std::cout << "Message sent" << std::endl;
    received = read(sockfd, buffer, 1024);
    std::cout << "Message received: " << std::endl;
    printf("%s\n", buffer);
    return 0;
}
