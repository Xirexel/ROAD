#ifndef OPTIONSWIDGET_H
#define OPTIONSWIDGET_H

#include <QWidget>
#include <QMap>

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

    void showEvent(QShowEvent *);

    void closeEvent(QCloseEvent *event);

private:
    Ui::OptionsWidget *ui;

    ModelOptions _ModelOptions;

    QMap<QString, unsigned int> m_dicROADFormats;

signals:

    void updateModelOptions();

private slots:

    void updateEncodingOptionsWidget(QString aIndex);

    void updateState(bool aState);

    void rejectState();

    void persist();

    void setAsDefault(bool aState);

};

#endif // OPTIONSWIDGET_H
