#include "audioplayer.h"
#include "wavefractalreader.h"
#include "wavefractal_parser.h"

#include <QAudioOutput>

AudioPlayer::AudioPlayer(QObject *parent) :
    QObject(parent),
    _reader(nullptr),
    _audioOutput(nullptr),
    _device(QAudioDeviceInfo::defaultOutputDevice()),
    _sampleCount(0)

{
}

AudioPlayer::~AudioPlayer()
{
    releaseSource();
}

audioplayer::optional<FractalInfo> AudioPlayer::getFractalInfo(QString filePath)
{
    audioplayer::optional<FractalInfo> result;

    FILE * pFile;

    pFile = fopen (filePath.toStdString().c_str() , "r");

    auto lWaveFractalFormatData = WaveFractal_parser::getInstance().parse(pFile);

    fclose(pFile);

    if(!lWaveFractalFormatData)
        return result;

    WaveFractalFormatData _waveFractalFormatData = *lWaveFractalFormatData;

    __WAVEFORMAT lWAVEFORMAT = _waveFractalFormatData.getWaveformat();

    FractalInfo lFractalInfo;

    lFractalInfo._originalBitsPerSample = lWAVEFORMAT.bitsPerSample;

    __FRACDESCR lFractDescr = _waveFractalFormatData.getFracdescr();

    auto lFractalDecdingOptions = lFractDescr._format;

    int ltempFrequency = lFractalDecdingOptions->getOriginalSamplesPerRang() * lWAVEFORMAT.sampleRate;

    int ltempDecFrequency = ltempFrequency / 10;

    int ldiffFrequency = ltempFrequency - ltempDecFrequency * 10;

    int ladditionFrequency = 10 - ldiffFrequency;

    lFractalInfo._originalFrequency = ltempFrequency + ladditionFrequency;

    result = lFractalInfo;

    return result;
}

void AudioPlayer::setFilePath(QString filePath, quint32 scaleOfFrequency, quint32 bitsPerSample, QAudioDeviceInfo device)
{
    releaseSource();

    _reader = new WaveFractalReader(filePath, scaleOfFrequency, bitsPerSample, this);

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

void AudioPlayer::releaseSource()
{
    if(_reader != nullptr)
        _reader->deleteLater();

    if(_audioOutput != nullptr)
        delete _audioOutput;

    _reader = nullptr;

    _audioOutput = nullptr;
}

QAudio::State AudioPlayer::getState()
{
    if(_audioOutput == nullptr)
        return QAudio::StoppedState;

    return _audioOutput->state();
}

void AudioPlayer::start()
{
    if(_audioOutput != nullptr && _reader != nullptr)
    {
        delete _audioOutput;

        _audioOutput = new QAudioOutput(_device, _reader->getFormat(), this);

        _audioOutput->start(_reader);
    }
}

void AudioPlayer::pause()
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

void AudioPlayer::stop()
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

void AudioPlayer::setTrackPosition(int pos)
{
    if(_reader == nullptr)
        return;

    qreal lvalue = static_cast<qreal>(pos) / static_cast<qreal>(_sampleCount);

    _reader->setRelatedPosition(lvalue);

}

void AudioPlayer::emitGetTrackPosition(qreal value)
{
    qreal lvalue = static_cast<qreal>(_sampleCount) * value;

    emit getTrackPosition(lvalue);
}
