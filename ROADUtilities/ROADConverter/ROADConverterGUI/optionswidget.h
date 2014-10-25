#ifndef OPTIONSWIDGET_H
#define OPTIONSWIDGET_H

#include <QWidget>
#include "listitemsmodel.h"



namespace Ui {
class OptionsWidget;
}

class OptionsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OptionsWidget(QWidget *parent = 0);
    ~OptionsWidget();

    ModelOptions getModelOptions();

protected:

    void showEvent(QShowEvent * event);

    void closeEvent(QCloseEvent *event);

private:
    Ui::OptionsWidget *ui;

    ModelOptions _ModelOptions;

signals:

    void updateModelOptions();

};

#endif // OPTIONSWIDGET_H
