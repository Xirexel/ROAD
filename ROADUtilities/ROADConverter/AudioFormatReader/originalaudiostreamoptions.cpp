#include "originalaudiostreamoptions.h"


OriginalAudioStreamOptions::OriginalAudioStreamOptions()
{

}

OriginalAudioStreamOptions::OriginalAudioStreamOptions(quint32 aAmountOfChannels,
                                                       quint32 aFrequency,
                                                       TypeBitePerSample aTypeBitePerSample,
                                                       quint32 aBPS)
{
    _amountOfChannels = aAmountOfChannels;

    _frequency = aFrequency;

    _typeBitePerSample = aTypeBitePerSample;

    _bps = aBPS;
}

quint32 OriginalAudioStreamOptions::getAmountOfChannels()
{
    return this->_amountOfChannels;
}

quint32 OriginalAudioStreamOptions::getFrequency()
{
    return this->_frequency;
}

OriginalAudioStreamOptions::TypeBitePerSample OriginalAudioStreamOptions::getTypeBitePerSample()
{
    return _typeBitePerSample;
}

quint32 OriginalAudioStreamOptions::getBPS()
{
    return this->_bps;
}
