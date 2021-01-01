#pragma once

#include <string>
#include <unordered_map>
#include <sys/socket.h>

// The tcp server should support
// 1. Set Socket Options
// 2. Binding socket to a port
// 3. Listening to connection requests over a port for the socket
// 4. Accepting connection requests
// 5. Sending/receiving datas over a socket

enum class SOCKET_TYPES : uint8_t
{
    STREAM, // tcp
    DGRAM   // udp
};

static const std::unordered_map<SOCKET_TYPES, int> socketTypeToSocketInt = {
    {SOCKET_TYPES::STREAM, SOCK_STREAM},
    {SOCKET_TYPES::DGRAM, SOCK_DGRAM},
};

class SocketServer
{
public:
    bool createListener(std::string address, int port, SOCKET_TYPES sockType);

private:
    int m_sockFd{0};
    std::string m_serverAddr{""};
    int m_port{0};
    SOCKET_TYPES m_sockType{SOCKET_TYPES::DGRAM};
};

class SocketClient
{
public:
    SocketClient(std::string address, std::string port, SOCKET_TYPES sockType = SOCKET_TYPES::STREAM);

    void getInfo();

private:
    int m_sockFd{0};
    std::string m_serverAddr{""};
    std::string m_port{0};
    SOCKET_TYPES m_sockType{SOCKET_TYPES::DGRAM};
};

// The tcp client should support
// 1. Creating a socket
// 2. Connecting to a server
// 3. Sending messages to/receiving from server
