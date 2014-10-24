#ifndef ROADOVERCODEROPTIONS_H
#define ROADOVERCODEROPTIONS_H


#include "listitem_global.h"

#include "interfaces.h"

class LISTITEMSHARED_EXPORT ROADoverCoderOptions: public IROADoverCoderOptions
{
public:




    ROADoverCoderOptions();



    ROADoverCoderOptions(TypeROADFormat typeROADFormat,
                         quint32 superFrameLength,
                         quint32 minSampleLengthRang,
                         quint32 relativeDomainShift,
                         TypeMixingChannelsMode typeMixingChannelsMode,
                         double aSilenceThreshold,
                         double aRangThreshold);

    TypeROADFormat getTypeROADFormat();

    quint32 getFrameSampleLength();

    quint32 getSuperFrameLength();

    quint32 getMaxSampleLengthRang();

    quint32 getMinSampleLengthRang();

    quint32 getRelativeDomainShift();

    TypeMixingChannelsMode getTypeMixingChannelsMode();

    double getSilenceThreshold();

    double getRangThreshold();

private:


    TypeROADFormat _typeROADFormat;

    quint32 _frameSampleLength;

    quint32 _superFrameLength;

    quint32 _maxSampleLengthRang;

    quint32 _minSampleLengthRang;

    quint32 _relativeDomainShift;

    TypeMixingChannelsMode _typeMixingChannelsMode;

    double _silenceThreshold;

    double _rangThreshold;
};

#endif // ROADOVERCODEROPTIONS_H
