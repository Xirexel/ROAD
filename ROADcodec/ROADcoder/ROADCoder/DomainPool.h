#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADcoder__ROADCoder__DomainPool_h__
#define __ROADcoder__ROADCoder__DomainPool_h__

// #include "ROADcoder/ROADCoder/Domain.h"
// #include "ROADcoder/ROADCoder/ROADFractalAnalyzerNoneFixedRangLength.h"

namespace ROADcoder
{
	namespace ROADCoder
	{
		class Domain;
		class ROADFractalAnalyzerNoneFixedRangLength;
		class DomainPool;
	}
}

namespace ROADcoder
{
	namespace ROADCoder
	{
		class DomainPool
		{
			private: unsigned int _size;
			private: unsigned int _domainRelativeShift;
            private: unsigned int _rangTopSampleLength;
            public: std::vector<ROADcoder::ROADCoder::Domain*> _domains;

            public: DomainPool(unsigned int aSize, unsigned int aRangTopSampleLength, unsigned int aDomainRelativeShift);

			public: ROADcoder::ROADCoder::Domain* getDomain(unsigned int aIndex);

			public: void populate(double* aData);

            public: virtual ~DomainPool();

			public: unsigned int getSize();
		};
	}
}

#endif
