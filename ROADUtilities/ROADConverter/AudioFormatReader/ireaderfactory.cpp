#include "ireaderfactory.h"
#include "wave_parser.h"
#include "WaveReader.h"


IReaderFactory::IReaderFactory()
{
}

IReaderFactory &IReaderFactory::getInstance()
{
    static IReaderFactory instance;

    return instance;
}

IReaderFactory::~IReaderFactory()
{

}

std::tuple<bool, IReader* > IReaderFactory::getIReader(QString aFilePath, TypeAudioFile aTypeAudioFile)
{
    bool result = false;

    IReader *lptrIReader = nullptr;

    switch(aTypeAudioFile)
    {
    case WAVE:

        lptrIReader = getWaveReader(aFilePath);

        result = true;
    case NONE:
        break;

    }

    return std::make_tuple(result, lptrIReader);
}

IReader *IReaderFactory::getWaveReader(QString aFilePath)
{
    IReader * result = nullptr;

    do
    {
        QFile file(aFilePath);

        file.open(QIODevice::ReadOnly);

        if(!file.isOpen())
            break;

        QDataStream dataStream(&file);

        auto resultParse = Wave_parser::getInstance().parse(dataStream);

        file.close();

        if(std::get<0>(resultParse))
        {
            WaveFormatData lWaveFormatData = std::get<1>(resultParse);

            quint16 lBPS = lWaveFormatData.getWaveformat().bitsPerSample;

            switch(lBPS)
            {
            case 8:
                result = new WaveReader<quint8>(aFilePath, lWaveFormatData);
                break;

            case 16:
                result = new WaveReader<qint16>(aFilePath, lWaveFormatData);
                break;

            case 32:
                result = new WaveReader<qint32>(aFilePath, lWaveFormatData);
                break;
            }
        }
    }
    while(false);


    return result;
}
