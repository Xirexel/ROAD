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

    for(quint32 lIndex = 0; lIndex < 4; ++lIndex)
    {
        ui->m_DepthFractalAnalyseComboBox->addItem(QString("%1 levels").arg(lIndex + 1),
                                                lIndex);
    }


    quint32 lcurrFractalAnalyseLevels = m_options->getAmountRangLevels();

    ui->m_DepthFractalAnalyseComboBox->setCurrentIndex(lcurrFractalAnalyseLevels);


    ui->m_ShiftDomainsSpinBox->setValue((int)m_options->getDomainShift());

    if(m_options->getEndianType() == 0)
        ui->m_endianTypeComboBox->setCurrentIndex(0);
    else
        ui->m_endianTypeComboBox->setCurrentIndex(1);

    connect(ui->m_ConstantScaleEnableCheckBox, SIGNAL(toggled(bool)), ui->m_ConstantScaleDoubleSpinBox, SLOT(setEnabled(bool)));

    if(m_options->getConstantScale() != 0)
    {
        ui->m_ConstantScaleEnableCheckBox->setChecked(true);

        ui->m_ConstantScaleDoubleSpinBox->setValue((double)m_options->getConstantScale()/128.0);
    }


    connect(ui->m_maxSuperFrameSpinBox, SIGNAL(valueChanged(int)) , SLOT(setState()));

    connect(ui->m_RangSampleLengthComboBox, SIGNAL(currentIndexChanged(int)) , SLOT(setState()));

    connect(ui->m_DepthFractalAnalyseComboBox, SIGNAL(currentIndexChanged(int)) , SLOT(setState()));

    connect(ui->m_ShiftDomainsSpinBox, SIGNAL(valueChanged(int)) , SLOT(setState()));

    connect(ui->m_endianTypeComboBox, SIGNAL(currentIndexChanged(int)) , SLOT(setState()));

    connect(ui->m_ConstantScaleDoubleSpinBox, SIGNAL(valueChanged(double)) , SLOT(setState()));

    connect(ui->m_ConstantScaleEnableCheckBox, SIGNAL(clicked()) , SLOT(setState()));


}

void EncodingOptionsFirstVersionWidget::setState()
{
    using namespace PlatformDependencies;

    this->m_options->setMaxSuperFrameLength(ui->m_maxSuperFrameSpinBox->value());

    this->m_options->setRangSampleLengthPowerOfTwoScale(ui->m_RangSampleLengthComboBox->currentData().toInt());

    this->m_options->setAmountRangLevels(ui->m_DepthFractalAnalyseComboBox->currentData().toInt());

    this->m_options->setDomainShift(ui->m_ShiftDomainsSpinBox->value());

    this->m_options->setEndianType(ui->m_endianTypeComboBox->currentIndex());

    if(ui->m_ConstantScaleEnableCheckBox->isChecked())
        this->m_options->setConstantScale((ROADInt8) (ui->m_ConstantScaleDoubleSpinBox->value() * 128.0));
    else
        this->m_options->setConstantScale((ROADInt8)0);

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
