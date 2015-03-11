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


void EncodingOptionsFactory::setAsDefaultIROADoverEncodingOptions(unsigned int aROADFormat)
{
    return EncodingOptions::PersistROADEncodingOptions::getInstance().persistROADFormatAsDefault(aROADFormat);
}

unsigned int EncodingOptionsFactory::getAsDefaultIROADoverEncodingOptions()
{
    return EncodingOptions::PersistROADEncodingOptions::getInstance().loadDefaultROADFormat();
}
