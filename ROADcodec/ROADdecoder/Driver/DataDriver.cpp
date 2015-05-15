#include "DataDriver.h"
#include "DataReadDriver.h"
#include "EndianConvertorFactory.h"


std::unique_ptr<ROADdecoder::Driver::IDataReadDriver> ROADdecoder::Driver::DataDriver::getIDataReadDriver(std::shared_ptr<ROADByte> &aData,
                                                                                                          ROADUInt32 aLength,
                                                                                                          Endian::EndianType aEndianType)
{

    auto lconvertor = Endian::EndianConvertorFactory::getInstance().getIEndianConvertor(aEndianType);

    std::unique_ptr<IDataReadDriver> result(new DataReadDriver(aData, aLength, lconvertor));

    return result;
}

std::unique_ptr<ROADdecoder::Driver::IDataReadDriver> ROADdecoder::Driver::DataDriver::getIDataReadDriver(ROADdecoder::Driver::DataContainer *aData,
                                                                                                          ROADUInt32 aLength,
                                                                                                          Endian::EndianType aEndianType)
{

    auto lconvertor = Endian::EndianConvertorFactory::getInstance().getIEndianConvertor(aEndianType);

    std::unique_ptr<IDataReadDriver> result(new DataReadDriver(aData, aLength, lconvertor));

    return result;
}
