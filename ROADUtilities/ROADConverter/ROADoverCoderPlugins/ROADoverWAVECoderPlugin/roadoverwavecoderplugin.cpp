#include "roadoverwavecoderplugin.h"
#include "roadoverwavecoder.h"


ROADoverWAVECoderPlugin::ROADoverWAVECoderPlugin(QObject *parent) :
    QObject(parent)
{
}


IROADoverCoder* ROADoverWAVECoderPlugin::createIROADoverCoder(IROADoverRawReader* ptrReader,
                                                              IROADoverCoderOptions *aIROADoverCoderOptions,
                                                              IOriginalAudioStreamOptions *aOriginalAudioStreamOptions,
                                                              QString outputFile)
{
    ROADoverEncoding::ROADoverEncodingOptions lOptions;

    lOptions.setBitsPerSample(aOriginalAudioStreamOptions->getBPS());

    lOptions.setChannels(aOriginalAudioStreamOptions->getAmountOfChannels());

    lOptions.setDomainShift(aIROADoverCoderOptions->getRelativeDomainShift());

    lOptions.setEncryptionFromat(0);


    switch(aIROADoverCoderOptions->getTypeROADFormat())
    {

    case IROADoverCoderOptions::EXPEREMENTAL:

        lOptions.setFormat(ROADoverEncoding::EXPEREMENTAL);

        break;
    }



    lOptions.setFrameSampleLength(aIROADoverCoderOptions->getFrameSampleLength());

    lOptions.setLongestRangSampleLength(aIROADoverCoderOptions->getMaxSampleLengthRang());



    switch(aIROADoverCoderOptions->getTypeMixingChannelsMode())
    {

    case IROADoverCoderOptions::NONE:

        lOptions.setMixingChannelsMode(ROADoverEncoding::NONE);

        break;

    case IROADoverCoderOptions::L_PLUS_R:

        lOptions.setMixingChannelsMode(ROADoverEncoding::LplusR);

        break;

    case IROADoverCoderOptions::L_MINUS_R:

        lOptions.setMixingChannelsMode(ROADoverEncoding::LminusR);

        break;
    }



    lOptions.setShortestRangSampleLength(aIROADoverCoderOptions->getMinSampleLengthRang());

    lOptions.setSuperframeLength(aIROADoverCoderOptions->getSuperFrameLength());




//    switch(aOriginalAudioStreamOptions->getTypeBitePerSample())
//    {

//    case IOriginalAudioStreamOptions::U8:

//        lOptions.setRangThreshold(aIROADoverCoderOptions->getRangThreshold());

//        lOptions.setSilenceThreshold(aIROADoverCoderOptions->getSilenceThreshold());

//        break;


//    case IOriginalAudioStreamOptions::S16:

//        lOptions.setRangThreshold(10000);

//        lOptions.setSilenceThreshold(10000);

//        break;


//    case IOriginalAudioStreamOptions::S32:

//        lOptions.setRangThreshold(14167287856893.154);

//        lOptions.setSilenceThreshold(14167287856893.154);

//        break;

//    }


//    lOptions.setRangThreshold(aIROADoverCoderOptions->getRangThreshold());

//    lOptions.setSilenceThreshold(aIROADoverCoderOptions->getSilenceThreshold());



    return new ROADoverWAVECoder(outputFile, ptrReader, aOriginalAudioStreamOptions, lOptions);
}

bool ROADoverWAVECoderPlugin::ROADoverWAVECoderPlugin::checkPlugin() const
{
    return true;
}

QString ROADoverWAVECoderPlugin::name() const
{
    return QString("ROADoverWAVE");
}
