#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADdecoder__ROAD__IFractalAverItem_h__
#define __ROADdecoder__ROAD__IFractalAverItem_h__

namespace ROADdecoder
{
	namespace ROAD
	{
		class IFractalAverItem;
	}
}

namespace ROADdecoder
{
	namespace ROAD
	{
		class IFractalAverItem
		{

			public: virtual double getAver() = 0;

			public: virtual unsigned int getLength() = 0;
		};
	}
}

#endif
