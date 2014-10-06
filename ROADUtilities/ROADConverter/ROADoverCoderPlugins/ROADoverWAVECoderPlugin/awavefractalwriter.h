#ifndef AWAVEFRACTALWRITER_H
#define AWAVEFRACTALWRITER_H


#include <QDataStream>
#include <QFile>
#include <QTemporaryFile>


#include "fractalchanks.h"


class AWaveFractalWriter
{
public:
    AWaveFractalWriter(QString aFilePath,
                       __WAVEDESCR aWaveDesc,
                       __WAVEFORMAT awaveformat,
                       __WAVEDESCRDATA aWaveData);

    virtual ~AWaveFractalWriter();

    void flushAndCloseFile(const char *aByteData, int aLength);

    void reject();

    virtual unsigned int convertDoubleArrayToByteArray(const double* aDoubleData, unsigned int aLength, unsigned char*  aByteData) = 0;

    virtual void writePrelistening(double* aDoubleData, unsigned int aLength) = 0;

    virtual void writeROADdata(unsigned char* aData, unsigned int aLength);


protected:

    QFile _QFile;

    QTemporaryFile _tempFractalMapFile;

    QTemporaryFile _tempFractalDataFile;

    QDataStream _dataStream;

    QDataStream _fractalMapStream;

    QDataStream _fractalDataStream;

    bool _isOpen;

    quint32 _averLength;

    __WAVEDESCR _waveDesc;

    __WAVEFORMAT _waveformat;

    __WAVEDESCRDATA _waveData;

    __FRACMAP _fractalMap;

    __FRACDESCRINDECES _fractalIndeces;

private:

    void writeHead();

    void writeFractInfo(const char *aByteData, int aLength);

    void closeFiles();
};

#endif // AWAVEFRACTALWRITER_H
