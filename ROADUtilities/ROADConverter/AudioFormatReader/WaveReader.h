#ifndef WAVEREADER_H
#define WAVEREADER_H

#include <QFile>
#include <QDataStream>


#include "ireader.h"
#include "../ListItem/interfaces.h"
#include "wave_parser.h"
#include "originalaudiostreamoptions.h"



template<typename T>
class WaveReader : public IReader, public IROADoverRawReader
{
public:
    explicit WaveReader(QString filePath, WaveFormatData aWaveFormatData, QObject *parent = 0)
        : IReader(parent),
          _file(filePath),
          _isWaveFile(false),
          _waveFormatData(aWaveFormatData),
          _readSampleCount(0)
    {
        _isWaveFile = _file.open(QIODevice::ReadOnly);

        _file.seek(aWaveFormatData.getPosition());

        _dataStream.setDevice(&_file);

        _dataStream.setByteOrder(QDataStream::LittleEndian);

        __WAVEFORMAT lwaveformat = aWaveFormatData.getWaveformat();

        if(lwaveformat.format != 1)
            _isWaveFile = false;

        __WAVEDESCRDATA ldescrdata = aWaveFormatData.getWavedescrdata();

        _fullSampleCount = ldescrdata.chunkHead.size / lwaveformat.blockAlign;

        IOriginalAudioStreamOptions::TypeBitePerSample lTypeBitePerSample = IOriginalAudioStreamOptions::S16;

        switch(lwaveformat.bitsPerSample)
        {

        case 8:
            lTypeBitePerSample = IOriginalAudioStreamOptions::U8;
            break;

        case 16:
            lTypeBitePerSample = IOriginalAudioStreamOptions::S16;
            break;

        case 32:
            lTypeBitePerSample = IOriginalAudioStreamOptions::S32;
            break;


        }

        _originalAudioStreamOptions = OriginalAudioStreamOptions(lwaveformat.channels, lwaveformat.sampleRate, lTypeBitePerSample, lwaveformat.bitsPerSample);
    }

    virtual ~WaveReader()
    {
        _file.close();
    }

    virtual void setAtBegin()
    {
        _readSampleCount = 0;

        _file.seek(_waveFormatData.getPosition());
    }

    virtual Result readData(QVarLengthArray<double*> &channelsArray,
                            quint32 superFrameSampleLength)
    {
        Result result = ERROR;

        typeSample lvalue;

        do
        {

            unsigned int count = channelsArray.count();

            unsigned int position = 0;

            for(;
                position < superFrameSampleLength;
                ++position)
            {

                if(_dataStream.atEnd())
                {
                    result = FINISHFILE;

                    break;
                }

                for(unsigned int index = 0;
                    index < count;
                    ++index)
                {
                    _dataStream >> lvalue;

                    double *ptr = channelsArray.at(index);

                    ptr[position] = lvalue;
                }
            }

            _readSampleCount += position;

            if((superFrameSampleLength - position) == 0)
            {
                if(result == ERROR)
                    result = DONE;

            }
            else if(result == FINISHFILE)
            {
                double lDoubleValue = 0.0;

                for(;
                    position < superFrameSampleLength;
                    ++position)
                {

                    for(unsigned int index = 0;
                        index < count;
                        ++index)
                    {
                        double *ptr = channelsArray.at(index);

                        lDoubleValue = ptr[position - 1];

                        ptr[position] = lDoubleValue;
                    }
                }
            }
        }
        while(false);

        return result;
    }

    virtual bool isOpen()
    {
        return _isWaveFile;
    }

    virtual qint32 getPercentOfProcessedFile()
    {
        qint32 result = 0;

        result = (_readSampleCount * 100)/_fullSampleCount;

        return result;
    }

    virtual IROADoverRawReader *getIROADoverRawReader()
    {
        return this;
    }

    virtual IOriginalAudioStreamOptions *getIOriginalAudioStreamOptions()
    {
        return &_originalAudioStreamOptions;
    }

private:

    typedef T typeSample;

    QFile _file;

    QDataStream _dataStream;

    bool _isWaveFile;

    quint32 _readSampleCount;

    qint32 _beginningPosition;

    quint32 _fullSampleCount;

    WaveFormatData _waveFormatData;

    OriginalAudioStreamOptions _originalAudioStreamOptions;

};


#endif // WAVEREADER_H
