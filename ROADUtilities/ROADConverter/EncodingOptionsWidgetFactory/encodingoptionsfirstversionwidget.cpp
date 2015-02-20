#include "encodingoptionsfirstversionwidget.h"
#include "ui_encodingoptionsfirstversionwidget.h"

EncodingOptionsFirstVersionWidget::EncodingOptionsFirstVersionWidget(std::unique_ptr<ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion> &aOptions, QWidget *parent) :
    EncodingOptionsWidget(parent),
    ui(new Ui::EncodingOptionsFirstVersionWidget),
    m_options(aOptions.release())
{
    ui->setupUi(this);

    ui->m_sampleLength->setText(QString("%1 samples").arg(m_options->getFrameSampleLength()));

    ui->m_maxSuperFrameSpinBox->setValue((int)m_options->getMaxSuperFrameLength());
}

void EncodingOptionsFirstVersionWidget::setState()
{
//    this->m_options->setSuperFrameLength(ui->superFrameLengthspinBox->value());

//    this->m_options->setDomainShift(ui->realtiveDomainShiftspinBox->value());

//    this->m_options->setAmountRangLevels(ui->minSampleLengthRangcomboBox->currentIndex());

//    this->m_options->setMixingChannelsMode(ROADcoder::ROADoverCoder::ChannelsMixingMode(ui->mixingChannelModecomboBox->currentIndex()));

    emit updatedState(true);
}

std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> EncodingOptionsFirstVersionWidget::getEncodingOptions()
{
    return this->m_options->clone();
}

EncodingOptionsFirstVersionWidget::~EncodingOptionsFirstVersionWidget()
{
    delete ui;
}
