#ifndef __ROADcoder__ROADoverCoder__DoubleDataContainer_h__
#define __ROADcoder__ROADoverCoder__DoubleDataContainer_h__

#include "IDoubleDataContainer.h"

namespace ROADcoder
{
	namespace ROADoverCoder
	{
		class IDoubleDataContainer;
		class DoubleDataContainer;
	}
}

namespace ROADcoder
{
	namespace ROADoverCoder
	{
		class DoubleDataContainer: public ROADcoder::ROADoverCoder::IDoubleDataContainer
		{
			private: double* _data;
			private: unsigned int _length;

            public: unsigned int getLength();

			public: double* getData();

            public: DoubleDataContainer(unsigned int aLength);

            public: virtual ~DoubleDataContainer();
		};
	}
}

#endif
