#ifndef __ROADdecoder__Driver__IDataReadDriver_h__
#define __ROADdecoder__Driver__IDataReadDriver_h__

#include "platformdependencies.h"


namespace ROADdecoder
{
	namespace Driver
    {
    using namespace PlatformDependencies;

		class IDataReadDriver
        {
            public: virtual ROADUInt32 getLength() = 0;

            public: virtual ROADUInt32 getPosition() = 0;

            public: virtual IDataReadDriver &operator >>(ROADInt8 &aValue) = 0;

            public: virtual IDataReadDriver &operator >>(ROADUInt8 &aValue) = 0;

            public: virtual IDataReadDriver &operator >>(ROADInt16 &aValue) = 0;

            public: virtual IDataReadDriver &operator >>(ROADUInt16 &aValue) = 0;

            public: virtual IDataReadDriver &operator >>(ROADInt32 &aValue) = 0;

            public: virtual IDataReadDriver &operator >>(ROADUInt32 &aValue) = 0;

            public: virtual ~IDataReadDriver(){}
		};

	}
}

#endif
