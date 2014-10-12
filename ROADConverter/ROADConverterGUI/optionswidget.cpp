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
    switch(_ModelOptions.getTypeROADFormat())
    {
    case ModelOptions::EXPEREMENTAL:
        ui->formatcomboBox->setCurrentIndex(0);
        break;
    }

    ui->superFrameLengthspinBox->setValue(_ModelOptions.getSuperFrameLength());

    ui->minSampleLengthRangcomboBox->setCurrentIndex((int)log2(_ModelOptions.getMinSampleLengthRang()/4));

    ui->realtiveDomainShiftspinBox->setValue(_ModelOptions.getRelativeDomainShift());

    switch(_ModelOptions.getTypeMixingChannelsMode())
    {
    case ModelOptions::L_PLUS_R:
        ui->mixingChannelModecomboBox->setCurrentIndex(0);
        break;

    case ModelOptions::L_MINUS_R:
        ui->mixingChannelModecomboBox->setCurrentIndex(1);
        break;

    case ModelOptions::NONE:
        ui->mixingChannelModecomboBox->setCurrentIndex(2);
        break;
    }

}

void OptionsWidget::closeEvent(QCloseEvent *event)
{
    ModelOptions::TypeROADFormat lTypeROADFormat;

    switch(ui->formatcomboBox->currentIndex())
    {
    case 0:
    default:
        lTypeROADFormat = ModelOptions::EXPEREMENTAL;
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

    ModelOptions::TypeMixingChannelsMode lTypeMixingChannelsMode;

    switch(ui->mixingChannelModecomboBox->currentIndex())
    {
    case 0:
        lTypeMixingChannelsMode = ModelOptions::L_PLUS_R;
        break;

    case 1:
        lTypeMixingChannelsMode = ModelOptions::L_MINUS_R;
        break;

    case 2:
        lTypeMixingChannelsMode = ModelOptions::NONE;
        break;
    }

    _ModelOptions = ModelOptions(lTypeROADFormat, ui->superFrameLengthspinBox->value(), lMinSampleLength, ui->realtiveDomainShiftspinBox->value(), lTypeMixingChannelsMode);

    emit updateModelOptions();

    event->accept();
}

ModelOptions OptionsWidget::getModelOptions()
{
    return _ModelOptions;
}
