#include "wavefractal_parser.h"

WaveFractal_parser::WaveFractal_parser()
{
}

WaveFractal_parser::~WaveFractal_parser()
{
}

WaveFractalFormatData WaveFractal_parser::parse(FILE * pFile)
{
    bool result = false;

    WaveFractalFormatData lWaveFractalFormatData;

    do
    {
        __WAVEDESCR lWaveDescr;

        bool lIsWaveDescr = parseWaveDescr(pFile, lWaveDescr);

        if(!lIsWaveDescr)
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
                __WAVEFORMAT lWaveFormat = parseWaveFormat(pFile, lHead);

                if(lWaveFormat.format != 1)
                    break;

                lWAVEFORMAT = lWaveFormat;

            }
            else if(lHead.id[0] == 'd'
                        && lHead.id[1] == 'a'
                        && lHead.id[2] == 't'
                        && lHead.id[3] == 'a')
            {
                result = true;

                lWAVEDESCRDATA.chunkHead = lHead;

                ldataPos = ftell(pFile);

                break;
            }
            else
                fseek(pFile, lHead.size-1, SEEK_CUR);

        }

        if(!result)
            break;

        int lpos = ftell(pFile);

        fseek(pFile, lHead.size, SEEK_CUR);


        if(feof(pFile))
        {

            lWaveFractalFormatData = WaveFractalFormatData(lWaveDescr, lWAVEFORMAT,
                                             lWAVEDESCRDATA, ldataPos);

            fseek(pFile, lpos, SEEK_SET);


            break;
        }

        result = false;

        int l = lpos + lHead.size - 1;

        fseek(pFile, lpos + lHead.size - 1, SEEK_SET);


        fread(lfractDescr._chunkHead.id, 1, sizeof(lfractDescr._chunkHead.id),pFile);


        __FRACDESCR ltest__FRACDESCR;

        if(!(lfractDescr == ltest__FRACDESCR))
        {
            break;
        }

        fread(&lfractDescr._chunkHead.size, 1, sizeof(lfractDescr._chunkHead.size),pFile);

        if(lfractDescr._chunkHead.size != sizeof(__FRACFORMAT))
            break;

        parseFractalFormat(pFile, lfractDescr);

//        (*stream) >> lfractDescr._format._format;

//        (*stream) >> lfractDescr._format._superFrameLength;

//        (*stream) >> lfractDescr._format._frameRangeLength;

//        (*stream) >> lfractDescr._format._domainShift;

//        (*stream) >> lfractDescr._format._domainShiftScale;

//        (*stream) >> lfractDescr._format._originalAmountOfChannels;

//        (*stream) >> lfractDescr._format._averDiffMode;

//        (*stream) >> lfractDescr._format._encriptionCode;


        if(feof(pFile))
            break;


        fread(lfractMap._chunkHead.id, 1, sizeof(lfractMap._chunkHead.id),pFile);


        __FRACMAP ltemp__FRACMAP;

        if(!(lfractMap == ltemp__FRACMAP))
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


        __FRACDESCRINDECES ltemp__FRACDESCRINDECES;

        if(!(lfractDescrIndeces == ltemp__FRACDESCRINDECES))
        {
            break;
        }


        fread(&lfractDescrIndeces._chunkHead.size, 1, sizeof(lfractDescrIndeces._chunkHead.size),pFile);

        lfractDescrIndecesPos = ftell(pFile);


        result = true;

        if(result)
            lWaveFractalFormatData = WaveFractalFormatData(lWaveDescr, lWAVEFORMAT,
                                                           lWAVEDESCRDATA, ldataPos, lfractDescr,
                                                           lfractMap, lfractDescrIndeces,
                                                           lfractalMapPos, lfractDescrIndecesPos);

    }
    while(false);

    return lWaveFractalFormatData;
}

WaveFractal_parser &WaveFractal_parser::getInstance()
{
    static WaveFractal_parser instance;

    return instance;
}

bool WaveFractal_parser::parseWaveDescr(FILE *pFile, __WAVEDESCR &lWaveDescr)
{
    bool result = false;

    do
    {
        int length = fread(lWaveDescr.chunkHead.id, 1, sizeof(lWaveDescr.chunkHead.id),pFile);


        if(length != sizeof(lWaveDescr.chunkHead.id))
            break;

        if(lWaveDescr.chunkHead.id[0] != 'R'
                || lWaveDescr.chunkHead.id[1] != 'I'
                || lWaveDescr.chunkHead.id[2] != 'F'
                || lWaveDescr.chunkHead.id[3] != 'F')
            break;

        length = fread(&lWaveDescr.chunkHead.size, 1, sizeof(lWaveDescr.chunkHead.size),pFile);

        if(length != sizeof(lWaveDescr.chunkHead.id))
            break;

        length = fread(lWaveDescr.wave, 1, sizeof(lWaveDescr.wave),pFile);

        if(length != sizeof(lWaveDescr.chunkHead.id))
            break;

        if(lWaveDescr.wave[0] != 'W'
                || lWaveDescr.wave[1] != 'A'
                || lWaveDescr.wave[2] != 'V'
                || lWaveDescr.wave[3] != 'E')
            break;

        result = true;
    }
    while(false);

    return result;
}

__WAVEFORMAT WaveFractal_parser::parseWaveFormat(FILE *pFile, __WAVECHUNKHEAD aHead)
{
    bool result = false;

    __WAVEFORMAT lwavedescr;

    lwavedescr.format = -1;

    do
    {
        int length = fread(&lwavedescr.format, 1, sizeof(lwavedescr.format),pFile);

        length = fread(&lwavedescr.channels, 1, sizeof(lwavedescr.channels),pFile);

        length = fread(&lwavedescr.sampleRate, 1, sizeof(lwavedescr.sampleRate),pFile);

        length = fread(&lwavedescr.byteRate, 1, sizeof(lwavedescr.byteRate),pFile);

        length = fread(&lwavedescr.blockAlign, 1, sizeof(lwavedescr.blockAlign),pFile);

        length = fread(&lwavedescr.bitsPerSample, 1, sizeof(lwavedescr.bitsPerSample),pFile);


//        (*stream) >> lwavedescr.format;

//        (*stream) >> lwavedescr.channels;

//        (*stream) >> lwavedescr.sampleRate;

//        (*stream) >> lwavedescr.byteRate;

//        (*stream) >> lwavedescr.blockAlign;

//        (*stream) >> lwavedescr.bitsPerSample;

        result = true;

        int shift = aHead.size - 16;

        fseek(pFile, shift, SEEK_CUR);

    }
    while(false);

    lwavedescr.chunkHead = aHead;

    lwavedescr.chunkHead.size = 16;

    return lwavedescr;
}

void WaveFractal_parser::parseFractalFormat(FILE *pFile, __FRACDESCR &lfractDescr)
{
    int length = fread(&lfractDescr._format._format, 1, sizeof(lfractDescr._format._format),pFile);

    length = fread(&lfractDescr._format._superFrameLength, 1, sizeof(lfractDescr._format._superFrameLength),pFile);

    length = fread(&lfractDescr._format._frameRangeLength, 1, sizeof(lfractDescr._format._frameRangeLength),pFile);

    length = fread(&lfractDescr._format._domainShift, 1, sizeof(lfractDescr._format._domainShift),pFile);

    length = fread(&lfractDescr._format._domainShiftScale, 1, sizeof(lfractDescr._format._domainShiftScale),pFile);

    length = fread(&lfractDescr._format._originalAmountOfChannels, 1, sizeof(lfractDescr._format._originalAmountOfChannels),pFile);

    length = fread(&lfractDescr._format._averDiffMode, 1, sizeof(lfractDescr._format._averDiffMode),pFile);

    length = fread(&lfractDescr._format._encriptionCode, 1, sizeof(lfractDescr._format._encriptionCode),pFile);
}
