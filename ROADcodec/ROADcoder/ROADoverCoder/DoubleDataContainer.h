#ifndef __ROADcoder__ROADoverCoder__DoubleDataContainer_h__
#define __ROADcoder__ROADoverCoder__DoubleDataContainer_h__

#include "IDoubleDataContainer.h"


namespace ROADcoder
{
	namespace ROADoverCoder
	{
		class DoubleDataContainer: public ROADcoder::ROADoverCoder::IDoubleDataContainer
		{
            private: UniqueMassive_ptr<ROADReal> _data;
            private: ROADUInt32 _length;

            public: ROADUInt32 getLength();

            public: PtrROADReal getData();

            public: DoubleDataContainer(ROADUInt32 aLength);

            public: virtual ~DoubleDataContainer();
		};
	}
}

#endif
