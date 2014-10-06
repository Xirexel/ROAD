#include "wavefractal_parser.h"

WaveFractal_parser::WaveFractal_parser()
{
}

WaveFractal_parser::~WaveFractal_parser()
{
}

std::tuple<bool, WaveFractalFormatData> WaveFractal_parser::parse(QDataStream &dataStream)
{
    bool result = false;

    WaveFractalFormatData lWaveFractalFormatData;

    dataStream.setByteOrder(QDataStream::LittleEndian);

    do
    {
        auto lWaveDescr = parseWaveDescr(dataStream);

        if(!std::get<0>(lWaveDescr))
            break;

        __WAVEDESCRDATA lWAVEDESCRDATA;

        __WAVEFORMAT lWAVEFORMAT;

        __WAVECHUNKHEAD lHead;

        qint64 ldataPos = -1;

        qint64 lfractalMapPos = -1;

        qint64 lfractDescrIndecesPos = -1;

        __FRACDESCR lfractDescr;

        __FRACMAP lfractMap;

        __FRACDESCRINDECES lfractDescrIndeces;

        while(!dataStream.atEnd())
        {


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

                ldataPos = dataStream.device()->pos();

                break;
            }
            else
                dataStream.skipRawData(lHead.size-1);

        }

        if(!result)
            break;

        qint64 lpos = dataStream.device()->pos();

        dataStream.skipRawData(lHead.size);

        if(dataStream.atEnd())
        {

            lWaveFractalFormatData = WaveFractalFormatData(std::get<1>(lWaveDescr), lWAVEFORMAT,
                                             lWAVEDESCRDATA, ldataPos);

            dataStream.device()->seek(lpos);

            break;
        }

        result = false;

        qint64 l = lpos + lHead.size - 1;

        dataStream.device()->seek(lpos + lHead.size - 1);

        int length = dataStream.readRawData((char *)lfractDescr._chunkHead.id,
                                            sizeof(lfractDescr._chunkHead.id));

        if(length != sizeof(lfractDescr._chunkHead.id))
            break;

        __FRACDESCR ltest__FRACDESCR;

        if(!(lfractDescr == ltest__FRACDESCR))
        {
            break;
        }

        dataStream >> lfractDescr._chunkHead.size;

        if(lfractDescr._chunkHead.size != sizeof(__FRACFORMAT))
            break;

        dataStream >> lfractDescr._format._format;

        dataStream >> lfractDescr._format._superFrameLength;

        dataStream >> lfractDescr._format._frameRangeLength;

        dataStream >> lfractDescr._format._domainShift;

        dataStream >> lfractDescr._format._domainShiftScale;

        dataStream >> lfractDescr._format._originalAmountOfChannels;

        dataStream >> lfractDescr._format._averDiffMode;

        dataStream >> lfractDescr._format._encriptionCode;


        if(dataStream.atEnd())
            break;


        length = dataStream.readRawData((char *)lfractMap._chunkHead.id,
                                                    sizeof(lfractMap._chunkHead.id));

        if(length != sizeof(lfractMap._chunkHead.id))
                break;


        __FRACMAP ltemp__FRACMAP;

        if(!(lfractMap == ltemp__FRACMAP))
        {
            break;
        }

        dataStream >> lfractMap._chunkHead.size;

        lfractalMapPos = dataStream.device()->pos();

        dataStream.skipRawData(lfractMap._chunkHead.size);


        if(dataStream.atEnd())
            break;


        length = dataStream.readRawData((char *)lfractDescrIndeces._chunkHead.id,
                                                    sizeof(lfractDescrIndeces._chunkHead.id));

        if(length != sizeof(lfractDescrIndeces._chunkHead.id))
                break;


        __FRACDESCRINDECES ltemp__FRACDESCRINDECES;

        if(!(lfractDescrIndeces == ltemp__FRACDESCRINDECES))
        {
            break;
        }

        dataStream >> lfractDescrIndeces._chunkHead.size;

        lfractDescrIndecesPos = dataStream.device()->pos();

        length = dataStream.skipRawData(lfractDescrIndeces._chunkHead.size);


        if(length != lfractDescrIndeces._chunkHead.size)
            break;

        result = true;

        if(result)
            lWaveFractalFormatData = WaveFractalFormatData(std::get<1>(lWaveDescr), lWAVEFORMAT,
                                                           lWAVEDESCRDATA, ldataPos, lfractDescr,
                                                           lfractMap, lfractDescrIndeces,
                                                           lfractalMapPos, lfractDescrIndecesPos);

    }
    while(false);

    return std::make_tuple(result, lWaveFractalFormatData);
}

WaveFractal_parser &WaveFractal_parser::getInstance()
{
    static WaveFractal_parser instance;

    return instance;
}

std::tuple<bool, __WAVEDESCR> WaveFractal_parser::parseWaveDescr(QDataStream &dataStream)
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

std::tuple<bool, __WAVEFORMAT> WaveFractal_parser::parseWaveFormat(__WAVECHUNKHEAD aHead, QDataStream &dataStream)
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
