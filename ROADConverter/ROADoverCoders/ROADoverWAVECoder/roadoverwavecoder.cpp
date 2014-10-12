#include "roadoverwavecoder.h"


ROADoverWAVECoder::ROADoverWAVECoder(ROADoverEncoding::ROADoverEncodingOptions aOptions)
    :ROADoverEncoding::AROADover(aOptions)
{
}


ROADoverEncoding::Result ROADoverWAVECoder::readRawData(ROADoverEncoding::IRawDataBuffer* aBuffer)
{
    ROADoverEncoding::Result result = ROADoverEncoding::ERROR;

    return result;
}

unsigned int ROADoverWAVECoder::convertDoubleArrayToByteArray(double* aDoubleData, unsigned int aLength, char* aByteData)
{
    unsigned int result = 0;

    return result;
}

void ROADoverWAVECoder::writePrelistening(double* aData, unsigned int aLength)
{

}
void ROADoverWAVECoder::writeROADdata(char* aData, unsigned int aLength, unsigned int aPrelisteningCRC, unsigned int aROADdataCRC)
{
}
