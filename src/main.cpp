#include "request_handler.h"

#define PORT 8080

int main() {
    //setup a socket and connection tools
    sockaddr_in serverAddress;
    memset((char*)&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddress.sin_port = htons(PORT);

    RequestHandler requestHandler(serverAddress);
    requestHandler.HandleLoop();

    return 0;
}
