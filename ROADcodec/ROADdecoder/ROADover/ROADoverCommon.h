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


        template<ROADUInt8 DecodedSampleTypeCode>
        struct DecodedSampleTypeCodeToDecodedSampleType;

        template<>
        struct DecodedSampleTypeCodeToDecodedSampleType<ROADdecoder::ROADover::ROADRawDataFormat::D64>
        {
            public: typedef double DecodedSampleType;
        };

        template<>
        struct DecodedSampleTypeCodeToDecodedSampleType<ROADdecoder::ROADover::ROADRawDataFormat::S32>
        {
            public: typedef int DecodedSampleType;
        };
    }
}

#endif // ROADOVERCOMMON_H
