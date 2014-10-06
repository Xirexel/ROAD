#include "encodingoptionsexperementalwidget.h"
#include "ui_encodingoptionsexperementalwidget.h"


EncodingOptionsExperementalWidget::EncodingOptionsExperementalWidget(std::unique_ptr<ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental> &aOptions, QWidget *parent) :
    EncodingOptionsWidget(parent),
    ui(new Ui::EncodingOptionsExperementalWidget),
    m_options(aOptions.release())
{
    ui->setupUi(this);


    if(!m_options)
        return;

    ui->superFrameLengthspinBox->setValue(m_options->getSuperFrameLength());

    ui->realtiveDomainShiftspinBox->setValue(m_options->getDomainShift());

    ui->minSampleLengthRangcomboBox->setCurrentIndex(m_options->getAmountRangLevels());

    ui->mixingChannelModecomboBox->setCurrentIndex(m_options->getMixingChannelsMode());



    connect(ui->superFrameLengthspinBox, SIGNAL(valueChanged(int)), SLOT(setState()));

    connect(ui->realtiveDomainShiftspinBox, SIGNAL(valueChanged(int)), SLOT(setState()));

    connect(ui->minSampleLengthRangcomboBox, SIGNAL(currentIndexChanged(int)), SLOT(setState()));

    connect(ui->mixingChannelModecomboBox, SIGNAL(currentIndexChanged(int)), SLOT(setState()));



}

void EncodingOptionsExperementalWidget::setState()
{
    this->m_options->setSuperFrameLength(ui->superFrameLengthspinBox->value());

    this->m_options->setDomainShift(ui->realtiveDomainShiftspinBox->value());

    this->m_options->setAmountRangLevels(ui->minSampleLengthRangcomboBox->currentIndex());

    this->m_options->setMixingChannelsMode(ROADcoder::ROADoverCoder::ChannelsMixingMode(ui->mixingChannelModecomboBox->currentIndex()));

    emit updatedState(true);
}

EncodingOptionsExperementalWidget::~EncodingOptionsExperementalWidget()
{
    delete ui;
}

std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> EncodingOptionsExperementalWidget::getEncodingOptions()
{
    return this->m_options->clone();
}
