// export module SocketServer;
#include <cstring>
#include <string>
#include <unordered_map>
#include <sys/socket.h>
#include <netdb.h>

#include "Socket/SocketServer.h"

// The tcp server should support
// 1. Set Socket Options
// 2. Binding socket to a port
// 3. Listening to connection requests over a port for the socket
// 4. Accepting connection requests
// 5. Sending/receiving datas over a socket
// export class SocketServer;
// export class SOCKET_TYPES;
// export class SocketClient;

bool SocketServer::createListener(std::string address, int port, SOCKET_TYPES sockType)
{
    m_serverAddr = std::move(address);
    m_port = port;
    m_sockType = sockType;

    return true;
}

SocketClient::SocketClient(std::string address, std::string port, SOCKET_TYPES sockType)
{
    m_serverAddr = std::move(address);
    m_port = port;
    m_sockType = sockType;
}

void SocketClient::getInfo()
{
    struct addrinfo hints;
    memset(&hints, 0, sizeof hints);                          // make sure the struct is empty
    hints.ai_family = AF_UNSPEC;                              // don't care IPv4 or IPv6
    hints.ai_socktype = socketTypeToSocketInt.at(m_sockType); // TCP stream sockets
    // hints.ai_flags = AI_PASSIVE;     // fill in my IP for me

    struct addrinfo *serverInfo;
    int status = getaddrinfo(m_serverAddr.c_str(), // e.g. "www.example.com" or IP
                             m_port.c_str(),       // e.g. "http" or port number
                             &hints,
                             &serverInfo);

    if (status != 0)
    {
        fprintf(stderr, "getaddrinfo error: %s \n", gai_strerror(status));
        exit(1);
    }

    // Read data

    freeaddrinfo(serverInfo);
}

// The tcp client should support
// 1. Creating a socket
// 2. Connecting to a server
// 3. Sending messages to/receiving from server
