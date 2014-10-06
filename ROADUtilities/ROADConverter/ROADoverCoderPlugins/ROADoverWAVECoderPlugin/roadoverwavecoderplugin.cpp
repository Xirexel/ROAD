#include "roadoverwavecoderplugin.h"
#include "roadoverwavecoder.h"


#define UNUSED(expr) do { (void)(expr); } while (0)

ROADoverWAVECoderPlugin::ROADoverWAVECoderPlugin(QObject *parent) :
    QObject(parent)
{
}


IROADoverCoder* ROADoverWAVECoderPlugin::createIROADoverCoder(IROADoverRawReader* ptrReader,
                                                              std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> &aIROADoverCoderOptions,
                                                              IOriginalAudioStreamOptions *aOriginalAudioStreamOptions,
                                                              QString outputFile)
{
    aIROADoverCoderOptions->setAmountOfChannels(aOriginalAudioStreamOptions->getAmountOfChannels());

    aIROADoverCoderOptions->setEncryptionFormat(0);

    aIROADoverCoderOptions->setBitsPerSample(aOriginalAudioStreamOptions->getBPS());

    return new ROADoverWAVECoder(outputFile, ptrReader, aOriginalAudioStreamOptions, aIROADoverCoderOptions);

}

bool ROADoverWAVECoderPlugin::ROADoverWAVECoderPlugin::checkPlugin() const
{
    return true;
}

QString ROADoverWAVECoderPlugin::name() const
{
    return QString("ROADoverWAVE");
}

QWidget *ROADoverWAVECoderPlugin::getOptionsWidget()
{
    return nullptr;
}
