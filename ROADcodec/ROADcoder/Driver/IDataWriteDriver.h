#ifndef __ROADcoder__Driver__IDataWriteDriver_h__
#define __ROADcoder__Driver__IDataWriteDriver_h__

#include "platformdependencies.h"


namespace ROADcoder
{
	namespace Driver
	{

        using namespace PlatformDependencies;
		class IDataWriteDriver
        {

            public: virtual ROADUInt32 getLength() = 0;

            public: virtual ROADUInt32 getPosition() = 0;

            public: virtual IDataWriteDriver &operator <<(ROADUInt64 aValue) = 0;

            public: virtual IDataWriteDriver &operator <<(ROADInt64 aValue) = 0;

            public: virtual IDataWriteDriver &operator <<(ROADUInt32 aValue) = 0;

            public: virtual IDataWriteDriver &operator <<(ROADInt32 aValue) = 0;

            public: virtual IDataWriteDriver &operator <<(ROADUInt16 aValue) = 0;

            public: virtual IDataWriteDriver &operator <<(ROADInt16 aValue) = 0;

            public: virtual IDataWriteDriver &operator <<(ROADByte aValue) = 0;

            public: virtual IDataWriteDriver &operator <<(ROADChar aValue) = 0;

            public: virtual IDataWriteDriver &computeAndAppendCRC8(ROADUInt32 aValue) = 0;

            public: virtual IDataWriteDriver &computeAndAppendCRC16(ROADUInt32 aValue) = 0;

            public: virtual IDataWriteDriver &computeAndAppendCRC32(ROADUInt32 aValue) = 0;

            public: virtual ~IDataWriteDriver(){}
		};
	}
}

#endif
