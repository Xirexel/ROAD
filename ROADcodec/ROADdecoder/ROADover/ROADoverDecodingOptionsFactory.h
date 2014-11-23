#include <string>
#include <vector>
#include <exception>
#include "memory"
using namespace std;

#ifndef __ROADdecoder__ROADover__ROADoverDecodingOptionsFactory_h__
#define __ROADdecoder__ROADover__ROADoverDecodingOptionsFactory_h__

// #include "ROADdecoder/ROADover/IROADoverDecodingOptions.h"

#include "roadover_global.h"

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
        class ROADOVERSHARED_EXPORT ROADoverDecodingOptionsFactory
		{
            public: static void getIROADoverDecodingOptions(unsigned char* aData, unsigned int aLength);
		};
	}
}

#endif