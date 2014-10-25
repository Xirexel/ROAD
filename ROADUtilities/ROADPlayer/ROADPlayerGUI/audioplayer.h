#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QObject>
#include <QAudioDeviceInfo>

class WaveFractalReader;
class QAudioOutput;

class AudioPlayer : public QObject
{
    Q_OBJECT
public:
    explicit AudioPlayer(QObject *parent = 0);

    virtual ~AudioPlayer();

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

#endif // AUDIOPLAYER_H
