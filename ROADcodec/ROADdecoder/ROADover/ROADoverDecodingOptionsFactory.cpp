#include "ROADoverDecodingOptionsFactory.h"
#include "ROADoverDecodingOptionsExperemental.h"


ROADdecoder::ROADover::IROADoverDecodingOptions *ROADdecoder::ROADover::ROADoverDecodingOptionsFactory::getIROADoverDecodingOptions(std::unique_ptr<Driver::IDataReadDriver> &aPtrIDataReadDriver)
{
    ROADdecoder::ROADover::IROADoverDecodingOptions* result = nullptr;

    ROADUInt32 formatMode = 0;

    aPtrIDataReadDriver.get()->operator >>(formatMode);

    if(formatMode == 0)
    {
        result = new ROADoverDecodingOptionsExperemental(aPtrIDataReadDriver.get());
    }

    return result;
}
