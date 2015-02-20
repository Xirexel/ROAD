#ifndef __ROADdecoder__ROADover__DoubleDataContainer_h__
#define __ROADdecoder__ROADover__DoubleDataContainer_h__

#include "IDoubleDataContainer.h"

#include "platformdependencies.h"

namespace ROADdecoder
{
	namespace ROADover
	{
    using namespace PlatformDependencies;

		class DoubleDataContainer: public ROADdecoder::ROADover::IDoubleDataContainer
		{
            private: PtrROADReal _data;
            private: ROADUInt32 _count;

            public: PtrROADReal getData();

            public: ROADUInt32 getCount();

            public: void setCount(ROADUInt32 aValue);

            public: ~DoubleDataContainer();

            public: DoubleDataContainer(ROADUInt32 aLength);
		};
	}
}

#endif
