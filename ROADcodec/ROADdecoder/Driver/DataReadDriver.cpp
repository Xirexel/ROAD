#include "DataReadDriver.h"

ROADdecoder::Driver::DataReadDriver::DataReadDriver(std::unique_ptr<ROADByte> &aData,
                                                    ROADUInt32 aLength,
                                                    std::unique_ptr<Endian::IEndianConvertor> &aConvertor)
    : _data(aData.release()),
     _length(aLength),
     _position(0),
     _convertor(aConvertor.release())
{
}

ROADdecoder::Driver::DataReadDriver::~DataReadDriver()
{

}

ROADdecoder::Driver::IDataReadDriver &ROADdecoder::Driver::DataReadDriver::operator >>(ROADUInt32 &aValue)
{
    if(_length >= (_position + 4))
    {
        aValue = _convertor->convertToUINT32(_data.get() + _position);

        _position += 4;
    }

    return *this;
}

ROADdecoder::Driver::IDataReadDriver &ROADdecoder::Driver::DataReadDriver::operator >>(ROADInt32 &aValue)
{
    if(_length >= (_position + 4))
    {
        aValue = _convertor->convertToINT32(_data.get() + _position);

        _position += 4;
    }

    return *this;
}

ROADdecoder::Driver::IDataReadDriver &ROADdecoder::Driver::DataReadDriver::operator >>(ROADUInt16 &aValue)
{
    if(_length >= (_position + 2))
    {
        aValue = _convertor->convertToUINT16(_data.get() + _position);

        _position += 2;
    }

    return *this;
}

ROADdecoder::Driver::IDataReadDriver &ROADdecoder::Driver::DataReadDriver::operator >>(ROADInt16 &aValue)
{
    if(_length >= (_position + 2))
    {
        aValue = _convertor->convertToINT16(_data.get() + _position);

        _position += 2;
    }

    return *this;
}

ROADdecoder::Driver::IDataReadDriver &ROADdecoder::Driver::DataReadDriver::operator >>(ROADUInt8 &aValue)
{
    if(_length >= (_position + 1))
    {
        aValue = _convertor->convertToUINT8(_data.get() + _position);

        _position += 1;
    }

    return *this;
}

ROADdecoder::Driver::IDataReadDriver &ROADdecoder::Driver::DataReadDriver::operator >>(ROADInt8 &aValue)
{
    if(_length >= (_position + 1))
    {
        aValue = _convertor->convertToINT8(_data.get() + _position);

        _position += 1;
    }

    return *this;
}


PlatformDependencies::ROADUInt32 ROADdecoder::Driver::DataReadDriver::getLength()
{
    return this->_length;
}

PlatformDependencies::ROADUInt32 ROADdecoder::Driver::DataReadDriver::getPosition()
{
    return this->_position;
}
