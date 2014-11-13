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

			public: virtual ROADdecoder::ROADover::ROADFormatMode getROADFormatMode() = 0;

            public: virtual ~IROADoverDecodingOptions(){}
		};
	}
}

#endif
