#include <QTime>
#include <QFileInfo>
#include <memory>


#include "processingthread.h"
#include "Audio_Fractal_Encoder.h"
#include "wavereader.h"
#include "wavefractalwriter.h"
#include "wave_parser.h"




ProcessingThread::ProcessingThread(QObject *parent) :
    QThread(parent)
{
}

void ProcessingThread::setFractalEncoderOptions(QString waveFilePath,
                                                QString waveFractalFilePath,
                                                FractalOptions fractalOptions)
{
    _waveFilePath = waveFilePath;
    _waveFractalFilePath = waveFractalFilePath;
    _fractalOptions = fractalOptions;
}

void ProcessingThread::run()
{
    FractalEncoding::ReadResult result = FractalEncoding::ERROR;

    QTime time;

    time.start();

    do
    {

        QFileInfo fileinfo(_waveFilePath);

        if(!fileinfo.exists())
            break;

        QFile file(_waveFilePath);

        if(!file.open(QIODevice::ReadOnly))
            return;

        QDataStream dataStream(&file);

        auto parseResult = Wave_parser::getInstance().parse(dataStream);

        file.close();

        if(!std::get<0>(parseResult))
            break;

        WaveFormatData lwaveFormatData = std::get<1>(parseResult);

        std::unique_ptr<IWaveReader> lptrReader;

        std::unique_ptr<IWaveFractalWriter> lptrWriter;



        __WAVEDESCR aWaveDesc = lwaveFormatData.getWavedescr();

        __WAVEFORMAT awaveformat = lwaveFormatData.getWaveformat();

        __WAVEDESCRDATA aWaveData = lwaveFormatData.getWavedescrdata();



        quint32 sampleSize = aWaveData.chunkHead.size / awaveformat.blockAlign;

        quint32 amountFrames = sampleSize / (_fractalOptions._frameSampleLength * _fractalOptions._superFrameLength);

        auto diff = sampleSize % _fractalOptions._frameSampleLength;


        if(diff > 0)
            ++amountFrames;

        sampleSize = amountFrames * (_fractalOptions._frameSampleLength * _fractalOptions._superFrameLength) / _fractalOptions._smallestRangeLength;



        awaveformat.sampleRate = awaveformat.sampleRate /_fractalOptions._smallestRangeLength;

        awaveformat.blockAlign = awaveformat.blockAlign / awaveformat.channels;

        awaveformat.byteRate = awaveformat.sampleRate * awaveformat.blockAlign;

        awaveformat.channels = 1;

        aWaveData.chunkHead.size = sampleSize * awaveformat.blockAlign;

        aWaveDesc.chunkHead.size = 36 + aWaveData.chunkHead.size;





        __FRACDESCR lFractalFormat;

        lFractalFormat._format._format = 0;

        lFractalFormat._format._superFrameLength = _fractalOptions._superFrameLength;

        lFractalFormat._format._frameRangeLength = _fractalOptions._frameSampleLength / _fractalOptions._smallestRangeLength;

        lFractalFormat._format._domainShift = _fractalOptions._relativeDomainShift;

        lFractalFormat._format._domainShiftScale = _fractalOptions._smallestRangeLength;

        lFractalFormat._format._originalAmountOfChannels = 2;

        lFractalFormat._format._averDiffMode = _fractalOptions._mixingChannelMode;

        lFractalFormat._format._encriptionCode = 0;

        lFractalFormat._chunkHead.size = sizeof(lFractalFormat._format);





        FractalEncoding::FractalEncodingOptions options;


        switch(lwaveFormatData.getWaveformat().bitsPerSample)
        {
        case 8:
            lptrReader.reset(new WaveReader<quint8>(_waveFilePath));
            lptrWriter.reset(new WaveFractalWriter<quint8>(_waveFractalFilePath,
                                                           aWaveDesc,
                                                           awaveformat,
                                                           aWaveData,
                                                           lFractalFormat));
            options.setSilenceThreshold(5);

            break;
        case 16:
            lptrReader.reset(new WaveReader<qint16>(_waveFilePath));
            lptrWriter.reset(new WaveFractalWriter<qint16>(_waveFractalFilePath,
                                                           aWaveDesc,
                                                           awaveformat,
                                                           aWaveData,
                                                           lFractalFormat));



            options.setSilenceThreshold(10000);

            break;
        case 32:
            lptrReader.reset(new WaveReader<qint32>(_waveFilePath));
            lptrWriter.reset(new WaveFractalWriter<qint32>(_waveFractalFilePath,
                                                           aWaveDesc,
                                                           awaveformat,
                                                           aWaveData,
                                                           lFractalFormat));

            options.setSilenceThreshold(14167287856893.154);

            break;
        }

        if(!lptrReader || !lptrWriter)
            break;

        if(!lptrReader->isOpen())
            break;



        unsigned int index = log2(static_cast<double>(_fractalOptions._widestRangeLength/_fractalOptions._smallestRangeLength));

        options.setAmountRangeLevels(index);

        options.setDomainShift(_fractalOptions._relativeDomainShift);

        options.setFrameSampleLength(_fractalOptions._frameSampleLength);

        options.setRangeThreshold(10000);

        options.setRangeTopSampleLength(_fractalOptions._widestRangeLength);

        options.setSuperFrameLength(_fractalOptions._superFrameLength);


        FractalEncoding::MixingChannelsMode lMixingChannelsMode = FractalEncoding::LPLUSR;

        switch(_fractalOptions._mixingChannelMode)
        {
        case FractalOptions::LPLUSR:
        default:
            lMixingChannelsMode = FractalEncoding::LPLUSR;
            break;

        case FractalOptions::LMINUSR:
            lMixingChannelsMode = FractalEncoding::LMINUSR;
            break;

        case FractalOptions::NONE:
            lMixingChannelsMode = FractalEncoding::NONE;
            break;

        }

        options.setMixingChannelsMode(lMixingChannelsMode);

        FractalEncoding::Audio_Fractal_Encoder encoder(lptrReader.get(), lptrWriter.get(), options);

        bool isRunning = true;

        while(isRunning)
        {
            result = encoder.doEncoding();

            switch(result)
            {
                case FractalEncoding::ERROR:
                {
                    isRunning = false;
                }
                break;

                case FractalEncoding::DONE:
                break;

            case FractalEncoding::FINISHFILE:
                {
                    isRunning = false;
                }
                break;
            }

            qint32 percent = lptrReader->getPercentOfProcessedFile();

            if(percent < 0)
                break;

            emit progressValue(percent);

            if (QThread::currentThread()->isInterruptionRequested())
            {
                result = FractalEncoding::ERROR;

                break;
            }
        }


        if(result == FractalEncoding::ERROR)
        {
            lptrWriter->reject();
        }
        else
        {
            lptrWriter->flushAndCloseFile();
        }

    }
    while(false);

    float temptime = time.elapsed();

    if(result == FractalEncoding::ERROR)
    {
        temptime = -1.0f;
    }

    emit elapsedTime(temptime);
}

void ProcessingThread::interept()
{
    this->requestInterruption();
}
