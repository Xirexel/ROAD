#include "DataReadDriver.h"
#include "crc.h"


ROADdecoder::Driver::DataReadDriver::DataReadDriver(std::shared_ptr<ROADByte> &aData,
                                                    ROADUInt32 aLength,
                                                    std::unique_ptr<Endian::IEndianConvertor> &aConvertor)
    : _data(aData),
      _ptrData(aData.get()),
     _length(aLength),
     _position(0),
     _convertor(aConvertor.release())
{
}

ROADdecoder::Driver::DataReadDriver::DataReadDriver(DataContainer *aData,
                                                    ROADUInt32 aLength,
                                                    std::unique_ptr<Endian::IEndianConvertor> &aConvertor)
    : _ptrData(aData->get()),
     _length(aLength),
     _position(0),
     _convertor(aConvertor.release())
{
    _dataDataContainer = aData;
}

ROADdecoder::Driver::DataReadDriver::~DataReadDriver()
{

}

ROADdecoder::Driver::IDataReadDriver &ROADdecoder::Driver::DataReadDriver::operator >>(ROADInt64 &aValue)
{
    readData(aValue);

    return *this;
}

ROADdecoder::Driver::IDataReadDriver &ROADdecoder::Driver::DataReadDriver::operator >>(ROADUInt64 &aValue)
{
    readData(aValue);

    return *this;
}

ROADdecoder::Driver::IDataReadDriver &ROADdecoder::Driver::DataReadDriver::operator >>(std::tuple<PtrROADUInt8, ROADUInt64> aData)
{
    using namespace std;

    if(_length >= (_position + (unsigned)get<1>(aData)))
    {
        memcpy(get<0>(aData), this->_ptrData + _position, get<1>(aData));

        _position += get<1>(aData);
    }
    else
        throw std::range_error("Position of pointer is out of range!!!");

    return *this;

}

ROADdecoder::Driver::IDataReadDriver &ROADdecoder::Driver::DataReadDriver::operator >>(ROADUInt32 &aValue)
{
    readData(aValue);

    return *this;
}

ROADdecoder::Driver::IDataReadDriver &ROADdecoder::Driver::DataReadDriver::operator >>(ROADInt32 &aValue)
{
    readData(aValue);

    return *this;
}

ROADdecoder::Driver::IDataReadDriver &ROADdecoder::Driver::DataReadDriver::operator >>(ROADUInt16 &aValue)
{
    readData(aValue);

    return *this;
}

ROADdecoder::Driver::IDataReadDriver &ROADdecoder::Driver::DataReadDriver::operator >>(ROADInt16 &aValue)
{
    readData(aValue);

    return *this;
}

ROADdecoder::Driver::IDataReadDriver &ROADdecoder::Driver::DataReadDriver::operator >>(ROADUInt8 &aValue)
{
    readData(aValue);

    return *this;
}

ROADdecoder::Driver::IDataReadDriver &ROADdecoder::Driver::DataReadDriver::operator >>(ROADInt8 &aValue)
{
    readData(aValue);

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

    if(((this->_position + aOffset) <= this->_length) && ((this->_position + aOffset) >=0))
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
        auto lresult = CRCSupport::CRC::CRC8(this->_ptrData + this->_position, aLength);// 1 bytes - CRC8 code.

        auto lvalue = _convertor->convertToType(lresult, this->_ptrData + (this->_position + aLength));

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
        auto lresult = CRCSupport::CRC::CRC16(this->_ptrData + this->_position, aLength);// 2 bytes - CRC8 code.

        auto lvalue = _convertor->convertToType(lresult, this->_ptrData + (this->_position + aLength));

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
        auto lresult = CRCSupport::CRC::CRC32(this->_ptrData + this->_position, aLength);// 4 bytes - CRC8 code.

        auto lvalue = _convertor->convertToType(lresult, this->_ptrData + (this->_position + aLength));

        aOk = lresult == lvalue;
    }
    else
        throw std::range_error("Position of pointer is out of range!!!");

    return *this;
}
