#ifndef INTERFACES_H
#define INTERFACES_H

#include <QtPlugin>
#include <QVarLengthArray>





enum Result{
    ERROR,
    DONE,
    FINISHFILE
};

class IROADoverCoderOptions
{
public:

    enum TypeROADFormat
    {
        EXPEREMENTAL
    };

    enum TypeMixingChannelsMode
    {
        L_PLUS_R,
        L_MINUS_R,
        NONE
    };


    virtual TypeROADFormat getTypeROADFormat() = 0;

    virtual quint32 getFrameSampleLength() = 0;

    virtual quint32 getSuperFrameLength() = 0;

    virtual quint32 getMaxSampleLengthRang() = 0;

    virtual quint32 getMinSampleLengthRang() = 0;

    virtual quint32 getRelativeDomainShift() = 0;

    virtual TypeMixingChannelsMode getTypeMixingChannelsMode() = 0;

};

class IOriginalAudioStreamOptions
{
public:

    enum TypeBitePerSample
    {
        U8,
        S16,
        S32
    };

public:

    virtual quint32 getAmountOfChannels() = 0;

    virtual quint32 getFrequency() = 0;

    virtual TypeBitePerSample getTypeBitePerSample() = 0;

private:

    quint32 _amountOfChannels;

    quint32 _frequency;

    TypeBitePerSample _typeBitePerSample;

};

class IROADoverRawReader
{
public:
    virtual ~IROADoverRawReader() {}

    virtual Result readData(QVarLengthArray<double*> &channelsArray,
                            quint32 superFrameSampleLength) = 0;

};

class IROADoverCoder
{
public:
    virtual ~IROADoverCoder() {}

    virtual Result doEncoding() = 0;
};

class IROADoverCoderPlugin
{
public:
    virtual ~IROADoverCoderPlugin() {}

    virtual IROADoverCoder* createIROADoverCoder(IROADoverRawReader* ptrReader,
                                                 IROADoverCoderOptions *aIROADoverCoderOptions,
                                                 IOriginalAudioStreamOptions *
                                                 aOriginalAudioStreamOptions,
                                                 QString outputFile) = 0;

    virtual bool checkPlugin() const = 0;

    virtual QString name() const = 0;
};

#define IROADoverCoderPlugin_iid "ROADConvertor.IROADoverCoderPlugin"

Q_DECLARE_INTERFACE(IROADoverCoderPlugin, IROADoverCoderPlugin_iid)

#endif // INTERFACES_H
