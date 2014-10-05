#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __DomainPool_h__
#define __DomainPool_h__

#include "Domain.h"
// #include "IDomain.h"

namespace ROADEncoding
{
	class Domain;
	class IDomain;
	class DomainPool;
}

namespace ROADEncoding
{
	class DomainPool
	{
		private: unsigned int _size;
		private: unsigned int _domainRelativeShift;
		private: unsigned int _rangeTopSampleLength;
        public: std::vector<ROADEncoding::Domain*> _domains;

		public: DomainPool(unsigned int aSize, unsigned int aRangeTopSampleLength, unsigned int aDomainRelativeShift);

        public: virtual ~DomainPool();

        public: ROADEncoding::IDomain* getIDomain(unsigned int aIndex);

		public: void populate(double* aData);

		public: unsigned int getSize();
	};
}

#endif
