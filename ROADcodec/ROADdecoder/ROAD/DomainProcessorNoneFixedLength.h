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
		class DomainProcessorNoneFixedLength;
	}
}

namespace ROADdecoder
{
	namespace ROAD
	{
		class DomainProcessorNoneFixedLength
		{
            private: double* _data;

            public: ~DomainProcessorNoneFixedLength();

			public: DomainProcessorNoneFixedLength(unsigned int aMaxLength);

			public: double* process(double* aData, unsigned int aLength, bool aInversDirection, unsigned int aDomainOffset);

			private: void backFlip(unsigned int aLength);
		};
	}
}

#endif
