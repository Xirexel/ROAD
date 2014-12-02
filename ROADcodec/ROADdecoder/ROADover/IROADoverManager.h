#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADdecoder__ROADover__IROADoverManager_h__
#define __ROADdecoder__ROADover__IROADoverManager_h__

#include "Result.h"

namespace ROADdecoder
{
	namespace ROADover
	{
		// enum Result;
		class IROADoverManager;
	}
}

namespace ROADdecoder
{
	namespace ROADover
	{
		class IROADoverManager
		{

			public: virtual ROADdecoder::ROADover::Result decode() = 0;

            public: virtual ~IROADoverManager(){}
		};
	}
}

#endif
