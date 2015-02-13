#ifndef __ROADcoder__ROADCoder__DomainPool_h__
#define __ROADcoder__ROADCoder__DomainPool_h__

#include <vector>

#include "platformdependencies.h"


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
		class DomainPool
		{
            private: ROADUInt32 _size;
            private: ROADUInt32 _domainRelativeShift;
            private: ROADUInt32 _rangTopSampleLength;
            public: std::vector<ROADcoder::ROADCoder::Domain*> _domains;

            public: DomainPool(ROADUInt32 aSize, ROADUInt32 aRangTopSampleLength, ROADUInt32 aDomainRelativeShift);

            public: ROADcoder::ROADCoder::Domain* getDomain(ROADUInt32 aIndex);

            public: void populate(PtrROADReal aData);

            public: virtual ~DomainPool();

            public: ROADUInt32 getSize();
		};
	}
}

#endif
