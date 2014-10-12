#ifndef MODELOPTIONS_H
#define MODELOPTIONS_H
#include "listitemsmodel_global.h"
#include "interfaces.h"


class LISTITEMSMODELSHARED_EXPORT ModelOptions
{
public:

public:    

    explicit ModelOptions();

    ModelOptions(TypeROADFormat typeROADFormat, quint32 superFrameLength, quint32 minSampleLengthRang, quint32 relativeDomainShift, TypeMixingChannelsMode typeMixingChannelsMode);

    ROADoverCoderOptions getROADoverCoderOptions();

private:

    ROADoverCoderOptions _localROADoverCoderOptions;
};

#endif // MODELOPTIONS_H
