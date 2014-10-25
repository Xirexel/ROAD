#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ICharDataContainer_h__
#define __ICharDataContainer_h__

namespace ROADoverEncoding
{
	class ICharDataContainer;
}

namespace ROADoverEncoding
{
	class ICharDataContainer
	{

		public: virtual char* getData() = 0;

		public: virtual unsigned int getLength() = 0;

        public: virtual ~ICharDataContainer(){}
	};
}

#endif
