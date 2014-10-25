#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __IROADDataCollection_h__
#define __IROADDataCollection_h__

namespace ROADEncoding
{
    class IROADDataContainer;
}
namespace ROADoverEncoding
{
	class IROADDataCollection;
}

namespace ROADoverEncoding
{
	class IROADDataCollection
	{
        public: virtual ROADEncoding::IROADDataContainer* getIROADDataContainer(unsigned int aIndex) = 0;

		public: virtual unsigned int getCount() = 0;
	};
}

#endif
