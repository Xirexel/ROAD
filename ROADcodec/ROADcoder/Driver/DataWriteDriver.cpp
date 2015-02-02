#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "DataWriteDriver.h"
#include "IEndianConvertor.h"


ROADcoder::Driver::DataWriteDriver::DataWriteDriver(std::unique_ptr<unsigned char> &aData, unsigned int aLength, std::unique_ptr<Endian::IEndianConvertor> &aConvertor)
    : _data(aData.release()),
      _length(aLength),
      _position(0),
      _convertor(aConvertor.release())
{
}

ROADcoder::Driver::DataWriteDriver::~DataWriteDriver()
{
}

ROADcoder::Driver::IDataWriteDriver &ROADcoder::Driver::DataWriteDriver::operator <<(unsigned int &aValue)
{
    if(_length >= (_position + sizeof(aValue)))
    {
        _convertor->convertToBytes(aValue, _data.get() + _position);

        _position += sizeof(aValue);
    }

    return *this;
}

ROADcoder::Driver::IDataWriteDriver &ROADcoder::Driver::DataWriteDriver::operator <<(int &aValue)
{
    if(_length >= (_position + sizeof(aValue)))
    {
        _convertor->convertToBytes(aValue, _data.get() + _position);

        _position += sizeof(aValue);
    }

    return *this;
}

ROADcoder::Driver::IDataWriteDriver &ROADcoder::Driver::DataWriteDriver::operator <<(unsigned short &aValue)
{
    if(_length >= (_position + sizeof(aValue)))
    {
        _convertor->convertToBytes(aValue, _data.get() + _position);

        _position += sizeof(aValue);
    }

    return *this;
}

ROADcoder::Driver::IDataWriteDriver &ROADcoder::Driver::DataWriteDriver::operator <<(short &aValue)
{
    if(_length >= (_position + sizeof(aValue)))
    {
        _convertor->convertToBytes(aValue, _data.get() + _position);

        _position += sizeof(aValue);
    }

    return *this;
}
