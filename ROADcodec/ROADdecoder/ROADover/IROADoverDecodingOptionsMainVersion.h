#ifndef ROADOVERDECODINGOPTIONSMAINVERSION_H
#define ROADOVERDECODINGOPTIONSMAINVERSION_H


#include "IROADoverDecodingOptions.h"
#include "ROADRawDataFormat.h"



namespace ROADdecoder
{
    namespace ROADover
    {
        class IROADoverDecodingOptionsMainVersion: public ROADdecoder::ROADover::IROADoverDecodingOptions
        {
            public: virtual ROADUInt32 getOrder() = 0;

            public: virtual ROADUInt32 getMaxSuperFrameLength() = 0;

            public: virtual ROADUInt32 getFrameSampleLength() = 0;

            public: virtual ROADUInt32 getMaxFrameRangLength() = 0;

            public: virtual ROADUInt32 getMinSamplesPerRang() = 0;

            public: virtual ROADRawDataFormat getBitsPerSampleCode(){return UNKNOWNDataFormat;}

            public: virtual ~IROADoverDecodingOptionsMainVersion(){}
        };
    }
}

#endif // ROADOVERDECODINGOPTIONSMAINVERSION_H
