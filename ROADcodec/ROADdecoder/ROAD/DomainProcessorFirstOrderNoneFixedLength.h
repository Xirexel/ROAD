#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADdecoder__ROAD__DomainProcessorNoneFixedLength_h__
#define __ROADdecoder__ROAD__DomainProcessorNoneFixedLength_h__

namespace ROADdecoder
{
	namespace ROAD
	{
        class DomainProcessorFirstOrderNoneFixedLength;
	}
}

namespace ROADdecoder
{
	namespace ROAD
	{
        class DomainProcessorFirstOrderNoneFixedLength
		{
            private: double* _data;

            public: ~DomainProcessorFirstOrderNoneFixedLength();

            public: DomainProcessorFirstOrderNoneFixedLength(unsigned int aMaxLength);

			public: double* process(double* aData, unsigned int aLength, bool aInversDirection, unsigned int aDomainOffset);

			private: void backFlip(unsigned int aLength);
		};
	}
}

#endif
