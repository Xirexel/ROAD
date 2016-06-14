#include "DataDriver.h"
#include "DataWriteDriver.h"
#include "EndianConvertorFactory.h"



PlatformDependencies::Unique_ptr<ROADcoder::Driver::IDataWriteDriver> ROADcoder::Driver::DataDriver::getIDataWriteDriver(
        SharedMassive_ptr<ROADByte> &aData,
        Endian::EndianType aEndianType)
{
    auto lconvertor = Endian::EndianConvertorFactory::getInstance().getIEndianConvertor(aEndianType);

    PlatformDependencies::Unique_ptr<IDataWriteDriver> result(new DataWriteDriver(aData, lconvertor));

    return result;
}
