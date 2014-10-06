#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADdecoder__ROAD__IFractalItemContainer_h__
#define __ROADdecoder__ROAD__IFractalItemContainer_h__

namespace ROADdecoder
{
	namespace ROAD
	{
        class IFractalFirstOrderItem;
		class IFractalAverItem;
        class IFractalFirstOrderItemContainer;
	}
}

namespace ROADdecoder
{
	namespace ROAD
	{
        class IFractalFirstOrderItemContainer
		{

            public: virtual ROADdecoder::ROAD::IFractalFirstOrderItem* getIFractalFirstOrderItem(unsigned int aIndex) = 0;

			public: virtual ROADdecoder::ROAD::IFractalAverItem* getIFractalAverItem(unsigned int aIndex) = 0;

            public: virtual unsigned int getIFractalFirstOrderItemCount() = 0;

			public: virtual unsigned int getIFractalAverItemCount() = 0;

            public: virtual ~IFractalFirstOrderItemContainer(){}
		};
	}
}

#endif
