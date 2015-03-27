#ifndef __ROADdecoder__ROADover__IROADoverDecodingOptions_h__
#define __ROADdecoder__ROADover__IROADoverDecodingOptions_h__

#include "ROADFormatMode.h"
#include "platformdependencies.h"


namespace ROADdecoder
{
	namespace ROADover
	{
    using namespace PlatformDependencies;
		class IROADoverDecodingOptions
		{

            public: virtual ROADUInt32 getROADFormatMode() = 0;

            public: virtual ~IROADoverDecodingOptions(){}

            public: virtual ROADUInt32 getOriginalSamplesPerRang() = 0;

            public: virtual void setFrequencyScale(ROADUInt32 aValue) = 0;

            public: virtual ROADUInt32 getEncryptionFormat() = 0;


		};
	}
}

#endif
