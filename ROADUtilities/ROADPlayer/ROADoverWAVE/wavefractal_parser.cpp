#include "wavefractal_parser.h"
#include "ROADoverDecodingOptionsFactory.h"
#include "DataDriver.h"

#include <QDebug>

WaveFractal_parser::WaveFractal_parser()
{
}

WaveFractal_parser::~WaveFractal_parser()
{
}

proxy::optional<WaveFractalFormatData> WaveFractal_parser::parse(FILE * pFile)
{
    proxy::optional<WaveFractalFormatData> result;

    do
    {
        auto lWaveDescr = parseWaveDescr(pFile);

        if(!lWaveDescr)
            break;

        __WAVEDESCRDATA lWAVEDESCRDATA;

        __WAVEFORMAT lWAVEFORMAT;

        __WAVECHUNKHEAD lHead;

        int ldataPos = 12;

        __FRACDESCR lfractDescr;

        __FRACMAP lfractMap;

        __FRACDESCRINDECES lfractDescrIndeces;

        int lfractalMapPos = -1;

        int lfractDescrIndecesPos = -1;

        while(!feof(pFile))
        {
            fseek(pFile, ldataPos, SEEK_SET);

            fread(lHead.id, 1, sizeof(lHead.id), pFile);

            ldataPos += 4;

            fseek(pFile, ldataPos, SEEK_SET);

            fread(&lHead.size, 1, sizeof(lHead.size), pFile);

            ldataPos += 4;

            fseek(pFile, ldataPos, SEEK_SET);

            if(lHead.id[0] == 'f'
                    && lHead.id[1] == 'm'
                    && lHead.id[2] == 't'
                    && lHead.id[3] == ' ')
            {
                auto lWaveFormat = parseWaveFormat(pFile, lHead);

                if(!lWaveFormat)
                    break;

                lWAVEFORMAT = *lWaveFormat;

            }
            else if(lHead.id[0] == 'd'
                        && lHead.id[1] == 'a'
                        && lHead.id[2] == 't'
                        && lHead.id[3] == 'a')
            {
                lWAVEDESCRDATA.chunkHead = lHead;

                break;
            }

            ldataPos += lHead.size;

            fseek(pFile, ldataPos, SEEK_SET);

        }

        int lpos = ldataPos + lHead.size;

        fseek(pFile, lpos, SEEK_SET);


        if(feof(pFile))
        {
            result = WaveFractalFormatData(*lWaveDescr, lWAVEFORMAT,
                                             lWAVEDESCRDATA, ldataPos);

            fseek(pFile, ldataPos, SEEK_SET);

            break;
        }

        fread(lfractDescr._chunkHead.id, 1, sizeof(lfractDescr._chunkHead.id),pFile);

        ROADdecoder::ROADover::IROADoverDecodingOptions *lIROADoverDecodingOptions = nullptr;

        switch(lfractDescr.check())
        {
            case __FRACDESCR::MAIN:
                lIROADoverDecodingOptions = parsMainFormat(pFile, lpos, lfractDescr);
            break;
            case __FRACDESCR::EXPEREMENTAL:
                lIROADoverDecodingOptions = parsExperementalFormat(pFile, lpos, lfractDescr);
            break;
            case __FRACDESCR::ERROR:
            default:
                lIROADoverDecodingOptions = nullptr;
            break;

        }

        if(lIROADoverDecodingOptions == nullptr)
            break;

//        lpos += 4;

//        fseek(pFile, lpos, SEEK_SET);

//        fread(&lfractDescr._chunkHead.size, 1, sizeof(lfractDescr._chunkHead.size),pFile);

//        lpos += 4;

//        fseek(pFile, lpos, SEEK_SET);

//        std::unique_ptr<unsigned char> lformatData(new unsigned char[lfractDescr._chunkHead.size]);

//        fread(lformatData.get(), lfractDescr._chunkHead.size, 1, pFile);

//        lpos += lfractDescr._chunkHead.size;

//        fseek(pFile, lpos, SEEK_SET);

//        auto lptrIDataReadDriver = ROADdecoder::Driver::DataDriver::getIDataReadDriver(lformatData, lfractDescr._chunkHead.size, Endian::LITTLE);

//        auto lIROADoverDecodingOptions = ROADdecoder::ROADover::ROADoverDecodingOptionsFactory::getIROADoverDecodingOptions(lptrIDataReadDriver);

        lfractDescr._format = lIROADoverDecodingOptions;

        if(feof(pFile))
            break;

        fread(lfractMap._chunkHead.id, 1, sizeof(lfractMap._chunkHead.id),pFile);

        lpos += 4;

        fseek(pFile, lpos, SEEK_SET);

        if(!lfractMap.check())
        {
            break;
        }

        fread(&lfractMap._chunkHead.size, 1, sizeof(lfractMap._chunkHead.size),pFile);

        lpos += 4;

        fseek(pFile, lpos, SEEK_SET);


        lfractalMapPos = lpos;

        lpos += lfractMap._chunkHead.size;

        fseek(pFile, lpos, SEEK_SET);

        fread(lfractDescrIndeces._chunkHead.id, 1, sizeof(lfractDescrIndeces._chunkHead.id),pFile);

        lpos += 4;

        fseek(pFile, lpos, SEEK_SET);

        if(!lfractDescrIndeces.check())
        {
            break;
        }



        fread(&lfractDescrIndeces._chunkHead.size, 1, sizeof(lfractDescrIndeces._chunkHead.size),pFile);

        lpos += 4;

        fseek(pFile, lpos, SEEK_SET);

        lfractDescrIndecesPos = lpos;

        result = WaveFractalFormatData(*lWaveDescr, lWAVEFORMAT,
                                       lWAVEDESCRDATA, ldataPos, lfractDescr,
                                       lfractMap, lfractDescrIndeces,
                                       lfractalMapPos, lfractDescrIndecesPos);

    }
    while(false);

    return result;
}

ROADdecoder::ROADover::IROADoverDecodingOptions *WaveFractal_parser::parsMainFormat(FILE * pFile, int &aPos, __FRACDESCR lfractDescr)
{
    ROADdecoder::ROADover::IROADoverDecodingOptions *result;

    do
    {

    }
    while(false);

    return result;
}

ROADdecoder::ROADover::IROADoverDecodingOptions * WaveFractal_parser::parsExperementalFormat(FILE * pFile, int &aPos, __FRACDESCR lfractDescr)
{
    ROADdecoder::ROADover::IROADoverDecodingOptions * result;

    do
    {

        aPos += 4;

        fseek(pFile, aPos, SEEK_SET);

        fread(&lfractDescr._chunkHead.size, 1, sizeof(lfractDescr._chunkHead.size),pFile);

        aPos += 4;

        fseek(pFile, aPos, SEEK_SET);

        std::unique_ptr<unsigned char> lformatData(new unsigned char[lfractDescr._chunkHead.size]);

        fread(lformatData.get(), lfractDescr._chunkHead.size, 1, pFile);

        aPos += lfractDescr._chunkHead.size;

        fseek(pFile, aPos, SEEK_SET);

        auto lptrIDataReadDriver = ROADdecoder::Driver::DataDriver::getIDataReadDriver(lformatData, lfractDescr._chunkHead.size, Endian::LITTLE);

        result = ROADdecoder::ROADover::ROADoverDecodingOptionsFactory::getIROADoverDecodingOptions(lptrIDataReadDriver);

    }
    while(false);

    return result;
}

WaveFractal_parser &WaveFractal_parser::getInstance()
{
    static WaveFractal_parser instance;

    return instance;
}

proxy::optional<__WAVEDESCR> WaveFractal_parser::parseWaveDescr(FILE *pFile)
{
    proxy::optional<__WAVEDESCR> result;

    do
    {
        __WAVEDESCR lWaveDescr;

        int length = fread(lWaveDescr.chunkHead.id, 1, sizeof(lWaveDescr.chunkHead.id),pFile);


        if(length != sizeof(lWaveDescr.chunkHead.id))
            break;

        length = fread(&lWaveDescr.chunkHead.size, 1, sizeof(lWaveDescr.chunkHead.size),pFile);

        if(length != sizeof(lWaveDescr.chunkHead.size))
            break;

        length = fread(lWaveDescr.wave, 1, sizeof(lWaveDescr.wave),pFile);

        if(length != sizeof(lWaveDescr.wave))
            break;

        if(!lWaveDescr.check())
            break;

        result = lWaveDescr;
    }
    while(false);

    return result;
}

proxy::optional<__WAVEFORMAT> WaveFractal_parser::parseWaveFormat(FILE *pFile, __WAVECHUNKHEAD aHead)
{
    proxy::optional<__WAVEFORMAT> result;

    do
    {
        __WAVEFORMAT lwavedescr;

        fread(&lwavedescr.format, 1, sizeof(lwavedescr.format),pFile);

        fread(&lwavedescr.channels, 1, sizeof(lwavedescr.channels),pFile);

        fread(&lwavedescr.sampleRate, 1, sizeof(lwavedescr.sampleRate),pFile);

        fread(&lwavedescr.byteRate, 1, sizeof(lwavedescr.byteRate),pFile);

        fread(&lwavedescr.blockAlign, 1, sizeof(lwavedescr.blockAlign),pFile);

        fread(&lwavedescr.bitsPerSample, 1, sizeof(lwavedescr.bitsPerSample),pFile);

        lwavedescr.chunkHead = aHead;

        int shift = aHead.size - 16;

        fseek(pFile, shift, SEEK_CUR);

        result = lwavedescr;
    }
    while(false);

    return result;
}
