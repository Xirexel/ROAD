#ifndef WAVEREADER_H
#define WAVEREADER_H

#include "iwavereader.h"

template<typename T>
class WaveReader : public IWaveReader
{
public:
    explicit WaveReader(QString filePath)
        : IWaveReader(filePath)
    {

    }

    FractalEncoding::ReadResult readData(double* aLeftChannel,
                                         double* aRightChannel,
                                         unsigned int aLength)
    {
        FractalEncoding::ReadResult result = FractalEncoding::ERROR;

        do
        {
            unsigned int readLength = aLength;

            while(readLength > 0)
            {

                typeSample lvalue;

                _dataStream >> lvalue;

                *aLeftChannel = lvalue;

                _dataStream >> lvalue;

                *aRightChannel = lvalue;

                --readLength;

                if(_dataStream.atEnd())
                {
                    result = FractalEncoding::FINISHFILE;

                    break;
                }

                ++aLeftChannel;

                ++aRightChannel;
            }

            _readSampleCount += (aLength - readLength);

            if(readLength == 0)
            {
                if(result == FractalEncoding::ERROR)
                    result = FractalEncoding::DONE;

            }
            else if(result == FractalEncoding::FINISHFILE)
            {
                double lLeftChannelvalue = *aLeftChannel;

                double lRightChannelvalue = *aRightChannel;

                while(readLength > 0)
                {

                    ++aLeftChannel;

                    ++aRightChannel;

                    *aLeftChannel = lLeftChannelvalue;

                    *aRightChannel = lRightChannelvalue;

                    --readLength;
                }
            }
        }
        while(false);

        return result;
    }

private:


    typedef T typeSample;

};
#endif // WAVEREADER_H
