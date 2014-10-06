#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __IFrameFractalItemCollection_h__
#define __IFrameFractalItemCollection_h__

// #include "IFractalItem.h"

namespace FractalEncoding
{
	class IFractalItem;
	class IFrameFractalItemCollection;
}

namespace FractalEncoding
{
	class IFrameFractalItemCollection
	{

		public: virtual FractalEncoding::IFractalItem* getNextIFractalItem() = 0;

        public: virtual ~IFrameFractalItemCollection(){}
	};
}

#endif
