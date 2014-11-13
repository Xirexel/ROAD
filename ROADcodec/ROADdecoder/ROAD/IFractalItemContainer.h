#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADdecoder__ROAD__IFractalItemContainer_h__
#define __ROADdecoder__ROAD__IFractalItemContainer_h__

// #include "ROADdecoder/ROAD/IFractalItem.h"
// #include "ROADdecoder/ROAD/IFractalAverItem.h"

namespace ROADdecoder
{
	namespace ROAD
	{
		class IFractalItem;
		class IFractalAverItem;
		class IFractalItemContainer;
	}
}

namespace ROADdecoder
{
	namespace ROAD
	{
		class IFractalItemContainer
		{

            public: virtual ROADdecoder::ROAD::IFractalItem* getIFractalItem(unsigned int aIndex) = 0;

			public: virtual ROADdecoder::ROAD::IFractalAverItem* getIFractalAverItem(unsigned int aIndex) = 0;

			public: virtual unsigned int getIFractalItemCount() = 0;

			public: virtual unsigned int getIFractalAverItemCount() = 0;
		};
	}
}

#endif
