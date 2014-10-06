#include "wave_parser.h"

Wave_parser::Wave_parser()
{
}

Wave_parser::~Wave_parser()
{

}

Wave_parser &Wave_parser::getInstance()
{
    static Wave_parser instance;

    return instance;
}

std::tuple<bool, WaveFormatData> Wave_parser::parse(QDataStream &dataStream)
{
    bool result = false;

    WaveFormatData lWaveFormatData;

    dataStream.setByteOrder(QDataStream::LittleEndian);

    do
    {
        auto lWaveDescr = parseWaveDescr(dataStream);

        if(!std::get<0>(lWaveDescr))
            break;

        __WAVEDESCRDATA lWAVEDESCRDATA;

        __WAVEFORMAT lWAVEFORMAT;

        while(!dataStream.atEnd())
        {
            __WAVECHUNKHEAD lHead;

            int length = dataStream.readRawData((char *)lHead.id, sizeof(lHead.id));

            if(length != sizeof(lHead.id))
                break;

            dataStream >> lHead.size;

            if(lHead.id[0] == 'f'
                    && lHead.id[1] == 'm'
                    && lHead.id[2] == 't'
                    && lHead.id[3] == ' ')
            {
                auto lWaveFormat = parseWaveFormat(lHead, dataStream);

                if(!std::get<0>(lWaveFormat))
                    break;

                lWAVEFORMAT = std::get<1>(lWaveFormat);

            }
            else if(lHead.id[0] == 'd'
                        && lHead.id[1] == 'a'
                        && lHead.id[2] == 't'
                        && lHead.id[3] == 'a')
            {
                result = true;

                lWAVEDESCRDATA.chunkHead = lHead;

                break;
            }
            else
                dataStream.skipRawData(lHead.size);

        }

        if(result)
            lWaveFormatData = WaveFormatData(std::get<1>(lWaveDescr), lWAVEFORMAT,
                                             lWAVEDESCRDATA);

    }
    while(false);

    return std::make_tuple(result, lWaveFormatData);
}

std::tuple<bool, __WAVEDESCR> Wave_parser::parseWaveDescr(QDataStream &dataStream)
{
    bool result = false;

    __WAVEDESCR lwavedescr;

    do
    {
        int length = dataStream.readRawData((char *)lwavedescr.chunkHead.id, sizeof(lwavedescr.chunkHead.id));

        if(length != sizeof(lwavedescr.chunkHead.id))
            break;

        if(lwavedescr.chunkHead.id[0] != 'R'
                || lwavedescr.chunkHead.id[1] != 'I'
                || lwavedescr.chunkHead.id[2] != 'F'
                || lwavedescr.chunkHead.id[3] != 'F')
            break;

        dataStream >> lwavedescr.chunkHead.size;

        length = dataStream.readRawData((char *)lwavedescr.wave, sizeof(lwavedescr.wave));

        if(length != sizeof(lwavedescr.wave))
            break;

        if(lwavedescr.wave[0] != 'W'
                || lwavedescr.wave[1] != 'A'
                || lwavedescr.wave[2] != 'V'
                || lwavedescr.wave[3] != 'E')
            break;

        result = true;
    }
    while(false);

    return std::make_tuple(result, lwavedescr);
}

std::tuple<bool, __WAVEFORMAT> Wave_parser::parseWaveFormat(__WAVECHUNKHEAD aHead, QDataStream &dataStream)
{
    bool result = false;

    __WAVEFORMAT lwavedescr;

    do
    {

        dataStream >> lwavedescr.format;

        dataStream >> lwavedescr.channels;

        dataStream >> lwavedescr.sampleRate;

        dataStream >> lwavedescr.byteRate;

        dataStream >> lwavedescr.blockAlign;

        dataStream >> lwavedescr.bitsPerSample;

        result = true;

        quint32 shift = aHead.size - 16;

        dataStream.skipRawData(shift);
    }
    while(false);

    lwavedescr.chunkHead = aHead;

    lwavedescr.chunkHead.size = 16;

    return std::make_tuple(result, lwavedescr);
}
