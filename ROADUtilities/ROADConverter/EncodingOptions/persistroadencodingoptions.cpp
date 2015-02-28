#include "persistroadencodingoptions.h"
#include "ROADoverEncodingOptionsFactory.h"
#include "../Endian/EndianType.h"
#include "ROADoverEncodingOptionsExperemental.h"
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
        case EXPEREMENTAL:
        {
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
        }
            break;
        case FIRSTVERSION:
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

    std::unique_ptr<IROADoverEncodingOptions> lresult(ROADoverEncodingOptionsFactory::getIROADoverEncodingOptions(aROADFormat));

    do
    {

        if(!lresult)
            break;

        switch (aROADFormat)
        {
        case EXPEREMENTAL:
        {
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
        }

            break;

        case FIRSTVERSION:
        {
            auto loptions = dynamic_cast<ROADoverEncodingOptionsFirstVersion*>(lresult.get());

            if(loptions == nullptr)
                break;

            settings.beginGroup("ROADoverEncodingOptionsFirstVersion");

            loptions->setAmountRangLevels((ROADUInt8)settings.value("amountRangeLevels", 0).toInt());

            loptions->setConstantScale((ROADInt8)settings.value("constantScale", 96).toUInt());

            loptions->setDomainShift(settings.value("domainShift", 1).toInt());

            loptions->setEndianType((ROADUInt8)settings.value("endianType", (ROADUInt8)Endian::LITTLE).toInt());

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

