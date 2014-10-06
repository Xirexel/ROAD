#ifndef AUDIOWAVEFRACTALPLAYER_H
#define AUDIOWAVEFRACTALPLAYER_H

#include <QObject>
#include <QAudioDeviceInfo>

class WaveFractalReader;

class QAudioOutput;

class AudioWaveFractalPlayer : public QObject
{
    Q_OBJECT
public:
    explicit AudioWaveFractalPlayer(QObject *parent = 0);

    virtual ~AudioWaveFractalPlayer();

    void setFilePath(QString filePath, quint32 samplePerRange, quint32 bitsPerSample, QAudioDeviceInfo device);

    void releaseSource();

    QAudio::State getState();

private:

    WaveFractalReader* _reader;

    QAudioOutput *_audioOutput;

    QAudioDeviceInfo _device;

    qint64 _sampleCount;

signals:

    void setRange(int min, int max);

    void getTrackPosition(int pos);

    void finish();

public slots:

    void start();

    void stop();

    void pause();

    void setTrackPosition(int pos);

private slots:

    void emitGetTrackPosition(qreal value);

};

#endif // AUDIOWAVEFRACTALPLAYER_H
