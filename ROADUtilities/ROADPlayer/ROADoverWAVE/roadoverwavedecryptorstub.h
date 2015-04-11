#ifndef ROADOVERWAVEDESCRIPTIONSTUB_H
#define ROADOVERWAVEDESCRIPTIONSTUB_H

#include "roadoverwave.h"

template<typename T, typename O>
class ROADoverWAVEDecryptorStub : public ROADoverWAVE<T, O>
{
public:
    ROADoverWAVEDecryptorStub(ROADdecoder::ROADover::IROADoverDecodingOptions* aOptions,
                                WaveFractalFormatData aWaveFractalFormatData,
                                std::string aFilePath)
        : ROADoverWAVE<T, O>(aOptions,
                       aWaveFractalFormatData,
                       aFilePath),
          _preListenSamplesLength(ROADoverWAVE<T, O>::getSuperframeLength() * ROADoverWAVE<T, O>::getFrameRangLength()),
          _preListeningIndexTemplate(128)
    {

    }


protected:

    virtual int readROADdata(unsigned char* aData, ROADUInt32 aCRC32)
    {
        int result = 0;

        for(decltype(_preListenSamplesLength) lindex = 0;
            lindex < _preListenSamplesLength;
            ++lindex)
        {
            *aData = this->_preListeningIndexTemplate;

            ++aData;
        }

        result = _preListenSamplesLength;

        return result;
    }

private:

    unsigned int _preListenSamplesLength;

    unsigned char _preListeningIndexTemplate;

};

#endif // ROADOVERWAVEDESCRIPTIONSTUB_H
