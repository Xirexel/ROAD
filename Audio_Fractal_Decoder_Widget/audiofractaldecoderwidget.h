#ifndef AUDIOFRACTALDECODERWIDGET_H
#define AUDIOFRACTALDECODERWIDGET_H

#include <QWidget>

#include "audio_fractal_decoder_widget_global.h"

class AudioWaveFractalPlayer;
class FractalToWaveConverter;

namespace Ui {
class AudioFractalDecoderWidget;
}


class AUDIO_FRACTAL_DECODER_WIDGETSHARED_EXPORT  AudioFractalDecoderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AudioFractalDecoderWidget(QWidget *parent = 0);
    ~AudioFractalDecoderWidget();

private:
    Ui::AudioFractalDecoderWidget *ui;

    QString selectedFilePath;

    AudioWaveFractalPlayer *_player;

    FractalToWaveConverter *_converter;

    void resetWidget();

signals:

private slots:

    void openWaveFractalFile();

    void setPositionTraker(int value);

    void decodeIntoWaveFile();

    void play_pause();

    void checkState();

    void changeFrequency(int index);

    void changeOutputDevice(int index);

    void changeOutputBitsPerSample(int index);
};

#endif // AUDIOFRACTALDECODERWIDGET_H
