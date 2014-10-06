#include "audiowavefractalplayer.h"
#include "wavefractalreader.h"


#include <QAudioOutput>


AudioWaveFractalPlayer::AudioWaveFractalPlayer(QObject *parent) :
    QObject(parent),
    _reader(nullptr),
    _audioOutput(nullptr),
    _device(QAudioDeviceInfo::defaultOutputDevice()),
    _sampleCount(0)
{
}

AudioWaveFractalPlayer::~AudioWaveFractalPlayer()
{
    releaseSource();
}

void AudioWaveFractalPlayer::setFilePath(QString filePath, quint32 samplePerRange, quint32 bitsPerSample, QAudioDeviceInfo device)
{
    releaseSource();

    _reader = new WaveFractalReader(filePath, samplePerRange, bitsPerSample, this);

    if(!_reader->isOpen())
        return;

    _device = device;

    connect(_reader, SIGNAL(relatedPosition(qreal)), SLOT(emitGetTrackPosition(qreal)));

    connect(_reader, SIGNAL(finish()), SLOT(stop()));

    connect(_reader, SIGNAL(finish()), SIGNAL(finish()));



    _audioOutput = new QAudioOutput(_device, _reader->getFormat(), this);

    _sampleCount = _reader->getSampleAmount();

    emit setRange(0, _sampleCount);
}

void AudioWaveFractalPlayer::releaseSource()
{
    if(_reader != nullptr)
        delete _reader;

    if(_audioOutput != nullptr)
        delete _audioOutput;

    _reader = nullptr;

    _audioOutput = nullptr;
}

QAudio::State AudioWaveFractalPlayer::getState()
{
    if(_audioOutput == nullptr)
        return QAudio::StoppedState;

    return _audioOutput->state();
}

void AudioWaveFractalPlayer::start()
{
    if(_audioOutput != nullptr)
    {
        delete _audioOutput;

        _audioOutput = new QAudioOutput(_device, _reader->getFormat(), this);

        _audioOutput->start(_reader);
    }
}

void AudioWaveFractalPlayer::pause()
{
    if(_audioOutput == nullptr)
        return;

    if(_audioOutput->state() == QAudio::SuspendedState)
        _audioOutput->resume();
    else if(_audioOutput->state() == QAudio::ActiveState)
        _audioOutput->suspend();
    else if(_audioOutput->state() == QAudio::StoppedState)
        start();

}

void AudioWaveFractalPlayer::stop()
{
    if(_audioOutput == nullptr)
        return;

    _audioOutput->reset();

    _audioOutput->stop();

    _audioOutput->reset();

    _reader->setRelatedPosition(0.0);

    emitGetTrackPosition(0.0);

    emit finish();
}

void AudioWaveFractalPlayer::setTrackPosition(int pos)
{
    if(_reader == nullptr)
        return;

    qreal lvalue = static_cast<qreal>(pos) / static_cast<qreal>(_sampleCount);

    _reader->setRelatedPosition(lvalue);

}

void AudioWaveFractalPlayer::emitGetTrackPosition(qreal value)
{
    qreal lvalue = static_cast<qreal>(_sampleCount) * value;

    emit getTrackPosition(lvalue);
}
