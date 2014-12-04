#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

namespace Ui {
class MainWidget;
}

class AudioPlayer;

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

private:
    Ui::MainWidget *ui;

    AudioPlayer *_player;

    QString _filePath;

private slots:

    void setPositionTraker(int value);

    void play_pause();

    void checkState();

    void openFractalFile();

    void saveIntoWaveFile();

    void changeOutputDevice(int index);

    void updateAudioPlayer();

    void changeFrequency(int);

    void changeOutputBitsPerSample(int);

};

#endif // MAINWIDGET_H
