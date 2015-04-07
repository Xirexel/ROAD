#include "optionswidget.h"
#include "ui_optionswidget.h"
#include <QShowEvent>
#include <math.h>


#include "encodingoptionsfactory.h"
#include "encodingoptionswidgetfactory.h"
#include "../../../ROADcodec/ROADcoder/ROADoverCoder/IROADoverEncodingOptions.h"


OptionsWidget::OptionsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OptionsWidget),
    m_dicROADFormats(EncodingOptions::EncodingOptionsWidgetFactory::getEncodingOptions())
{
    ui->setupUi(this);

    connect(ui->selectTypeOfROADencodingComboBox, SIGNAL(currentIndexChanged(QString)), SLOT(updateEncodingOptionsWidget(QString)));

    connect(ui->cancelPushButton, SIGNAL(clicked()), SLOT(rejectState()));

    connect(ui->confirmPushButton, SIGNAL(clicked()), SLOT(persist()));

    Qt::WindowFlags flags = Qt::CustomizeWindowHint
            |Qt::WindowTitleHint
            |Qt::MSWindowsFixedSizeDialogHint
            |Qt::WindowCloseButtonHint;

    this->setWindowFlags(flags);

    ui->selectTypeOfROADencodingComboBox->addItems(m_dicROADFormats.keys());

    QString ldefaultKey = m_dicROADFormats.key(_ModelOptions.getROADoverCoderOptions());

    ui->selectTypeOfROADencodingComboBox->setCurrentText(ldefaultKey);

    connect(ui->setROADTypeAsDefaultCheckBox, SIGNAL(clicked(bool)), SLOT(setAsDefault(bool)));

}

OptionsWidget::~OptionsWidget()
{
    delete ui;
}

void OptionsWidget::showEvent(QShowEvent * )
{


}

void OptionsWidget::closeEvent(QCloseEvent *event)
{
    event->accept();
}

ModelOptions OptionsWidget::getModelOptions()
{
    return _ModelOptions;
}

void OptionsWidget::updateEncodingOptionsWidget(QString aIndex)
{
    auto lselectedROADFormat = m_dicROADFormats[aIndex];

    auto loptionsWidget = EncodingOptions::EncodingOptionsWidgetFactory::getEncodingOptionsWidget(lselectedROADFormat);

    connect(loptionsWidget.get(), SIGNAL(updatedState(bool)), SLOT(updateState(bool)));

    ui->encodingOptionsScrollArea->setWidget(loptionsWidget.release());


    auto lcurrentROADFormat = _ModelOptions.getROADoverCoderOptions();

    if(lselectedROADFormat != lcurrentROADFormat)
    {
        ui->setROADTypeAsDefaultCheckBox->setChecked(false);

        ui->setROADTypeAsDefaultCheckBox->setEnabled(true);
    }
    else
    {
        ui->setROADTypeAsDefaultCheckBox->setChecked(true);

        ui->setROADTypeAsDefaultCheckBox->setEnabled(false);
    }

}

void OptionsWidget::updateState(bool aState)
{
    ui->confirmPanel->setEnabled(aState);
}

void OptionsWidget::rejectState()
{
    ui->confirmPanel->setEnabled(false);

    updateEncodingOptionsWidget(ui->selectTypeOfROADencodingComboBox->currentText());
}

void OptionsWidget::setAsDefault(bool aState)
{
    if(!aState)
        return;

    auto lcurrROADFormat = ui->selectTypeOfROADencodingComboBox->currentText();

    _ModelOptions.setROADoverCoderOptions(m_dicROADFormats.value(lcurrROADFormat));

    ui->setROADTypeAsDefaultCheckBox->setChecked(aState);

    ui->setROADTypeAsDefaultCheckBox->setEnabled(!aState);
}

void OptionsWidget::persist()
{
    do
    {
        auto lptrWidget = dynamic_cast<EncodingOptions::EncodingOptionsWidget*>(ui->encodingOptionsScrollArea->widget());

        if(lptrWidget == nullptr)
            break;

        auto loptions = lptrWidget->getEncodingOptions();

        if(!loptions)
            break;

        EncodingOptionsFactory::persistIROADoverEncodingOptions(loptions);

    }
    while(false);

    rejectState();
}
