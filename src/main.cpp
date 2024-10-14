#include "routing_table_resource.h"
#include "client_handler.h"
#include <iostream>
#include <string>

#define PORT 8080

int main() {
    //setup a socket and connection tools
    sockaddr_in serverAddress;
    bzero((char*)&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddress.sin_port = htons(PORT);

    ClientHandler clientHandler(serverAddress);

    RoutingTableResource resource;

    std::string response = resource.GetResponse();
    std::cout << response << std::endl;

    return 0;
}
