#ifndef IWAVEFRACTALWRITER_H
#define IWAVEFRACTALWRITER_H


#include <QFile>
#include <QTemporaryFile>
#include <QDataStream>

#include "IRawDataWriter.h"
#include "wave_parser.h"
#include "fractalchanks.h"

class IWaveFractalWriter: public FractalEncoding::IRawDataWriter
{
public:
    IWaveFractalWriter(QString aFilePath,
                       __WAVEDESCR aWaveDesc,
                       __WAVEFORMAT awaveformat,
                       __WAVEDESCRDATA aWaveData,
                       __FRACDESCR aFractalFormat);

    virtual ~IWaveFractalWriter();

    void flushAndCloseFile();

    void reject();

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

#endif // IWAVEFRACTALWRITER_H
