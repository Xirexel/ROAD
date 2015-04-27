#ifndef ROADDATAFORMAT_H
#define ROADDATAFORMAT_H

#include "platformdependencies.h"

namespace ROADdecoder
{
    namespace ROAD
    {
        enum ROADDataFormat: PlatformDependencies::ROADUInt8
        {
            Int32 = 0x20,
            Double = 0x44
//            U8 = 0x08, S8 = 0xF8, U12 = 0xF4, S12 = 0x0C, U16 = 0xF0, S16 = 0x10, U20 = 0xEC, S20 = 0x14,
//            U24 = 0xE8, S24 = 0x18, U32 = 0xE0, S32 = 0x20, U64 = 0xC0, S64 = 0x40,
//            F32 = 0x46, D64 = 0x44, UNKNOWNDataFormat = 0x00
            /* U8 = 0x08 - unsigned integer 8 bits,
             * S8 = 0xF8 - signed integer 8 bits,
             * U12 = 0xF4 - unsigned integer 12 bits,
             * S12 = 0x0C - signed integer 12 bits,
             * U16 = 0xF0 - unsigned integer 16 bits,
             * S16 = 0x10 - signed integer 16 bits,
             * U20 = 0xEC - unsigned integer 20 bits,
             * S20 = 0x14 - signed integer 20 bits,
             * U24 = 0xE8 - unsigned integer 24 bits,
             * S24 = 0x18 - signed integer 24 bits,
             * U32 = 0xE0 - unsigned integer 32 bits,
             * S32 = 0x20 - signed integer 32 bits,
             * U64 = 0xC0 - unsigned integer 64 bits,
             * S64 = 0x40 - signed integer 64 bits,
             * F32 = 0x46 - float 32 bits,
             * D64 = 0x44 - double 64 bits,
             * UNKNOWN = 0x00 - is not covered*/

        };
    }
}

#endif // ROADRAWDATAFORMAT_H
