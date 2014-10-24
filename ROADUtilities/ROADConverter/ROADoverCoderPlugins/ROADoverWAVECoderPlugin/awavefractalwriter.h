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
                       __WAVEDESCRDATA aWaveData,
                       __FRACDESCR aFractalFormat);

    virtual ~AWaveFractalWriter();

    void flushAndCloseFile();

    void reject();

    virtual unsigned int convertDoubleArrayToByteArray(double* aDoubleData, unsigned int aLength, char* aByteData) = 0;

    virtual void writePrelistening(double* aData, unsigned int aLength) = 0;

    virtual void writeROADdata(char* aData, unsigned int aLength, unsigned int aPrelisteningCRC, unsigned int aROADdataCRC);


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

    __FRACDESCR _fractalFormat;

    __FRACMAP _fractalMap;

    __FRACDESCRINDECES _fractalIndeces;

private:

    void writeHead();

    void writeFractInfo();

    void closeFiles();
};

#endif // AWAVEFRACTALWRITER_H
