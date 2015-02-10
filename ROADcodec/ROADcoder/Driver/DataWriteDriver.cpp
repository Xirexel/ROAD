#include <exception>

#include "DataWriteDriver.h"
#include "IEndianConvertor.h"


ROADcoder::Driver::DataWriteDriver::DataWriteDriver(std::unique_ptr<ROADByte> &aData, ROADUInt32 aLength, std::unique_ptr<Endian::IEndianConvertor> &aConvertor)
    : _data(aData.release()),
      _length(aLength),
      _position(0),
      _convertor(aConvertor.release())
{
}

ROADcoder::Driver::DataWriteDriver::~DataWriteDriver()
{
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
