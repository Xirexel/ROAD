#include <exception>

#include "DataWriteDriver.h"
#include "IEndianConvertor.h"
#include "crc.h"


ROADcoder::Driver::DataWriteDriver::DataWriteDriver(
        SharedMassive_ptr<ROADByte> &aData,
        PlatformDependencies::Unique_ptr<Endian::IEndianConvertor> &aConvertor)
    : _data(aData),
      _position(0),
      _convertor(aConvertor.release())
{
}

PlatformDependencies::ROADSize ROADcoder::Driver::DataWriteDriver::getLength()
{
    return this->_data.length();
}

PlatformDependencies::ROADSize ROADcoder::Driver::DataWriteDriver::getPosition()
{
    return this->_position;
}

ROADcoder::Driver::DataWriteDriver::~DataWriteDriver()
{
}

ROADcoder::Driver::IDataWriteDriver &ROADcoder::Driver::DataWriteDriver::operator <<(ROADUInt64 aValue)
{
    writeData(aValue);

    return *this;
}

ROADcoder::Driver::IDataWriteDriver &ROADcoder::Driver::DataWriteDriver::operator <<(ROADInt64 aValue)
{
    writeData(aValue);

    return *this;
}

ROADcoder::Driver::IDataWriteDriver &ROADcoder::Driver::DataWriteDriver::operator <<(ROADUInt32 aValue)
{
    writeData(aValue);

    return *this;
}

ROADcoder::Driver::IDataWriteDriver &ROADcoder::Driver::DataWriteDriver::operator <<(ROADInt32 aValue)
{
    writeData(aValue);

    return *this;
}

ROADcoder::Driver::IDataWriteDriver &ROADcoder::Driver::DataWriteDriver::operator <<(ROADUInt16 aValue)
{
    writeData(aValue);

    return *this;
}

ROADcoder::Driver::IDataWriteDriver &ROADcoder::Driver::DataWriteDriver::operator <<(ROADInt16 aValue)
{
    writeData(aValue);

    return *this;
}

ROADcoder::Driver::IDataWriteDriver &ROADcoder::Driver::DataWriteDriver::operator <<(ROADByte aValue)
{
    writeData(aValue);

    return *this;
}

ROADcoder::Driver::IDataWriteDriver &ROADcoder::Driver::DataWriteDriver::operator <<(ROADChar aValue)
{
    writeData(aValue);

    return *this;
}

ROADcoder::Driver::IDataWriteDriver &ROADcoder::Driver::DataWriteDriver::operator <<(std::tuple<PtrROADUInt8, ROADSize> aData)
{
    using namespace std;

    auto length = getLength();

    if(length >= (_position + get<1>(aData)))
    {
        memcpy(_data.get() + _position, get<0>(aData), get<1>(aData));

        _position += get<1>(aData);
    }
    else
        throw std::range_error("Position of pointer is out of range!!!");

    return *this;
}

ROADcoder::Driver::IDataWriteDriver &ROADcoder::Driver::DataWriteDriver::computeAndAppendCRC8(ROADUInt32 aValue)
{
    if(this->_position >= aValue)
        this->operator <<(CRCSupport::CRC::CRC8(_data.get() + (this->_position - aValue), aValue)); // 1 bytes - CRC8 code.
    else
        throw std::range_error("Position of pointer is out of range!!!");

    return *this;
}

ROADcoder::Driver::IDataWriteDriver &ROADcoder::Driver::DataWriteDriver::computeAndAppendCRC16(ROADUInt32 aValue)
{
    if(this->_position >= aValue)
        this->operator <<(CRCSupport::CRC::CRC16(_data.get() + (this->_position - aValue), aValue)); // 2 bytes - CRC16 code.
    else
        throw std::range_error("Position of pointer is out of range!!!");

    return *this;
}

ROADcoder::Driver::IDataWriteDriver &ROADcoder::Driver::DataWriteDriver::computeAndAppendCRC32(ROADUInt32 aValue)
{
    if(this->_position >= aValue)
        this->operator <<(CRCSupport::CRC::CRC32(_data.get() + (this->_position - aValue), aValue)); // 4 bytes - CRC32 code.
    else
        throw std::range_error("Position of pointer is out of range!!!");

    return *this;
}
