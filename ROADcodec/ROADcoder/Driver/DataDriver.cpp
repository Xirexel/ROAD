#include "DataDriver.h"
#include "DataWriteDriver.h"
#include "EndianConvertorFactory.h"



std::unique_ptr<ROADcoder::Driver::IDataWriteDriver> ROADcoder::Driver::DataDriver::getIDataWriteDriver(std::unique_ptr<ROADByte> &aData, ROADUInt32 aLength, Endian::EndianType aEndianType)
{
    auto lconvertor = Endian::EndianConvertorFactory::getInstance().getIEndianConvertor(aEndianType);

    std::unique_ptr<IDataWriteDriver> result(new DataWriteDriver(aData, aLength, lconvertor));

    return result;
}
