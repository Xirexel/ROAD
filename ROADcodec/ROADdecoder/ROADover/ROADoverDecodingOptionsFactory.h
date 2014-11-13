#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADdecoder__ROADover__ROADoverDecodingOptionsFactory_h__
#define __ROADdecoder__ROADover__ROADoverDecodingOptionsFactory_h__

// #include "ROADdecoder/ROADover/IROADoverDecodingOptions.h"

namespace ROADdecoder
{
	namespace ROADover
	{
		class IROADoverDecodingOptions;
		class ROADoverDecodingOptionsFactory;
	}
}

namespace ROADdecoder
{
	namespace ROADover
	{
		class ROADoverDecodingOptionsFactory
		{
            public: static ROADdecoder::ROADover::IROADoverDecodingOptions* getIROADoverDecodingOptions(unsigned char* aData, unsigned int aLength);
		};
	}
}

#endif
