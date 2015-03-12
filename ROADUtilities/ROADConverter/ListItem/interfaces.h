#ifndef INTERFACES_H
#define INTERFACES_H

#include <QtPlugin>
#include <QVarLengthArray>

#include "../../../ROADcodec/ROADcoder/ROADoverCoder/IROADoverEncodingOptions.h"



enum Result{
    ERROR,
    DONE,
    FINISHFILE
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

    virtual quint32 getBPS() = 0;

protected:

    quint32 _amountOfChannels;

    quint32 _frequency;

    TypeBitePerSample _typeBitePerSample;

    quint32 _bps;

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

    virtual void flushAndCloseFile() = 0;

    virtual void reject() = 0;
};

class IROADoverCoderPlugin
{
public:
    virtual ~IROADoverCoderPlugin() {}

    virtual IROADoverCoder* createIROADoverCoder(IROADoverRawReader* ptrReader,
                                                 std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions>
                                                 &aIROADoverCoderOptions,
                                                 IOriginalAudioStreamOptions *aOriginalAudioStreamOptions,
                                                 QString outputFile) = 0;

    virtual bool checkPlugin() const = 0;

    virtual QString name() const = 0;

    virtual QWidget *getOptionsWidget() = 0;
};

#define IROADoverCoderPlugin_iid "ROADConvertor.IROADoverCoderPlugin"

Q_DECLARE_INTERFACE(IROADoverCoderPlugin, IROADoverCoderPlugin_iid)

#endif // INTERFACES_H
