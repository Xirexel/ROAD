#include "listitem.h"
#include "ui_listitem.h"
#include <QFileInfo>
#include <QPixmap>
#include <QDir>



#include "encodingthread.h"
#include "wave_parser.h"
#include "ireaderfactory.h"
#include "ireader.h"
#include "progresscontrolpanel.h"


ListItem::ListItem(TypeSource aTypeSource,
                   QVarLengthArray<IROADoverCoderPlugin *> vPtrIROADoverCoderPlugin,
                   QString filePath,
                   ROADoverCoderOptions aROADoverCoderOptions,
                   QWidget *parent)
    : QWidget(parent),
      ui(new Ui::ListItem),
      _filePath(filePath),
      _typeROADoverCoder(aTypeSource),
      _ptrIROADoverCoderPluginCollection(vPtrIROADoverCoderPlugin),
      _optionsROADoverCoder(aROADoverCoderOptions)
{
    ui->setupUi(this);

    QFileInfo lQFileInfo(filePath);

    ui->fileNameLabel->setText(lQFileInfo.baseName());

    _outputFilePath = QDir::homePath() + "/Documents/" + lQFileInfo.baseName();



    IReaderFactory::TypeAudioFile lTypeAudioFile = IReaderFactory::NONE;

    switch(aTypeSource)
    {
    case WAVE:
    {

        ui->iconLabel->setPixmap(QPixmap(":/images/Wav.png").scaled(ui->iconLabel->sizeHint(),Qt::KeepAspectRatioByExpanding));

        lTypeAudioFile = IReaderFactory::WAVE;


    }

        break;

    }

    auto result = IReaderFactory::getInstance().getIReader(filePath, lTypeAudioFile);

    if(std::get<0>(result))
    {
        _smartPTRIReader.reset(std::get<1>(result));
    }

    for(IROADoverCoderPlugin * item: vPtrIROADoverCoderPlugin)
        ui->comboBoxROADoverCoder->addItem(item->name());


    connect(ui->startStopButton, SIGNAL(clicked()), SLOT(startEncoding()));

    connect(ui->deleteButton, SIGNAL(clicked()), SIGNAL(deleteFromList()));

}

ListItem::~ListItem()
{
    delete ui;
}

void ListItem::startEncoding()
{
    if(!_smartPTRIReader || ui->comboBoxROADoverCoder->currentIndex() < 0)
    {
        return;
    }


    IROADoverCoderPlugin * lptrIROADoverCoderPlugin = _ptrIROADoverCoderPluginCollection.at(ui->comboBoxROADoverCoder->currentIndex());

    IROADoverCoder* lptrIROADoverCoder = lptrIROADoverCoderPlugin->createIROADoverCoder(
                _smartPTRIReader.get()->getIROADoverRawReader(),
                &_optionsROADoverCoder,
                _smartPTRIReader.get()->getIOriginalAudioStreamOptions(),
                _outputFilePath);

    _smartPTRIReader.get()->setAtBegin();

    _smartPTREncodingThread.reset(
                new EncodingThread(lptrIROADoverCoder));

    ProgressControlPanel *lptrProgressControlPanel = new ProgressControlPanel();

    lptrProgressControlPanel->setObjectName("lptrProgressControlPanel");

    ui->widget->setEnabled(false);

    ui->verticalLayout->addWidget(lptrProgressControlPanel);

    QSize lHintSize = this->sizeHint();

    if(lHintSize.isValid())
    {
        this->resize(lHintSize);
    }

    emit updateVisual();

    connect(_smartPTREncodingThread.get(), SIGNAL(updatePercentageProgress()),SLOT(updatePercentage()));

    connect(_smartPTREncodingThread.get(), SIGNAL(started()), lptrProgressControlPanel,SLOT(show()));

    connect(_smartPTREncodingThread.get(), SIGNAL(finished()), lptrProgressControlPanel,SLOT(close()));

    connect(_smartPTREncodingThread.get(), SIGNAL(finished()), this,SLOT(enableItem()));

    connect(lptrProgressControlPanel, SIGNAL(interept()), _smartPTREncodingThread.get(), SLOT(interept()));



    _smartPTREncodingThread->start();

}

void ListItem::breakEncoding()
{

}

void ListItem::enableItem()
{
    ui->widget->setEnabled(true);

    QSize lHintSize = this->sizeHint();

    if(lHintSize.isValid())
    {
        this->resize(lHintSize);
    }

    emit updateVisual();
}

void ListItem::updatePercentage()
{
    ProgressControlPanel *lptrProgressControlPanel = this->findChild<ProgressControlPanel *>("lptrProgressControlPanel");

    if(lptrProgressControlPanel == nullptr)
        return;

    qint32 g = _smartPTRIReader->getPercentOfProcessedFile();

    lptrProgressControlPanel->setProgressValue(g);
}
