#include "optionswidget.h"
#include "ui_optionswidget.h"
#include "encodingoptionswidgetfactory.h"


#include "../../../ROADcodec/ROADcoder/ROADoverCoder/IROADoverEncodingOptions.h"

OptionsWidget::OptionsWidget(std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> &aOptionsROADoverCoder, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OptionsWidget),
    m_dicROADFormats(EncodingOptions::EncodingOptionsWidgetFactory::getEncodingOptions()),
    _optionsROADoverCoder(aOptionsROADoverCoder->clone())
{
    ui->setupUi(this);

    connect(ui->selectTypeOfROADencodingComboBox, SIGNAL(currentIndexChanged(QString)), SLOT(updateEncodingOptionsWidget(QString)));

    connect(ui->confirmPushButton, SIGNAL(clicked()), SLOT(confirmOptions()));

    connect(ui->confirmPushButton, SIGNAL(clicked()), SIGNAL(closeWidget()));

    connect(ui->cancelPushButton, SIGNAL(clicked()), SIGNAL(closeWidget()));



    ui->selectTypeOfROADencodingComboBox->addItems(m_dicROADFormats.keys());

    QList<QString> lList = m_dicROADFormats.keys(_optionsROADoverCoder->getROADFormatMode());

    if(lList.size() > 0)
    {
        ui->selectTypeOfROADencodingComboBox->setCurrentText(lList.at(0));

        setEncodingOptionsWidget(_optionsROADoverCoder);
    }
}

OptionsWidget::~OptionsWidget()
{
    delete ui;
}

void OptionsWidget::setEncodingOptionsWidget(std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> &aOptionsROADoverCoder)
{
    auto loptionsWidget = EncodingOptions::EncodingOptionsWidgetFactory::getEncodingOptionsWidget(aOptionsROADoverCoder);

    connect(loptionsWidget.get(), SIGNAL(updatedState(bool)), SLOT(updateState(bool)));

    ui->widgetScrollArea->setWidget(loptionsWidget.release());
}

void OptionsWidget::updateEncodingOptionsWidget(QString aIndex)
{
    auto loptionsWidget = EncodingOptions::EncodingOptionsWidgetFactory::getEncodingOptionsWidget(m_dicROADFormats[aIndex]);

    connect(loptionsWidget.get(), SIGNAL(updatedState(bool)), SLOT(updateState(bool)));

    ui->widgetScrollArea->setWidget(loptionsWidget.release());
}

void OptionsWidget::confirmOptions()
{
    do
    {
        auto lptrWidget = dynamic_cast<EncodingOptions::EncodingOptionsWidget*>(ui->widgetScrollArea->widget());

        if(lptrWidget == nullptr)
            break;

        auto loptions = lptrWidget->getEncodingOptions();

        if(!loptions)
            break;

        emit updateOptions(loptions);


    }
    while(false);

}

void OptionsWidget::updateState(bool aState)
{
    if(aState)
    {
        ui->confirmPanel->setEnabled(true);
    }
}
