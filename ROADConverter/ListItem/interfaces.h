#ifndef INTERFACES_H
#define INTERFACES_H

#include <QtPlugin>
#include <QVarLengthArray>

enum Result{
    ERROR,
    DONE,
    FINISHFILE
};

class ROADoverCoderOptions
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



    ROADoverCoderOptions(TypeROADFormat typeROADFormat,
                         quint32 superFrameLength,
                         quint32 minSampleLengthRang,
                         quint32 relativeDomainShift,
                         TypeMixingChannelsMode typeMixingChannelsMode)
        : _typeROADFormat(typeROADFormat),
          _frameSampleLength(2048),
          _superFrameLength(superFrameLength),
          _maxSampleLengthRang(32),
          _minSampleLengthRang(minSampleLengthRang),
          _relativeDomainShift(relativeDomainShift),
          _typeMixingChannelsMode(typeMixingChannelsMode)
    {

    }

    TypeROADFormat getTypeROADFormat();

    quint32 getFrameSampleLength();

    quint32 getSuperFrameLength();

    quint32 getMaxSampleLengthRang();

    quint32 getMinSampleLengthRang();

    quint32 getRelativeDomainShift();

    TypeMixingChannelsMode getTypeMixingChannelsMode();

private:


    TypeROADFormat _typeROADFormat;

    quint32 _frameSampleLength;

    quint32 _superFrameLength;

    quint32 _maxSampleLengthRang;

    quint32 _minSampleLengthRang;

    quint32 _relativeDomainShift;

    TypeMixingChannelsMode _typeMixingChannelsMode;



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
                                                 ROADoverCoderOptions options,
                                                 QString outputFile) = 0;

    virtual bool checkPlugin() const = 0;

    QString name() const = 0;
};

#define IROADoverCoderPlugin_iid "ROADConvertor.IROADoverCoderPlugin"

Q_DECLARE_INTERFACE(IROADoverCoderPlugin, IROADoverCoderPlugin_iid)

#endif

#endif // INTERFACES_H
