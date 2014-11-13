#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADdecoder__ROADover__IDoubleDataContainer_h__
#define __ROADdecoder__ROADover__IDoubleDataContainer_h__

namespace ROADdecoder
{
	namespace ROADover
	{
		class IDoubleDataContainer;
	}
}

namespace ROADdecoder
{
	namespace ROADover
	{
		class IDoubleDataContainer
		{

			public: virtual double* getData() = 0;

			public: virtual unsigned int getCount() = 0;

			public: virtual void setCount(unsigned int aValue) = 0;

            public: virtual ~IDoubleDataContainer(){}
		};
	}
}

#endif
