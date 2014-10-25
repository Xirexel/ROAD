#include "optionswidget.h"
#include "ui_optionswidget.h"
#include <QShowEvent>
#include <math.h>




OptionsWidget::OptionsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OptionsWidget)
{
    ui->setupUi(this);

    Qt::WindowFlags flags = Qt::CustomizeWindowHint
            |Qt::WindowTitleHint
            |Qt::MSWindowsFixedSizeDialogHint
            |Qt::WindowCloseButtonHint;

    this->setWindowFlags(flags);
}

OptionsWidget::~OptionsWidget()
{
    delete ui;
}

void OptionsWidget::showEvent(QShowEvent * event)
{
    ROADoverCoderOptions _ROADoverCoderOptions = _ModelOptions.getROADoverCoderOptions();

    switch(_ROADoverCoderOptions.getTypeROADFormat())
    {
    case ROADoverCoderOptions::EXPEREMENTAL:
        ui->formatcomboBox->setCurrentIndex(0);
        break;
    }

    ui->superFrameLengthspinBox->setValue(_ROADoverCoderOptions.getSuperFrameLength());

    ui->minSampleLengthRangcomboBox->setCurrentIndex((int)log2(_ROADoverCoderOptions.getMinSampleLengthRang()/4));

    ui->realtiveDomainShiftspinBox->setValue(_ROADoverCoderOptions.getRelativeDomainShift());

    switch(_ROADoverCoderOptions.getTypeMixingChannelsMode())
    {
    case ROADoverCoderOptions::L_PLUS_R:
        ui->mixingChannelModecomboBox->setCurrentIndex(0);
        break;

    case ROADoverCoderOptions::L_MINUS_R:
        ui->mixingChannelModecomboBox->setCurrentIndex(1);
        break;

    case ROADoverCoderOptions::NONE:
        ui->mixingChannelModecomboBox->setCurrentIndex(2);
        break;
    }

}

void OptionsWidget::closeEvent(QCloseEvent *event)
{
    ROADoverCoderOptions::TypeROADFormat lTypeROADFormat;

    switch(ui->formatcomboBox->currentIndex())
    {
    case 0:
    default:
        lTypeROADFormat = ROADoverCoderOptions::EXPEREMENTAL;
        break;
    }

    quint32 lMinSampleLength;

    switch(ui->minSampleLengthRangcomboBox->currentIndex())
    {
    case 0:
    default:
        lMinSampleLength = 4;
        break;

    case 1:
        lMinSampleLength = 8;
        break;

    case 2:
        lMinSampleLength = 16;
        break;

    case 3:
        lMinSampleLength = 32;
        break;
    }

    ROADoverCoderOptions::TypeMixingChannelsMode lTypeMixingChannelsMode;

    switch(ui->mixingChannelModecomboBox->currentIndex())
    {
    case 0:
        lTypeMixingChannelsMode = ROADoverCoderOptions::L_PLUS_R;
        break;

    case 1:
        lTypeMixingChannelsMode = ROADoverCoderOptions::L_MINUS_R;
        break;

    case 2:
        lTypeMixingChannelsMode = ROADoverCoderOptions::NONE;
        break;
    }

    ROADoverCoderOptions lROADoverCoderOptions(lTypeROADFormat,
                                               ui->superFrameLengthspinBox->value(),
                                               lMinSampleLength,
                                               ui->realtiveDomainShiftspinBox->value(),
                                               lTypeMixingChannelsMode,
                                               1000.0,
                                               1000.0);

    _ModelOptions.setROADoverCoderOptions(lROADoverCoderOptions);

    emit updateModelOptions();

    event->accept();
}

ModelOptions OptionsWidget::getModelOptions()
{
    return _ModelOptions;
}
