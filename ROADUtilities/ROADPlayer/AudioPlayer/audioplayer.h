#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QObject>
#include <QAudioDeviceInfo>

class WaveFractalReader;
class QAudioOutput;


namespace proxy {

template<typename T>
class optional
{
public:

    optional()
        : m_initialized(false)
    {

    }

    bool is_initialized() const { return m_initialized ; }

    bool operator!() const noexcept { return !this->is_initialized() ; }

    optional& operator= ( T val )
      {
        m_initialized = true;

        value_type = val;

        return *this ;
      }

    T operator *() &
    {
        return value_type ;
    }

private:

    bool m_initialized;

    T value_type;

};

}

struct FractalInfo
{
    unsigned int _originalBitsPerSample;

    unsigned int _originalSamplesPerRang;

    FractalInfo()
        : _originalBitsPerSample(0),
          _originalSamplesPerRang(0)
    {}
};

class AudioPlayer : public QObject
{
    Q_OBJECT
public:
    explicit AudioPlayer(QObject *parent = 0);

    virtual ~AudioPlayer();

    void setFilePath(QString filePath, quint32 samplesPerRang, quint32 bitsPerSample, QAudioDeviceInfo device);

    static proxy::optional<FractalInfo> getFractalInfo(QString filePath);

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
