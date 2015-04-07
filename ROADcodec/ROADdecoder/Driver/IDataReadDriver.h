#ifndef __ROADdecoder__Driver__IDataReadDriver_h__
#define __ROADdecoder__Driver__IDataReadDriver_h__

#include <memory>


#include "platformdependencies.h"


namespace ROADdecoder
{
	namespace Driver
    {
    using namespace PlatformDependencies;

		class IDataReadDriver
        {
            public: virtual ROADUInt64 getLength() = 0;

            public: virtual ROADUInt64 getPosition() = 0;

            public: virtual ROADBool seek(ROADInt64 aOffset) = 0;

            public: virtual ROADBool eod() = 0;

            public: virtual IDataReadDriver &operator >>(ROADInt8 &aValue) = 0;

            public: virtual IDataReadDriver &operator >>(ROADUInt8 &aValue) = 0;

            public: virtual IDataReadDriver &operator >>(ROADInt16 &aValue) = 0;

            public: virtual IDataReadDriver &operator >>(ROADUInt16 &aValue) = 0;

            public: virtual IDataReadDriver &operator >>(ROADInt32 &aValue) = 0;

            public: virtual IDataReadDriver &operator >>(ROADUInt32 &aValue) = 0;

            public: virtual IDataReadDriver &operator >>(ROADInt64 &aValue) = 0;

            public: virtual IDataReadDriver &operator >>(ROADUInt64 &aValue) = 0;

            public: virtual IDataReadDriver &operator >>(std::tuple<PtrROADUInt8, ROADUInt64> aData) = 0;

            public: virtual IDataReadDriver &computeAndCheckCRC8(ROADInt64 aLength, ROADBool &aOk) = 0;

            public: virtual IDataReadDriver &computeAndCheckCRC16(ROADInt64 aLength, ROADBool &aOk) = 0;

            public: virtual IDataReadDriver &computeAndCheckCRC32(ROADInt64 aLength, ROADBool &aOk) = 0;

            public: virtual ~IDataReadDriver(){}
		};

	}
}

#endif
