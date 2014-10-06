#ifndef ROADOVERWAVECODER_H
#define ROADOVERWAVECODER_H

#include <memory>


#include "roadoverwavecoder_global.h"
#include "../../ListItem/interfaces.h"
#include "awavefractalwriter.h"
#include "ROADover.h"
#include "RawDataBuffer.h"
#include "Result.h"




class ROADOVERWAVECODERSHARED_EXPORT ROADoverWAVECoder: public ROADcoder::ROADoverCoder::ROADover, public IROADoverCoder
{

public:
    ROADoverWAVECoder(QString outputFile, IROADoverRawReader* aPtrReader, IOriginalAudioStreamOptions *aOriginalAudioStreamOptions, std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> &aOptions);

// Methods of IROADoverCoder

    virtual Result doEncoding();

    virtual void flushAndCloseFile();

    virtual void reject();


// Methods of ROADcoder::ROADoverCoder::ROADover

    virtual bool lockResource();

    virtual bool unlockResource();

    virtual ROADcoder::ROADoverCoder::Result readRawData(ROADcoder::ROADoverCoder::RawDataBuffer &aRawDataBuffer);

    virtual unsigned int convertDoubleArrayIntoByteArray(const double* aDoubleData, unsigned int aLengthDoubleArray, unsigned char* aByteData);

    virtual void writePreListening(double *aDoubleData, unsigned int aLength);

    virtual void writeROADdata(unsigned char* aByteData, unsigned int aLength);

private:

    IROADoverRawReader* ptrReader;

    QVarLengthArray<double*> temp;

    std::unique_ptr<AWaveFractalWriter> _unique_ptrAWaveFractalWriter;



    void writeHead();

    void writeFractInfo();

    void closeFiles();
};

#endif // ROADOVERWAVECODER_H
