#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADdecoder__Driver__IDataReadDriver_h__
#define __ROADdecoder__Driver__IDataReadDriver_h__

namespace ROADdecoder
{
	namespace Driver
	{
		class IDataReadDriver;
	}
}

namespace ROADdecoder
{
	namespace Driver
    {
		class IDataReadDriver
		{            
            public: virtual IDataReadDriver &operator >>(unsigned int &aValue) = 0;

            public: virtual ~IDataReadDriver(){}
		};

	}
}

#endif
