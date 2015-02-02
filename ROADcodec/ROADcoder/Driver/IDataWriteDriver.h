#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADcoder__Driver__IDataWriteDriver_h__
#define __ROADcoder__Driver__IDataWriteDriver_h__

namespace ROADcoder
{
	namespace Driver
	{
		class IDataWriteDriver;
	}
}

namespace ROADcoder
{
	namespace Driver
	{
		class IDataWriteDriver
		{
            public: virtual IDataWriteDriver &operator <<(unsigned int &aValue) = 0;

            public: virtual IDataWriteDriver &operator <<(int &aValue) = 0;

            public: virtual IDataWriteDriver &operator <<(unsigned short &aValue) = 0;

            public: virtual IDataWriteDriver &operator <<(short &aValue) = 0;

            public: virtual ~IDataWriteDriver(){}
		};
	}
}

#endif
