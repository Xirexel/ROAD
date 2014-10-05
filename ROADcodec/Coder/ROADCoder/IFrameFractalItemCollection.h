#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __IFrameFractalItemCollection_h__
#define __IFrameFractalItemCollection_h__

// #include "IFractalItem.h"

namespace ROADEncoding
{
	class IFractalItem;
	class IFrameFractalItemCollection;
}

namespace ROADEncoding
{
	class IFrameFractalItemCollection
	{

        public: virtual ROADEncoding::IFractalItem* getNextIFractalItem() = 0;

        public: virtual ~IFrameFractalItemCollection(){}
	};
}

#endif
