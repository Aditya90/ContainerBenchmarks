#ifndef _CODE_TO_TEST_H_
#define _CODE_TO_TEST_H_

#include <array>

struct Header
{
    uint32_t serialNumber{0x00000000};
    uint32_t macAddress{0x00000000};
};

struct DataPayload
{
    std::array<uint8_t, 16> dataPayload{0};
};

struct Footer
{
    uint32_t crc{0x00000000};
};

struct NetworkMessage
{
    Header hdr{};
    DataPayload data{};
    Footer footer{};
};

class CommunicationData
{
private:
    NetworkMessage mMsg{};

public:
    CommunicationData() = default;
    CommunicationData(const CommunicationData &) = default;
    CommunicationData(CommunicationData &&) = default;
    CommunicationData &operator=(const CommunicationData &) = default;
    CommunicationData &operator=(CommunicationData &&) = default;

    void createDefaultData()
    {
        mMsg.hdr.macAddress = 0x01020304;
        mMsg.hdr.serialNumber = 0x01020304;

        mMsg.data.dataPayload = {1,
                                 2,
                                 3,
                                 4,
                                 5,
                                 6,
                                 7,
                                 8,
                                 9,
                                 10,
                                 11,
                                 12,
                                 13,
                                 14,
                                 15,
                                 16};
    }
};

#endif