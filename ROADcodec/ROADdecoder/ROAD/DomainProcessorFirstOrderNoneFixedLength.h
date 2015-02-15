#ifndef __ROADdecoder__ROAD__DomainProcessorNoneFixedLength_h__
#define __ROADdecoder__ROAD__DomainProcessorNoneFixedLength_h__

#include "platformdependencies.h"

namespace ROADdecoder
{
	namespace ROAD
	{
    using namespace PlatformDependencies;
        class DomainProcessorFirstOrderNoneFixedLength
		{
            private: PtrROADReal _data;

            public: ~DomainProcessorFirstOrderNoneFixedLength();

            public: DomainProcessorFirstOrderNoneFixedLength(ROADUInt32 aMaxLength);

            public: PtrROADReal process(PtrROADReal aData, ROADUInt32 aLength, ROADBool aInversDirection, ROADUInt32 aDomainOffset);

            private: void backFlip(ROADUInt32 aLength);
		};
	}
}

#endif
