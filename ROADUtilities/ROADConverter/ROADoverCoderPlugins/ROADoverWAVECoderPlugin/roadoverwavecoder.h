#ifndef ROADOVERWAVECODER_H
#define ROADOVERWAVECODER_H

#include <memory>


#include "roadoverwavecoder_global.h"
#include "AROADover.h"
#include "../../ListItem/interfaces.h"
#include "awavefractalwriter.h"





class ROADOVERWAVECODERSHARED_EXPORT ROADoverWAVECoder: public ROADoverEncoding::AROADover, public IROADoverCoder
{

public:
    ROADoverWAVECoder(QString outputFile, IROADoverRawReader* aPtrReader, IOriginalAudioStreamOptions *aOriginalAudioStreamOptions, ROADoverEncoding::ROADoverEncodingOptions aOptions);

    virtual Result doEncoding();

    virtual void flushAndCloseFile();

    virtual void reject();

protected: virtual ROADoverEncoding::Result readRawData(ROADoverEncoding::IRawDataBuffer* aBuffer);

protected: virtual unsigned int convertDoubleArrayToByteArray(double* aDoubleData, unsigned int aLength, char* aByteData);

protected: virtual void writePrelistening(double* aData, unsigned int aLength);

protected: virtual void writeROADdata(char* aData, unsigned int aLength, unsigned int aPrelisteningCRC, unsigned int aROADdataCRC);



private:

    IROADoverRawReader* ptrReader;

    quint32 _superFrameSampleLength;

    QVarLengthArray<double*> temp;

    std::unique_ptr<AWaveFractalWriter> _unique_ptrAWaveFractalWriter;



    void writeHead();

    void writeFractInfo();

    void closeFiles();
};

#endif // ROADOVERWAVECODER_H
