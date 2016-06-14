#ifndef __ROADcoder__ROADCoder__DomainPool_h__
#define __ROADcoder__ROADCoder__DomainPool_h__

#include <vector>

#include "memorydefine.h"


namespace ROADcoder
{
	namespace ROADCoder
	{
        class Domain;
	}
}

namespace ROADcoder
{
	namespace ROADCoder
	{
    using namespace PlatformDependencies;

        // collection of one level domains
		class DomainPool
        {
            private: ROADSize _size;
            private: ROADUInt32 _domainRelativeShift;
            private: ROADUInt32 _rangTopSampleLength;
            private: std::vector<ROADcoder::ROADCoder::Domain*> _domains;

            public: DomainPool(ROADSize aSize,
                               ROADUInt32 aRangTopSampleLength,
                               ROADUInt32 aDomainRelativeShift);

            public: ROADcoder::ROADCoder::Domain* getDomain(ROADUInt32 aIndex);

            public: void populate(PtrROADReal aData);

            public: virtual ~DomainPool();

            public: ROADSize getSize();
		};
	}
}

#endif
