#include "persistroadencodingoptions.h"
#include "ROADoverEncodingOptionsFactory.h"
#include "../Endian/EndianType.h"
#include "ROADoverEncodingOptionsFirstVersion.h"

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
    using namespace ROADcoder::ROADoverCoder;

    std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> result;

    result.reset(loadROADoverEncodingOptions(aROADFormat).release());

    return result;
}


void PersistROADEncodingOptions::persistROADFormatAsDefault(unsigned int aROADFormat)
{
    settings.beginGroup("DefaultOptions");

    settings.setValue("defaultROADFormat", aROADFormat);

    settings.endGroup();
}

unsigned int PersistROADEncodingOptions::loadDefaultROADFormat()
{
    unsigned int lresult;

    settings.beginGroup("DefaultOptions");

    lresult = settings.value("defaultROADFormat", 0).toUInt();

    auto lListOfSupportedROADFormats = ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFactory::getSupportedFormats();

    auto liter = std::find(lListOfSupportedROADFormats.begin(), lListOfSupportedROADFormats.end(),
                           lresult);

    if(liter == lListOfSupportedROADFormats.end())
        lresult = 0;

    settings.endGroup();

    return lresult;
}

void PersistROADEncodingOptions::persistIROADoverEncodingOptions(std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> &aPtrOptions)
{
    persistROADoverEncodingOptions(aPtrOptions.get());
}

void PersistROADEncodingOptions::persistROADoverEncodingOptions(ROADcoder::ROADoverCoder::IROADoverEncodingOptions * aPtrOptions)
{
    using namespace ROADcoder::ROADoverCoder;

    do
    {
        if(aPtrOptions == nullptr)
            break;

        switch (aPtrOptions->getROADFormatMode()) {
        case (PlatformDependencies::ROADByte)ROADFormatMode::FIRSTVERSION:
        {
            auto loptions = dynamic_cast<ROADoverEncodingOptionsFirstVersion*>(aPtrOptions);

            if(loptions == nullptr)
                break;

            settings.beginGroup("ROADoverEncodingOptionsFirstVersion");

            settings.setValue("amountRangeLevels", loptions->getAmountRangLevels());

            settings.setValue("constantScale", loptions->getConstantScale());

            settings.setValue("domainShift", loptions->getDomainShift());

            settings.setValue("endianType", loptions->getEndianType());

            settings.setValue("maxSuperFrameLength", loptions->getMaxSuperFrameLength());

            settings.setValue("mixingChannelsMode", loptions->getMixingChannelsMode());

            settings.setValue("rangSampleLengthPowerOfTwoScale", loptions->getRangSampleLengthPowerOfTwoScale());

            settings.setValue("rangThreshold", loptions->getRangThreshold());

            settings.setValue("silenceThreshold", loptions->getSilenceThreshold());

            settings.setValue("encryptionFormat", loptions->getEncryptionFormat());

            settings.endGroup();
        }
        default:
            break;
        }



    }while(false);
}

std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> PersistROADEncodingOptions::loadROADoverEncodingOptions(unsigned int aROADFormat)
{
    using namespace ROADcoder::ROADoverCoder;

    std::unique_ptr<IROADoverEncodingOptions> lresult(ROADoverEncodingOptionsFactory::getIROADoverEncodingOptions(aROADFormat).release());

    do
    {

        if(!lresult)
            break;

        switch (aROADFormat)
        {

        case FIRSTVERSION:
        {
            auto loptions = dynamic_cast<ROADoverEncodingOptionsFirstVersion*>(lresult.get());

            if(loptions == nullptr)
                break;

            settings.beginGroup("ROADoverEncodingOptionsFirstVersion");

            loptions->setAmountRangLevels((ROADUInt8)settings.value("amountRangeLevels", 0).toInt());

            loptions->setConstantScale((ROADInt8)settings.value("constantScale", 96).toUInt());

            loptions->setDomainShift(settings.value("domainShift", 1).toInt());

            loptions->setEndianType((ROADUInt8)settings.value("endianType", (ROADUInt8)Endian::EndianType::LITTLE).toInt());

            loptions->setMaxSuperFrameLength((ROADUInt8)settings.value("maxSuperFrameLength", 10).toInt());

            loptions->setMixingChannelsMode(
                        ROADcoder::ROADoverCoder::ChannelsMixingMode(settings.value("mixingChannelsMode",
                                                                     ROADcoder::ROADoverCoder::ChannelsMixingMode::MID).toInt()));

            loptions->setRangSampleLengthPowerOfTwoScale((ROADUInt8)settings.value("rangSampleLengthPowerOfTwoScale", 0).toInt());

            loptions->setRangThreshold(settings.value("rangThreshold", 120.0).toDouble());

            loptions->setSilenceThreshold(settings.value("silenceThreshold", 120.0).toDouble());

            loptions->setEncryptionFormat(settings.value("encryptionFormat", 0).toInt());

            settings.endGroup();

        }

            break;
        default:
            break;
        }

    }while(false);


    return lresult;
}

