#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADdecoder__ROADover__IROADoverDecodingOptions_h__
#define __ROADdecoder__ROADover__IROADoverDecodingOptions_h__

#include "ROADFormatMode.h"

namespace ROADdecoder
{
	namespace ROADover
	{
		// enum ROADFormatMode;
		class IROADoverDecodingOptions;
	}
}

namespace ROADdecoder
{
	namespace ROADover
	{
		class IROADoverDecodingOptions
		{

            public: virtual unsigned int getROADFormatMode() = 0;

            public: virtual ~IROADoverDecodingOptions(){}

			public: virtual unsigned int getOriginalSamplesPerRang() = 0;

            public: virtual void setSamplesPerRang(unsigned int aValue) = 0;

            public: virtual unsigned int getEncriptionCode() = 0;


		};
	}
}

#endif
