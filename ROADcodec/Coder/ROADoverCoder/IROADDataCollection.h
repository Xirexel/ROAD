#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __IROADDataCollection_h__
#define __IROADDataCollection_h__

namespace ROADoverEncoding
{
	class IROADDataCollection;
}

namespace ROADoverEncoding
{
	class IROADDataCollection
	{

		public: virtual unsigned int getCount() = 0;
	};
}

#endif
