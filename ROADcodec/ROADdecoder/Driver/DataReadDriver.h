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
            private: ROADInt64 _length;
            private: ROADInt64 _position;
            private: std::unique_ptr<Endian::IEndianConvertor> _convertor;

            public: DataReadDriver(std::shared_ptr<ROADByte> &aData, ROADUInt32 aLength, std::unique_ptr<Endian::IEndianConvertor> &aConvertor);

            public: virtual ROADUInt64 getLength();

            public: virtual ROADUInt64 getPosition();

            public: virtual ROADBool seek(ROADInt64 aOffset);

            public: virtual ROADBool eod();

            public: virtual IDataReadDriver &operator >>(ROADInt8 &aValue);

            public: virtual IDataReadDriver &operator >>(ROADUInt8 &aValue);

            public: virtual IDataReadDriver &operator >>(ROADInt16 &aValue);

            public: virtual IDataReadDriver &operator >>(ROADUInt16 &aValue);

            public: virtual IDataReadDriver &operator >>(ROADInt32 &aValue);

            public: virtual IDataReadDriver &operator >>(ROADUInt32 &aValue);

            public: virtual IDataReadDriver &operator >>(ROADInt64 &aValue);

            public: virtual IDataReadDriver &operator >>(ROADUInt64 &aValue);

            public: virtual IDataReadDriver &operator >>(std::tuple<PtrROADUInt8, ROADUInt64> aData);

            public: virtual IDataReadDriver &computeAndCheckCRC8(ROADInt64 aLength, ROADBool &aOk);

            public: virtual IDataReadDriver &computeAndCheckCRC16(ROADInt64 aLength, ROADBool &aOk);

            public: virtual IDataReadDriver &computeAndCheckCRC32(ROADInt64 aLength, ROADBool &aOk);

            public: virtual ~DataReadDriver();


            private: template<typename T> void readData(T &aValue)
            {
                if(_length >= (_position + sizeof(T)))
                {
                    aValue = _convertor->convertToType(aValue, _data.get() + _position);

                    _position += sizeof(T);
                }
                else
                    throw std::range_error("Position of pointer is out of range!!!");
            }
		};
	}
}

#endif
