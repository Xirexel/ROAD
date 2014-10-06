#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "DataDriver.h"
#include "DataReadDriver.h"
#include "EndianConvertorFactory.h"


std::unique_ptr<ROADdecoder::Driver::IDataReadDriver> ROADdecoder::Driver::DataDriver::getIDataReadDriver(std::unique_ptr<unsigned char> &aData, unsigned int aLength, Endian::EndianType aEndianType) {

    unique_ptr<Endian::IEndianConvertor> lconvertor(Endian::EndianConvertorFactory::getIEndianConvertor(aEndianType).release());

    unique_ptr<IDataReadDriver> result(new DataReadDriver(aData, aLength, lconvertor));

    return result;
}
