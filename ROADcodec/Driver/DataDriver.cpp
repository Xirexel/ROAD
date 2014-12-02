#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "DataDriver.h"
#include "DataReadDriver.h"
#include "EndianConvertorFactory.h"


#include "driver_global.h"

unique_ptr<Driver::IDataReadDriver> Driver::DataDriver::getIDataReadDriver(unique_ptr<unsigned char> &aData,
                                                                unsigned int aLength,
                                                                Endian::EndianType aEndianType)
{

    unique_ptr<Endian::IEndianConvertor> lconvertor(Endian::EndianConvertorFactory::getIEndianConvertor(aEndianType).release());

    unique_ptr<Driver::IDataReadDriver> result(new DataReadDriver(aData, aLength, lconvertor));

    return result;
}
