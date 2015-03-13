#ifndef __ROADcoder__ROADoverCoder__IROADoverEncodingOptions_h__
#define __ROADcoder__ROADoverCoder__IROADoverEncodingOptions_h__

#include <memory>


#include "ROADFormatMode.h"
#include "platformdependencies.h"
#include "ROADRawDataFormat.h"

namespace ROADcoder
{
	namespace ROADoverCoder
    {
        using namespace PlatformDependencies;

        class IROADoverEncodingOptions
        {
            public: virtual ~IROADoverEncodingOptions(){}

            public: virtual ROADByte getROADFormatMode() = 0;

            public: virtual void setAmountOfChannels(ROADUInt16 aAmountOfChannels) = 0;

            public: virtual void setEncryptionFormat(ROADUInt32 aEncryptionFormat) = 0;

            public: virtual void setBitsPerSampleCode(ROADRawDataFormat aBitsPerSampleCode) = 0;

            public: virtual void setOriginalFrequency(ROADUInt32){}

            public: virtual void setSelectedPreListeningChannel(ROADUInt16){}

            public: virtual std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> clone() = 0;
		};
	}
}

#endif
