#include "encodingoptionsfactory.h"
#include "persistroadencodingoptions.h"



std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> EncodingOptionsFactory::getIROADoverEncodingOptions(unsigned int aROADFormat)
{
    return EncodingOptions::PersistROADEncodingOptions::getInstance().loadIROADoverEncodingOptions(aROADFormat);
}

void EncodingOptionsFactory::persistIROADoverEncodingOptions(std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> &aOptions)
{
    EncodingOptions::PersistROADEncodingOptions::getInstance().persistIROADoverEncodingOptions(aOptions);
}
