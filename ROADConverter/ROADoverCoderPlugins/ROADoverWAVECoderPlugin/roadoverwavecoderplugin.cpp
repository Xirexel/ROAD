#include "roadoverwavecoderplugin.h"

ROADoverWAVECoderPlugin::ROADoverWAVECoderPlugin(QObject *parent) :
    QObject(parent)
{
}


IROADoverCoder* ROADoverWAVECoderPlugin::createIROADoverCoder(IROADoverRawReader* ptrReader,
                                                              IROADoverCoderOptions *aIROADoverCoderOptions,
                                                              IOriginalAudioStreamOptions *aOriginalAudioStreamOptions,
                                                              QString outputFile)
{
    return nullptr;
}

bool ROADoverWAVECoderPlugin::ROADoverWAVECoderPlugin::checkPlugin() const
{
    return true;
}

QString ROADoverWAVECoderPlugin::name() const
{
    return QString("ROADoverWAVE");
}
