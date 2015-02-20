#include "encodingoptionsfirstversionwidget.h"
#include "ui_encodingoptionsfirstversionwidget.h"
#include <qmath.h>

EncodingOptionsFirstVersionWidget::EncodingOptionsFirstVersionWidget(std::unique_ptr<ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion> &aOptions, QWidget *parent) :
    EncodingOptionsWidget(parent),
    ui(new Ui::EncodingOptionsFirstVersionWidget),
    m_options(aOptions.release())
{
    ui->setupUi(this);

    ui->m_sampleLength->setText(QString("%1 samples").arg(m_options->getFrameSampleLength()));

    ui->m_maxSuperFrameSpinBox->setValue((int)m_options->getMaxSuperFrameLength());

    quint32 lcount = 0;

    while (true) {

        quint32 lvalue = (quint32)(m_options->getInitRangSampleLength() << lcount);

        if(lvalue << 1 > m_options->getFrameSampleLength())
            break;

        ui->m_RangSampleLengthComboBox->addItem(QString("%1 samples").arg(lvalue),
                                                lcount);

        ++lcount;
    }

    recompute();

    ui->m_ShiftDomainsSpinBox->setValue((int)m_options->getDomainShift());

    if(m_options->getEndianType() == 0)
        ui->m_endianTypeComboBox->setCurrentIndex(0);
    else
        ui->m_endianTypeComboBox->setCurrentIndex(1);

    ui->m_ConstantScaleDoubleSpinBox->setValue((double)m_options->getConstantScale()/128.0);

}

void EncodingOptionsFirstVersionWidget::recompute()
{
    quint32 lrangSampleLength = (quint32)(m_options->getInitRangSampleLength() << ui->m_RangSampleLengthComboBox->currentData().toUInt());

    quint32 lmaxFractalAnalyseLevels = (quint32)log2(m_options->getFrameSampleLength() / lrangSampleLength);

    for(quint32 lIndex = 0; lIndex < lmaxFractalAnalyseLevels; ++lIndex)
    {
        ui->m_DepthFractalAnalyseComboBox->addItem(QString("%1 levels").arg(lIndex + 1),
                                                lIndex);
    }

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
