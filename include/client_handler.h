#pragma once

#include "routing_table_resource.h"
#include <sys/socket.h>
#include <netinet/in.h>

class ClientHandler
{
private:
    sockaddr_in m_serverAddress;
    int m_serverSd;
    RoutingTableResource m_resource;

    void HandleRequest(int connectionSd);
public:
    ClientHandler(sockaddr_in serverAddress);
    ~ClientHandler();
};