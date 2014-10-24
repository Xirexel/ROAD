#ifndef ORIGINALAUDIOSTREAMOPTIONS_H
#define ORIGINALAUDIOSTREAMOPTIONS_H

#include "../ListItem/interfaces.h"


class OriginalAudioStreamOptions: public IOriginalAudioStreamOptions
{
public:

    explicit OriginalAudioStreamOptions();

    OriginalAudioStreamOptions(quint32 aAmountOfChannels,
                               quint32 aFrequency,
                               TypeBitePerSample aTypeBitePerSample,
                               quint32 aBPS);

    virtual quint32 getAmountOfChannels();

    virtual quint32 getFrequency();

    virtual TypeBitePerSample getTypeBitePerSample();

    virtual quint32 getBPS();
};

#endif // ORIGINALAUDIOSTREAMOPTIONS_H
