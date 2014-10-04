#ifndef AUDIOFRACTALENCODERWIDGET_H
#define AUDIOFRACTALENCODERWIDGET_H

#include <QWidget>


#include "audio_fractal_encoder_widget_global.h"

namespace Ui {
class AudioFractalEncoderWidget;
}

class ProcessingThread;

class AUDIO_FRACTAL_ENCODER_WIDGETSHARED_EXPORT AudioFractalEncoderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AudioFractalEncoderWidget(QWidget *parent = 0);
    ~AudioFractalEncoderWidget();

private:
    Ui::AudioFractalEncoderWidget *ui;

    ProcessingThread *pProcessingThread;

    QString selectedFilePath;

private slots:

    void readWaveInfo();

    void processFile();

    void showElapsedTime(float time);
};

#endif // AUDIOFRACTALENCODERWIDGET_H
