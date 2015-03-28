#ifndef __ROADdecoder__Driver__DataReadDriver_h__
#define __ROADdecoder__Driver__DataReadDriver_h__

#include <memory>

#include "IEndianConvertor.h"
#include "IDataReadDriver.h"


namespace ROADdecoder
{
	namespace Driver
	{
		class DataReadDriver: public ROADdecoder::Driver::IDataReadDriver
		{
            private: std::shared_ptr<ROADByte> _data;
            private: ROADUInt32 _length;
            private: ROADUInt32 _position;
            private: std::unique_ptr<Endian::IEndianConvertor> _convertor;

            public: DataReadDriver(std::shared_ptr<ROADByte> &aData, ROADUInt32 aLength, std::unique_ptr<Endian::IEndianConvertor> &aConvertor);

            public: virtual ROADUInt32 getLength();

            public: virtual ROADUInt32 getPosition();

            public: virtual IDataReadDriver &operator >>(ROADInt8 &aValue);

            public: virtual IDataReadDriver &operator >>(ROADUInt8 &aValue);

            public: virtual IDataReadDriver &operator >>(ROADInt16 &aValue);

            public: virtual IDataReadDriver &operator >>(ROADUInt16 &aValue);

            public: virtual IDataReadDriver &operator >>(ROADInt32 &aValue);

            public: virtual IDataReadDriver &operator >>(ROADUInt32 &aValue);

            public: virtual IDataReadDriver &operator >>(ROADInt64 &aValue);

            public: virtual IDataReadDriver &operator >>(ROADUInt64 &aValue);

            public: virtual IDataReadDriver &computeAndCheckCRC8(ROADUInt32 aLength, ROADBool &aOk);

            public: virtual IDataReadDriver &computeAndCheckCRC16(ROADUInt32 aLength, ROADBool &aOk);

            public: virtual IDataReadDriver &computeAndCheckCRC32(ROADUInt32 aLength, ROADBool &aOk);

            public: virtual ~DataReadDriver();
		};
	}
}

#endif
