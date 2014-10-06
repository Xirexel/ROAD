#ifndef PROGRESSPROCESSINGWIDGET_H
#define PROGRESSPROCESSINGWIDGET_H

#include <QWidget>

namespace Ui {
class ProgressProcessingWidget;
}

class ProgressProcessingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProgressProcessingWidget(QWidget *parent = 0);
    ~ProgressProcessingWidget();

private:
    Ui::ProgressProcessingWidget *ui;

signals:
    void interept();


public slots:
    void setProgressValue(quint32 value);
};

#endif // PROGRESSPROCESSINGWIDGET_H
