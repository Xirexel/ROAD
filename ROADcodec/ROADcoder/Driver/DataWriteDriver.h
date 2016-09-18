#ifndef __ROADcoder__Driver__DataWriteDriver_h__
#define __ROADcoder__Driver__DataWriteDriver_h__

#include <memory>


#include "IEndianConvertor.h"
#include "IDataWriteDriver.h"
#include "memorydefine.h"


namespace ROADcoder
{
	namespace Driver
	{
        class DataWriteDriver: public ROADcoder::Driver::IDataWriteDriver
		{
            private: SharedMassive_ptr<ROADByte> _data;
            private: ROADSize _position;
            private: Unique_ptr<Endian::IEndianConvertor> _convertor;

            public: virtual ROADSize getLength();

            public: virtual ROADSize getPosition();

            public: virtual ~DataWriteDriver();

            public: DataWriteDriver(
                    SharedMassive_ptr<ROADByte> &aData,
                    Unique_ptr<Endian::IEndianConvertor> &aConvertor);

            public: virtual IDataWriteDriver &operator <<(ROADUInt64 aValue);

            public: virtual IDataWriteDriver &operator <<(ROADInt64 aValue);

            public: virtual IDataWriteDriver &operator <<(ROADUInt32 aValue);

            public: virtual IDataWriteDriver &operator <<(ROADInt32 aValue);

            public: virtual IDataWriteDriver &operator <<(ROADUInt16 aValue);

            public: virtual IDataWriteDriver &operator <<(ROADInt16 aValue);

            public: virtual IDataWriteDriver &operator <<(ROADByte aValue);

            public: virtual IDataWriteDriver &operator <<(ROADChar aValue);

            public: virtual IDataWriteDriver &operator <<(std::tuple<PtrROADUInt8, ROADSize> aData);

            public: virtual IDataWriteDriver &computeAndAppendCRC8(ROADUInt32 aValue);

            public: virtual IDataWriteDriver &computeAndAppendCRC16(ROADUInt32 aValue);

            public: virtual IDataWriteDriver &computeAndAppendCRC32(ROADUInt32 aValue);

            private: template<typename T> void writeData(T aValue)
                {
                    auto length = getLength();

                    if(length >= (_position + sizeof(T)))
                    {
                        _convertor->convertToBytes(aValue, _data.get() + _position);

                        _position += sizeof(T);
                    }
                    else
                        throw std::range_error("Position of pointer is out of range!!!");
                }
		};
	}
}

#endif
