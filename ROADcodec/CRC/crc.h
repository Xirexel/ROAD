#ifndef CRC_H
#define CRC_H

#include "platformdependencies.h"


namespace CRCSupport
{

    using namespace PlatformDependencies;

    class CRC
    {

    public:

        static ROADByte CRC8(ROADPtrByte aData, ROADUInt32 aLength);

        static ROADUInt16 CRC16(ROADPtrByte aData, ROADUInt32 aLength);

        static ROADUInt32 CRC32(ROADPtrByte aData, ROADUInt32 aLength);

    private:

        CRC() = delete;

        CRC(const CRC&) = delete;

        CRC& operator=(const CRC&) = delete;




    };

}

#endif // CRC_H
