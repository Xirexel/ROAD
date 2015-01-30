#include "DataDriver.h"
#include "DataWriteDriver.h"
#include "EndianConvertorFactory.h"



std::unique_ptr<ROADcoder::Driver::IDataWriteDriver> ROADcoder::Driver::DataDriver::getIDataWriteDriver(std::unique_ptr<unsigned char> &aData, unsigned int aLength, Endian::EndianType aEndianType)
{
    auto lconvertor = Endian::EndianConvertorFactory::getInstance().getIEndianConvertor(aEndianType);

    unique_ptr<IDataWriteDriver> result(new DataWriteDriver(aData, aLength, lconvertor));

    return result;
}
