#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __IUCharDataContainer_h__
#define __IUCharDataContainer_h__

namespace ROADEncoding
{
	class IUCharDataContainer;
}

namespace ROADEncoding
{
	class IUCharDataContainer
	{

		public: virtual unsigned char* getData() = 0;

		public: virtual unsigned int getCount() = 0;

        public: virtual ~IUCharDataContainer(){}
	};
}

#endif
