#include "wavefractal_parser.h"
#include "ROADoverDecodingOptionsFactory.h"


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

        int ldataPos = -1;

        int lfractalMapPos = -1;

        int lfractDescrIndecesPos = -1;

        __FRACDESCR lfractDescr;

        __FRACMAP lfractMap;

        __FRACDESCRINDECES lfractDescrIndeces;

        while(!feof(pFile))
        {

            fread(lHead.id, 1, sizeof(lHead.id), pFile);

            fread(&lHead.size, 1, sizeof(lHead.size), pFile);

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

                ldataPos = ftell(pFile);

                break;
            }
            else
                fseek(pFile, lHead.size-1, SEEK_CUR);

        }

        int lpos = ftell(pFile);

        fseek(pFile, lHead.size, SEEK_CUR);


        if(feof(pFile))
        {
            result = WaveFractalFormatData(*lWaveDescr, lWAVEFORMAT,
                                             lWAVEDESCRDATA, ldataPos);

            fseek(pFile, lpos, SEEK_SET);

            break;
        }

        int lfractalDescrPos = lpos + lHead.size - 1;

        fseek(pFile, lfractalDescrPos, SEEK_SET);

        fread(lfractDescr._chunkHead.id, 1, sizeof(lfractDescr._chunkHead.id),pFile);

        if(!lfractDescr.check())
        {
            break;
        }

        fread(&lfractDescr._chunkHead.size, 1, sizeof(lfractDescr._chunkHead.size),pFile);

//        if(lfractDescr._chunkHead.size != sizeof(ROADdecoder::ROADover::IROADoverDecodingOptions))
//            break;

        std::unique_ptr<unsigned char> lformatData(new unsigned char[lfractDescr._chunkHead.size]);

        fread(lformatData.get(), lfractDescr._chunkHead.size, 1, pFile);

        auto lIROADoverDecodingOptions = ROADdecoder::ROADover::ROADoverDecodingOptionsFactory::getIROADoverDecodingOptions(lformatData.get(), lfractDescr._chunkHead.size);

        lfractDescr._format = lIROADoverDecodingOptions;

        if(feof(pFile))
            break;

        fread(lfractMap._chunkHead.id, 1, sizeof(lfractMap._chunkHead.id),pFile);

        if(!lfractMap.check())
        {
            break;
        }

        fread(&lfractMap._chunkHead.size, 1, sizeof(lfractMap._chunkHead.size),pFile);



        lfractalMapPos = ftell(pFile);

//        stream->seekg(0, std::_S_end);

//        lfractalMapPos = stream->tellg();

//        unsigned int g = lfractMap._chunkHead.size;

        fseek(pFile, lfractMap._chunkHead.size-1, SEEK_CUR);

        fread(lfractDescrIndeces._chunkHead.id, 1, sizeof(lfractDescrIndeces._chunkHead.id),pFile);

        if(!lfractDescrIndeces.check())
        {
            break;
        }


        fread(&lfractDescrIndeces._chunkHead.size, 1, sizeof(lfractDescrIndeces._chunkHead.size),pFile);

        lfractDescrIndecesPos = ftell(pFile);

        result = WaveFractalFormatData(*lWaveDescr, lWAVEFORMAT,
                                       lWAVEDESCRDATA, ldataPos, lfractDescr,
                                       lfractMap, lfractDescrIndeces,
                                       lfractalMapPos, lfractDescrIndecesPos);

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

        int length = fread(&lwavedescr.format, 1, sizeof(lwavedescr.format),pFile);

        length = fread(&lwavedescr.channels, 1, sizeof(lwavedescr.channels),pFile);

        length = fread(&lwavedescr.sampleRate, 1, sizeof(lwavedescr.sampleRate),pFile);

        length = fread(&lwavedescr.byteRate, 1, sizeof(lwavedescr.byteRate),pFile);

        length = fread(&lwavedescr.blockAlign, 1, sizeof(lwavedescr.blockAlign),pFile);

        length = fread(&lwavedescr.bitsPerSample, 1, sizeof(lwavedescr.bitsPerSample),pFile);

        lwavedescr.chunkHead = aHead;

        int shift = aHead.size - 16;

        fseek(pFile, shift, SEEK_CUR);

        result = lwavedescr;
    }
    while(false);

    return result;
}

//void WaveFractal_parser::parseFractalFormat(FILE *pFile, __FRACDESCR &lfractDescr)
//{
//    int length = fread(&lfractDescr._format._format, 1, sizeof(lfractDescr._format._format),pFile);

//    length = fread(&lfractDescr._format._superFrameLength, 1, sizeof(lfractDescr._format._superFrameLength),pFile);

//    length = fread(&lfractDescr._format._frameRangeLength, 1, sizeof(lfractDescr._format._frameRangeLength),pFile);

//    length = fread(&lfractDescr._format._domainShift, 1, sizeof(lfractDescr._format._domainShift),pFile);

//    length = fread(&lfractDescr._format._domainShiftScale, 1, sizeof(lfractDescr._format._domainShiftScale),pFile);

//    length = fread(&lfractDescr._format._originalAmountOfChannels, 1, sizeof(lfractDescr._format._originalAmountOfChannels),pFile);

//    length = fread(&lfractDescr._format._averDiffMode, 1, sizeof(lfractDescr._format._averDiffMode),pFile);

//    length = fread(&lfractDescr._format._encriptionCode, 1, sizeof(lfractDescr._format._encriptionCode),pFile);
//}
