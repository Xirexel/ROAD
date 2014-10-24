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

private slots:

    void openFractalFile();

};

#endif // MAINWIDGET_H
