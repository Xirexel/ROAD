#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADdecoder__ROAD__IFractalItem_h__
#define __ROADdecoder__ROAD__IFractalItem_h__

namespace ROADdecoder
{
	namespace ROAD
	{
        class IFractalFirstOrderItem;
	}
}

namespace ROADdecoder
{
	namespace ROAD
	{
        class IFractalFirstOrderItem
		{

			public: virtual double getAver() = 0;

			public: virtual unsigned int getLength() = 0;

			public: virtual bool isInversDirection() = 0;

            public: virtual unsigned int getDomainOffset() = 0;

			public: virtual double getScale() = 0;

			public: virtual unsigned int getPosition() = 0;

            public: virtual ~IFractalFirstOrderItem(){}
		};
	}
}

#endif
