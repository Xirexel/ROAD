#ifndef ROADOVERWAVECODER_H
#define ROADOVERWAVECODER_H

#include "roadoverwavecoder_global.h"
#include "AROADover.h"

class ROADOVERWAVECODERSHARED_EXPORT ROADoverWAVECoder: public ROADoverEncoding::AROADover
{

public:
    ROADoverWAVECoder(ROADoverEncoding::ROADoverEncodingOptions aOptions);

protected: virtual ROADoverEncoding::Result readRawData(ROADoverEncoding::IRawDataBuffer* aBuffer);

protected: virtual unsigned int convertDoubleArrayToByteArray(double* aDoubleData, unsigned int aLength, char* aByteData);

protected: virtual void writePrelistening(double* aData, unsigned int aLength);

protected: virtual void writeROADdata(char* aData, unsigned int aLength, unsigned int aPrelisteningCRC, unsigned int aROADdataCRC);
};

#endif // ROADOVERWAVECODER_H
