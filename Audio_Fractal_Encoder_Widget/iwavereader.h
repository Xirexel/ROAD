#ifndef IWAVEREADER_H
#define IWAVEREADER_H

#include <QFile>
#include <QDataStream>

#include "IRawDataReader.h"

class IWaveReader: public FractalEncoding::IRawDataReader
{
public:
    IWaveReader(QString filePath);

    virtual ~IWaveReader();

    qint32 getPercentOfProcessedFile();

    bool isOpen();

protected:

    QFile _file;

    QDataStream _dataStream;

    bool _isWaveFile;

    quint32 _readSampleCount;

    quint32 _fullSampleCount;
};

#endif // IWAVEREADER_H
