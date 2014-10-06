#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __DomainPool_h__
#define __DomainPool_h__

#include "Domain.h"
// #include "IDomain.h"

namespace FractalEncoding
{
	class Domain;
	class IDomain;
	class DomainPool;
}

namespace FractalEncoding
{
	class DomainPool
	{
		private: unsigned int _size;
		private: unsigned int _domainRelativeShift;
		private: unsigned int _rangeTopSampleLength;
		public: std::vector<FractalEncoding::Domain*> _domains;

		public: DomainPool(unsigned int aSize, unsigned int aRangeTopSampleLength, unsigned int aDomainRelativeShift);

        public: virtual ~DomainPool();

		public: FractalEncoding::IDomain* getIDomain(unsigned int aIndex);

		public: void populate(double* aData);

		public: unsigned int getSize();
	};
}

#endif
