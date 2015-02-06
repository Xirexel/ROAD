#include <exception>

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

ROADcoder::Driver::IDataWriteDriver &ROADcoder::Driver::DataWriteDriver::operator <<(unsigned int aValue)
{
    writeData(aValue);

    return *this;
}

ROADcoder::Driver::IDataWriteDriver &ROADcoder::Driver::DataWriteDriver::operator <<(int aValue)
{
    writeData(aValue);

    return *this;
}

ROADcoder::Driver::IDataWriteDriver &ROADcoder::Driver::DataWriteDriver::operator <<(unsigned short aValue)
{
    writeData(aValue);

    return *this;
}

ROADcoder::Driver::IDataWriteDriver &ROADcoder::Driver::DataWriteDriver::operator <<(short aValue)
{
    writeData(aValue);

    return *this;
}

ROADcoder::Driver::IDataWriteDriver &ROADcoder::Driver::DataWriteDriver::operator <<(unsigned char aValue)
{
    writeData(aValue);

    return *this;
}

ROADcoder::Driver::IDataWriteDriver &ROADcoder::Driver::DataWriteDriver::operator <<(char aValue)
{
    writeData(aValue);

    return *this;
}
