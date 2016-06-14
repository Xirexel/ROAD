#include "roadovercoderfactory.h"
#include "roadoverwavecoder.h"
#include "ROADRawDataFormat.h"
#include "../../../ROADcodec/ROADcoder/ROADoverCoder/IROADoverEncodingOptions.h"

ROADoverCoderFactory::ROADoverCoderFactory()
{
}

ROADoverCoderFactory::~ROADoverCoderFactory()
{

}

IROADoverCoder* ROADoverCoderFactory::createIROADoverCoder(IROADoverRawReader* ptrReader,
                                             std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions>
                                             &aIROADoverCoderOptions,
                                             IOriginalAudioStreamOptions *aOriginalAudioStreamOptions,
                                             QString outputFile)
{
    IROADoverCoder* lresult = nullptr;

    using namespace ROADcoder;

    using namespace ROADcoder::ROADoverCoder;

    aIROADoverCoderOptions->setAmountOfChannels(aOriginalAudioStreamOptions->getAmountOfChannels());

    aIROADoverCoderOptions->setEncryptionFormat(0);

    auto lTypeBitePerSample = aOriginalAudioStreamOptions->getTypeBitePerSample();

    ROADRawDataFormat lROADRawDataFormat = ROADRawDataFormat::U8;

    switch (lTypeBitePerSample) {
    case IOriginalAudioStreamOptions::U8 :
        lROADRawDataFormat = ROADRawDataFormat::U8;

        break;
    case IOriginalAudioStreamOptions::S16 :
        lROADRawDataFormat = ROADRawDataFormat::S16;

        break;
    case IOriginalAudioStreamOptions::S32 :
        lROADRawDataFormat = ROADRawDataFormat::S32;

        break;
    default:
        break;
    }

    aIROADoverCoderOptions->setBitsPerSampleCode(lROADRawDataFormat);

    aIROADoverCoderOptions->setOriginalFrequency(aOriginalAudioStreamOptions->getFrequency());

    aIROADoverCoderOptions->setSelectedPreListeningChannel(0);

    Unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> lOptions(aIROADoverCoderOptions.release());

    lresult = new ROADoverWAVECoder(outputFile, ptrReader, aOriginalAudioStreamOptions, lOptions);

    return lresult;
}

QString ROADoverCoderFactory::name() const
{
    return QString("ROADoverWAVE");
}

QWidget* ROADoverCoderFactory::getLowFormatOptionsWidget()
{
    QWidget* lresult = nullptr;

    return lresult;
}
