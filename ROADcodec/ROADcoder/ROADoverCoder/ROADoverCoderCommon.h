#ifndef ROADOVERCODERCOMMON_H
#define ROADOVERCODERCOMMON_H

#include "ROADRawDataFormat.h"
#include "platformdependencies.h"


namespace ROADcoder
{
    namespace ROADoverCoder
    {
    using namespace PlatformDependencies;

        template<ROADUInt8 DecodedSampleTypeCode>
        struct SampleTypeCodeToSampleType;

        template<>
        struct SampleTypeCodeToSampleType<ROADcoder::ROADoverCoder::ROADRawDataFormat::D64>
        {
            public: typedef ROADReal DecodedSampleType;
        };

        template<>
        struct SampleTypeCodeToSampleType<ROADcoder::ROADoverCoder::ROADRawDataFormat::S32>
        {
            public: typedef ROADInt32 DecodedSampleType;
        };

        template<>
        struct SampleTypeCodeToSampleType<ROADcoder::ROADoverCoder::ROADRawDataFormat::S16>
        {
            public: typedef ROADInt16 DecodedSampleType;
        };


    }
}

#endif // ROADOVERCODERCOMMON_H
