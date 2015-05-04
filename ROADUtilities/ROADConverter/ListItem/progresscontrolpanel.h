#ifndef PROGRESSCONTROLPANEL_H
#define PROGRESSCONTROLPANEL_H

#include <QWidget>
#include <QTime>

namespace Ui {
class ProgressControlPanel;
}

class ProgressControlPanel : public QWidget
{
    Q_OBJECT

public:
    explicit ProgressControlPanel(QWidget *parent = 0);
    ~ProgressControlPanel();

private:
    Ui::ProgressControlPanel *ui;

    QTime mTime;

signals:

    void interept();

public slots:

    void setProgressValue(qint32 value);
};

#endif // PROGRESSCONTROLPANEL_H
