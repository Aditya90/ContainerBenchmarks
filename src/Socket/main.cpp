#include "Socket/SocketServer.h"

#include <memory>

int main()
{
    auto newSocClient = std::make_unique<SocketClient>("localhost", "5566", SOCKET_TYPES::DGRAM);
    auto newSocServer = std::make_unique<SocketServer>();

    newSocClient->getInfo();

    return 1;
}