#ifndef ROADOVERWAVECODER_H
#define ROADOVERWAVECODER_H

#include <memory>


#include "roadoverwavecoder_global.h"
#include "../../ListItem/interfaces.h"
#include "awavefractalwriter.h"
#include "ROADover.h"
#include "RawDataBuffer.h"
#include "Result.h"



using namespace PlatformDependencies;

class ROADOVERWAVECODERSHARED_EXPORT ROADoverWAVECoder: public ROADcoder::ROADoverCoder::ROADover, public IROADoverCoder
{

public:
    ROADoverWAVECoder(QString outputFile, IROADoverRawReader* aPtrReader, IOriginalAudioStreamOptions *aOriginalAudioStreamOptions, Unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> &aOptions);

// Methods of IROADoverCoder

    virtual Result doEncoding();

    virtual void flushAndCloseFile();

    virtual void reject();


// Methods of ROADcoder::ROADoverCoder::ROADover

    virtual bool lockResource();

    virtual bool unlockResource();

    virtual ROADcoder::ROADoverCoder::Result readRawData(ROADcoder::ROADoverCoder::RawDataBuffer &aRawDataBuffer);

    virtual unsigned int convertDoubleArrayIntoByteArray(const PtrROADReal aDoubleData, ROADUInt32 aLengthDoubleArray, PtrROADByte aByteData);

    virtual ROADUInt32 writePreListening(double *aDoubleData, unsigned int aLength);

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
