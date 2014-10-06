#include "persistroadencodingoptions.h"
#include "ROADoverEncodingOptionsFactory.h"
#include "ROADoverEncodingOptionsExperemental.h"

#include <QSettings>

using namespace EncodingOptions;

namespace {

QSettings settings("EvgenyPereguda", "ROADConvertor");

}

PersistROADEncodingOptions::PersistROADEncodingOptions()
{

}

PersistROADEncodingOptions& PersistROADEncodingOptions::getInstance()
{
    static PersistROADEncodingOptions sInstance;

    return sInstance;
}

std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> PersistROADEncodingOptions::loadIROADoverEncodingOptions(unsigned int aROADFormat)
{
    std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> result;

    switch (aROADFormat) {
    case 0:

        result.reset(loadROADoverEncodingOptionsExperemental().release());

        break;
    default:
        break;
    }

    return result;
}


void PersistROADEncodingOptions::persistIROADoverEncodingOptions(std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> &aPtrOptions)
{
    switch (aPtrOptions->getROADFormatMode()) {
    case 0:

        persistROADoverEncodingOptionsExperemental(aPtrOptions.get());

        break;
    default:
        break;
    }

}

void PersistROADEncodingOptions::persistROADoverEncodingOptionsExperemental(ROADcoder::ROADoverCoder::IROADoverEncodingOptions * aPtrOptions)
{
    using namespace ROADcoder::ROADoverCoder;

    do
    {
        if(aPtrOptions == nullptr)
            break;

        auto loptions = dynamic_cast<ROADoverEncodingOptionsExperemental*>(aPtrOptions);

        if(loptions == nullptr)
            break;

        settings.beginGroup("ROADoverEncodingOptionsExperemental");

        settings.setValue("amountRangeLevels", loptions->getAmountRangLevels());

        settings.setValue("domainShift", loptions->getDomainShift());

        settings.setValue("frameSampleLength", loptions->getFrameSampleLength());

        settings.setValue("mixingChannelsMode", loptions->getMixingChannelsMode());

        settings.setValue("rangThreshold", loptions->getRangThreshold());

        settings.setValue("silenceThreshold", loptions->getSilenceThreshold());

        settings.setValue("rangTopSampleLength", loptions->getRangTopSampleLength());

        settings.setValue("superFrameLength", loptions->getSuperFrameLength());

        settings.setValue("encryptionFormat", loptions->getEncryptionFormat());

        settings.endGroup();

    }while(false);


}

std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> PersistROADEncodingOptions::loadROADoverEncodingOptionsExperemental()
{
    using namespace ROADcoder::ROADoverCoder;

    std::unique_ptr<IROADoverEncodingOptions> lresult(ROADoverEncodingOptionsFactory::getIROADoverEncodingOptions(EXPEREMENTAL));

    do
    {
        if(!lresult)
            break;

        auto loptions = dynamic_cast<ROADoverEncodingOptionsExperemental*>(lresult.get());

        if(loptions == nullptr)
            break;

        settings.beginGroup("ROADoverEncodingOptionsExperemental");

        loptions->setAmountRangLevels(settings.value("amountRangeLevels", 3).toInt());

        loptions->setDomainShift(settings.value("domainShift", 1).toInt());

        loptions->setFrameSampleLength(settings.value("frameSampleLength", 2048).toInt());

        loptions->setMixingChannelsMode(ROADcoder::ROADoverCoder::ChannelsMixingMode(settings.value("mixingChannelsMode", 1).toInt()));

        loptions->setRangThreshold(settings.value("rangThreshold", 0.0).toDouble());

        loptions->setSilenceThreshold(settings.value("silenceThreshold", 120.0).toDouble());

        loptions->setRangTopSampleLength(settings.value("rangTopSampleLength", 32).toInt());

        loptions->setSuperFrameLength(settings.value("superFrameLength", 10).toInt());

        loptions->setEncryptionFormat(settings.value("encryptionFormat", 0).toInt());

        settings.endGroup();

    }while(false);


    return lresult;
}
