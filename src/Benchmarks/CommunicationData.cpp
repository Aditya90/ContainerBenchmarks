#include <iostream>
#include <array>

#include "Benchmarks/CommunicationData.h"

void CommunicationData::createDefaultData(void)
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