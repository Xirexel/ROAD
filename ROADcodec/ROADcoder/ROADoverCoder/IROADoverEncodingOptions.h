#ifndef __ROADcoder__ROADoverCoder__IROADoverEncodingOptions_h__
#define __ROADcoder__ROADoverCoder__IROADoverEncodingOptions_h__

#include <memory>


#include "ROADFormatMode.h"

namespace ROADcoder
{
	namespace ROADoverCoder
	{
		class IROADoverEncodingOptions
		{

            public: virtual ~IROADoverEncodingOptions(){}

            public: virtual unsigned int getROADFormatMode() = 0;

            public: virtual void setAmountOfChannels(unsigned int aAmountOfChannels) = 0;

            public: virtual void setEncryptionFormat(unsigned int aEncryptionFormat) = 0;

            public: virtual void setBitsPerSample(unsigned int aBitsPerSample) = 0;

            public: virtual std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> clone() = 0;
		};
	}
}

#endif
