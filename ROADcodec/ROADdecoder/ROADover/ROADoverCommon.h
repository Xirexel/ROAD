#ifndef ROADOVERCOMMON_H
#define ROADOVERCOMMON_H

#include "platformdependencies.h"
#include "EndianType.h"
#include "ROADRawDataFormat.h"

namespace ROADdecoder
{
    namespace ROADover
    {
        using namespace PlatformDependencies;

        template<typename ROADRawDataSampleType, typename ROADDecodingSampleType>
        class ROADoverManagerFirstOrder;
    }
}

#endif // ROADOVERCOMMON_H
