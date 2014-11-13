#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADdecoder__ROADover__DoubleDataContainer_h__
#define __ROADdecoder__ROADover__DoubleDataContainer_h__

 #include "IDoubleDataContainer.h"

namespace ROADdecoder
{
	namespace ROADover
	{
		class IDoubleDataContainer;
		class DoubleDataContainer;
	}
}

namespace ROADdecoder
{
	namespace ROADover
	{
		class DoubleDataContainer: public ROADdecoder::ROADover::IDoubleDataContainer
		{
            private: double *_data;
            private: unsigned int _count;

			public: double* getData();

			public: unsigned int getCount();

			public: void setCount(unsigned int aValue);

            public: ~DoubleDataContainer();

            public: DoubleDataContainer(unsigned int aLength);
		};
	}
}

#endif
