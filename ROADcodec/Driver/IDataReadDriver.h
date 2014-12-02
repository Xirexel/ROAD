#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __Driver__IDataReadDriver_h__
#define __Driver__IDataReadDriver_h__

namespace Driver
{
	class IDataReadDriver;
}

namespace Driver
{
	class IDataReadDriver
	{
        public: virtual IDataReadDriver &operator >>(unsigned int &aValue) = 0;

        public: virtual ~IDataReadDriver(){}
	};
}

#endif
