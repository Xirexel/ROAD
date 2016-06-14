#ifndef __ROADcoder__ROADoverCoder__RealDataContainer_h__
#define __ROADcoder__ROADoverCoder__RealDataContainer_h__

#include "memorydefine.h"
#include "IRealDataContainer.h"


namespace ROADcoder
{
	namespace ROADoverCoder
	{
        class RealDataContainer: public ROADcoder::ROADoverCoder::IRealDataContainer
		{
            private: UniqueMassive_ptr<ROADReal> _data;
            private: ROADUInt32 _length;

            public: ROADUInt32 getLength();

            public: PtrROADReal getData();

            public: RealDataContainer(ROADUInt32 aLength);

            public: virtual ~RealDataContainer();
		};
	}
}

#endif
