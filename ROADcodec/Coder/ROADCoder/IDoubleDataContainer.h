#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __IDoubleDataContainer_h__
#define __IDoubleDataContainer_h__

namespace ROADEncoding
{
	class IDoubleDataContainer;
}

namespace ROADEncoding
{
	class IDoubleDataContainer
	{

		public: virtual double* getData() = 0;

		public: virtual unsigned int getCount() = 0;

        public: virtual ~IDoubleDataContainer(){}
	};
}

#endif
