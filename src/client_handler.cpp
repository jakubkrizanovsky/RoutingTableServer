#include "client_handler.h"
#include <iostream>
#include <unistd.h>


ClientHandler::ClientHandler(sockaddr_in serverAddress) : m_serverAddress{serverAddress}
{
    //create socket
    m_serverSd = socket(AF_INET, SOCK_STREAM, 0);
    if(m_serverSd < 0)
    {
        std::cerr << "Error establishing the server socket" << std::endl;
        exit(0);
    }

    //bind the socket to its local address
    int bindStatus = bind(m_serverSd, (struct sockaddr*) &m_serverAddress, sizeof(m_serverAddress));
    if(bindStatus < 0)
    {
        std::cerr << "Error binding socket to local address" << std::endl;
        exit(0);
    }

    listen(m_serverSd, 5);

    sockaddr_in connectionAddress;
    socklen_t connectionAddressSize = sizeof(connectionAddress);

    while(true) {
        int connectionSd = accept(m_serverSd, (sockaddr *)&connectionAddress, &connectionAddressSize);
        if(connectionSd < 0) {
            std::cerr << "Error accepting request from client!" << std::endl;
            continue;
        }

        HandleRequest(connectionSd);   
    }
}

void ClientHandler::HandleRequest(int connectionSd)
{
    char buffer[1000];
    recv(connectionSd, (char*)&buffer, sizeof(buffer), 0);

    std::string message = "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: ";
    std::string response = m_resource.GetResponse();
    message.append(std::to_string(response.length()));
    message.append("\n\n");
    message.append(response);

    std::cout << message;
    send(connectionSd, message.c_str(), message.length(), 0);

    close(connectionSd);
}

ClientHandler::~ClientHandler()
{
    close(m_serverSd);
}
