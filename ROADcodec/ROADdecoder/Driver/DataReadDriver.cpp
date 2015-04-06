#include "DataReadDriver.h"
#include "crc.h"

ROADdecoder::Driver::DataReadDriver::DataReadDriver(std::shared_ptr<ROADByte> &aData,
                                                    ROADUInt32 aLength,
                                                    std::unique_ptr<Endian::IEndianConvertor> &aConvertor)
    : _data(aData),
     _length(aLength),
     _position(0),
     _convertor(aConvertor.release())
{
}

ROADdecoder::Driver::DataReadDriver::~DataReadDriver()
{

}

ROADdecoder::Driver::IDataReadDriver &ROADdecoder::Driver::DataReadDriver::operator >>(ROADInt64 &aValue)
{
    if(_length >= (_position + 8))
    {
        aValue = _convertor->convertToINT64(_data.get() + _position);

        _position += 8;
    }
    else
        throw std::range_error("Position of pointer is out of range!!!");

    return *this;
}

ROADdecoder::Driver::IDataReadDriver &ROADdecoder::Driver::DataReadDriver::operator >>(ROADUInt64 &aValue)
{
    if(_length >= (_position + 8))
    {
        aValue = _convertor->convertToUINT64(_data.get() + _position);

        _position += 8;
    }
    else
        throw std::range_error("Position of pointer is out of range!!!");

    return *this;
}

ROADdecoder::Driver::IDataReadDriver &ROADdecoder::Driver::DataReadDriver::operator >>(std::tuple<PtrROADUInt8, ROADUInt64> aData)
{
    using namespace std;

    if(_length >= (_position + get<1>(aData)))
    {
        memcpy(get<0>(aData), _data.get() + _position, get<1>(aData));

        _position += get<1>(aData);
    }
    else
        throw std::range_error("Position of pointer is out of range!!!");

    return *this;

}

ROADdecoder::Driver::IDataReadDriver &ROADdecoder::Driver::DataReadDriver::operator >>(ROADUInt32 &aValue)
{
    if(_length >= (_position + 4))
    {
        aValue = _convertor->convertToUINT32(_data.get() + _position);

        _position += 4;
    }
    else
        throw std::range_error("Position of pointer is out of range!!!");

    return *this;
}

ROADdecoder::Driver::IDataReadDriver &ROADdecoder::Driver::DataReadDriver::operator >>(ROADInt32 &aValue)
{
    if(_length >= (_position + 4))
    {
        aValue = _convertor->convertToINT32(_data.get() + _position);

        _position += 4;
    }
    else
        throw std::range_error("Position of pointer is out of range!!!");

    return *this;
}

ROADdecoder::Driver::IDataReadDriver &ROADdecoder::Driver::DataReadDriver::operator >>(ROADUInt16 &aValue)
{
    if(_length >= (_position + 2))
    {
        aValue = _convertor->convertToUINT16(_data.get() + _position);

        _position += 2;
    }
    else
        throw std::range_error("Position of pointer is out of range!!!");

    return *this;
}

ROADdecoder::Driver::IDataReadDriver &ROADdecoder::Driver::DataReadDriver::operator >>(ROADInt16 &aValue)
{
    if(_length >= (_position + 2))
    {
        aValue = _convertor->convertToINT16(_data.get() + _position);

        _position += 2;
    }
    else
        throw std::range_error("Position of pointer is out of range!!!");

    return *this;
}

ROADdecoder::Driver::IDataReadDriver &ROADdecoder::Driver::DataReadDriver::operator >>(ROADUInt8 &aValue)
{
    if(_length >= (_position + 1))
    {
        aValue = _convertor->convertToUINT8(_data.get() + _position);

        _position += 1;
    }
    else
        throw std::range_error("Position of pointer is out of range!!!");

    return *this;
}

ROADdecoder::Driver::IDataReadDriver &ROADdecoder::Driver::DataReadDriver::operator >>(ROADInt8 &aValue)
{
    if(_length >= (_position + 1))
    {
        aValue = _convertor->convertToINT8(_data.get() + _position);

        _position += 1;
    }
    else
        throw std::range_error("Position of pointer is out of range!!!");

    return *this;
}


PlatformDependencies::ROADUInt64 ROADdecoder::Driver::DataReadDriver::getLength()
{
    return this->_length;
}

PlatformDependencies::ROADUInt64 ROADdecoder::Driver::DataReadDriver::getPosition()
{
    return this->_position;
}

PlatformDependencies::ROADBool ROADdecoder::Driver::DataReadDriver::seek(ROADInt64 aOffset)
{
    ROADBool lresult = false;

    if(this->_position + aOffset <= this->_length && this->_position + aOffset >=0)
    {
        this->_position += aOffset;

        lresult = true;
    }

    return lresult;
}

PlatformDependencies::ROADBool ROADdecoder::Driver::DataReadDriver::eod()
{
    ROADBool lresult = false;

    if(this->_position >= (this->_length - 1))
    {
        lresult = true;
    }

    return lresult;
}

ROADdecoder::Driver::IDataReadDriver &ROADdecoder::Driver::DataReadDriver::computeAndCheckCRC8(ROADInt64 aLength, ROADBool &aOk)
{
    if(this->_position + aLength + 1 <= this->_length)
    {
        auto lresult = CRCSupport::CRC::CRC8(_data.get() + this->_position, aLength);// 1 bytes - CRC8 code.

        auto lvalue = _convertor->convertToUINT8(_data.get() + (this->_position + aLength));

        aOk = lresult == lvalue;
    }
    else
        throw std::range_error("Position of pointer is out of range!!!");

    return *this;
}

ROADdecoder::Driver::IDataReadDriver &ROADdecoder::Driver::DataReadDriver::computeAndCheckCRC16(ROADInt64 aLength, ROADBool &aOk)
{
    if(this->_position + aLength + 2 <= this->_length)
    {
        auto lresult = CRCSupport::CRC::CRC16(_data.get() + this->_position, aLength);// 2 bytes - CRC8 code.

        auto lvalue = _convertor->convertToUINT16(_data.get() + (this->_position + aLength));

        aOk = lresult == lvalue;
    }
    else
        throw std::range_error("Position of pointer is out of range!!!");

    return *this;
}

ROADdecoder::Driver::IDataReadDriver &ROADdecoder::Driver::DataReadDriver::computeAndCheckCRC32(ROADInt64 aLength, ROADBool &aOk)
{
    if(this->_position + aLength + 4 <= this->_length)
    {
        auto lresult = CRCSupport::CRC::CRC32(_data.get() + this->_position, aLength);// 4 bytes - CRC8 code.

        auto lvalue = _convertor->convertToUINT32(_data.get() + (this->_position + aLength));

        aOk = lresult == lvalue;
    }
    else
        throw std::range_error("Position of pointer is out of range!!!");

    return *this;
}
