#ifndef __ROADcoder__Driver__DataWriteDriver_h__
#define __ROADcoder__Driver__DataWriteDriver_h__

#include <memory>


#include "IEndianConvertor.h"
#include "IDataWriteDriver.h"


namespace ROADcoder
{
	namespace Driver
	{
		class DataWriteDriver: public ROADcoder::Driver::IDataWriteDriver
		{
            private: std::unique_ptr<ROADByte> _data;
            private: ROADUInt32 _length;
            private: ROADUInt32 _position;
            private: std::unique_ptr<Endian::IEndianConvertor> _convertor;

            public: virtual ROADUInt32 getLength();

            public: virtual ROADUInt32 getPosition();

            public: virtual ~DataWriteDriver();

            public: DataWriteDriver(std::unique_ptr<ROADByte> &aData, ROADUInt32 aLength, std::unique_ptr<Endian::IEndianConvertor> &aConvertor);

            public: virtual IDataWriteDriver &operator <<(ROADUInt32 aValue);

            public: virtual IDataWriteDriver &operator <<(ROADInt32 aValue);

            public: virtual IDataWriteDriver &operator <<(ROADUInt16 aValue);

            public: virtual IDataWriteDriver &operator <<(ROADInt16 aValue);

            public: virtual IDataWriteDriver &operator <<(ROADByte aValue);

            public: virtual IDataWriteDriver &operator <<(ROADChar aValue);

            private: template<typename T> void writeData(T aValue)
                {
                    if(_length >= (_position + sizeof(T)))
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
