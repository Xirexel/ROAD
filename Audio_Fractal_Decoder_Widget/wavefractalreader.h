#ifndef WAVEFRACTALREADER_H
#define WAVEFRACTALREADER_H

#include <QIODevice>
#include <QAudioFormat>
#include <QFile>
#include <QDataStream>


#include "wavefractal_parser.h"

class IReader;

class WaveFractalReader : public QIODevice
{
    Q_OBJECT
public:
    explicit WaveFractalReader(QString filePath, quint32 samplesPerRange, quint32 bitsPerSample, QObject *parent = 0);

    ~WaveFractalReader();

    void start();
    void stop();

    qint64 readData(char *data, qint64 maxlen);
    qint64 writeData(const char *data, qint64 len);
    qint64 bytesAvailable() const;    
    bool atEnd() const;
    bool seek(qint64 pos);

    QAudioFormat getFormat() const;

    qint64 getSizeOfData();

    qint64 getReadSizeOfData();

    qint64 getSampleAmount();

    qint32 getBitsPerSample();

    qint32 getBlockAlign();

    quint32 getByteRate();

    quint16 getChannels();




private:

    QAudioFormat _format;

    WaveFractalFormatData _waveFractalFormatData;

    bool _ready;

    QFile _file;

    QDataStream _dataStream;

    IReader* _IReader;

    qint64 _sizeOfData;

    qint64 _readSizeOfData;

    qint32 _bitsPerSample;

    qint32 _blockAlign;

    quint32 _byteRate;

    quint16 _channels;



signals:

    void relatedPosition(qreal value);

    void finish();

public slots:

    void setRelatedPosition(qreal value);

private slots:

    void emitSignalPosition(qint64 value);

};

#endif // WAVEFRACTALREADER_H
