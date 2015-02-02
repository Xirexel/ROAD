#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "DataDriver.h"
#include "DataReadDriver.h"
#include "EndianConvertorFactory.h"


std::unique_ptr<ROADdecoder::Driver::IDataReadDriver> ROADdecoder::Driver::DataDriver::getIDataReadDriver(std::unique_ptr<unsigned char> &aData, unsigned int aLength, Endian::EndianType aEndianType) {

    auto lconvertor = Endian::EndianConvertorFactory::getInstance().getIEndianConvertor(aEndianType);

    unique_ptr<IDataReadDriver> result(new DataReadDriver(aData, aLength, lconvertor));

    return result;
}
