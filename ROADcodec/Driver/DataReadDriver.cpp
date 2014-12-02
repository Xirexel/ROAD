#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "DataReadDriver.h"


#include "driver_global.h"

Driver::DataReadDriver::DataReadDriver(unique_ptr<unsigned char> &aData, unsigned int aLength, unique_ptr<Endian::IEndianConvertor> &aConvertor)
    : _data(aData.release()),
     _length(aLength),
     _position(0),
     _convertor(aConvertor.release())
{
}

Driver::DataReadDriver::~DataReadDriver()
{

}

Driver::IDataReadDriver &Driver::DataReadDriver::operator >>(unsigned int &aValue)
{
    UNUSED(aValue)

    if(_length >= (_position + 4))
    {
        aValue = _convertor->convertToUINT32(_data.get() + _position);

        _position += 4;
    }

    return *this;
}
