#include <QFileDialog>


#include "audiofractalencoderwidget.h"
#include "ui_audiofractalencoderwidget.h"
#include "progressprocessingwidget.h"
#include "processingthread.h"
#include "wave_parser.h"

AudioFractalEncoderWidget::AudioFractalEncoderWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AudioFractalEncoderWidget),
    pProcessingThread(new ProcessingThread(this))
{
    ui->setupUi(this);

    connect(ui->openWaveFileButton, SIGNAL(clicked()), SLOT(readWaveInfo()));

    connect(ui->processButton, SIGNAL(clicked()), SLOT(processFile()));

    connect(pProcessingThread, SIGNAL(elapsedTime(float)), SLOT(showElapsedTime(float)));
}

AudioFractalEncoderWidget::~AudioFractalEncoderWidget()
{
    delete ui;
}

void AudioFractalEncoderWidget::readWaveInfo()
{
    QString filePath = QFileDialog::getOpenFileName(
                this,
                QObject::tr("Open 'WAVE' File"),
                "/home",
                QObject::tr("*.wave (*.wav)"));

    QFileInfo fileinfo(filePath);

    if(!fileinfo.exists())
        return;

    QFile file(filePath);

    if(!file.open(QIODevice::ReadOnly))
        return;

    do
    {
        QDataStream dataStream(&file);

        auto result = Wave_parser::getInstance().parse(dataStream);

        if(!std::get<0>(result))
            break;

        __WAVEDESCR lwavedescr = std::get<1>(result).getWavedescr();

        QString temp(lwavedescr.chunkHead.id);

        temp = temp.section("",0,4);

        ui->label_12->setText(temp);

        ui->label_6->setText(QString("%1").arg(lwavedescr.chunkHead.size));

        temp = QString(lwavedescr.wave);

        temp = temp.section("",0,4);

        ui->label_10->setText(temp);



        __WAVEFORMAT lwaveformat = std::get<1>(result).getWaveformat();

        if(lwaveformat.format == 1 && lwaveformat.channels == 2)
            ui->processButton->setEnabled(true);
        else
            ui->processButton->setEnabled(false);

        temp = QString(lwaveformat.chunkHead.id);

        temp = temp.section("",0,4);

        ui->label_22->setText(temp);

        ui->label_18->setText(QString("%1").arg(lwaveformat.chunkHead.size));

        ui->label_8->setText(QString("%1").arg(lwaveformat.format));

        ui->label_14->setText(QString("%1").arg(lwaveformat.channels));

        ui->label_20->setText(QString("%1").arg(lwaveformat.sampleRate));

        ui->label_16->setText(QString("%1").arg(lwaveformat.byteRate));

        ui->label_24->setText(QString("%1").arg(lwaveformat.blockAlign));

        ui->label_26->setText(QString("%1").arg(lwaveformat.bitsPerSample));



        __WAVEDESCRDATA lwavedescrdata = std::get<1>(result).getWavedescrdata();

        temp = QString(lwavedescrdata.chunkHead.id);

        temp = temp.section("",0,4);

        ui->label_27->setText(temp);

        ui->label_28->setText(QString("%1").arg(lwavedescrdata.chunkHead.size));

        selectedFilePath = filePath;

    }
    while(false);

    file.close();
}

void AudioFractalEncoderWidget::processFile()
{
    QFileInfo fileinfo(selectedFilePath);

    if(!fileinfo.exists())
        return;

    QFile file(selectedFilePath);

    if(!file.open(QIODevice::ReadOnly))
        return;

    do
    {
        QDataStream dataStream(&file);

        auto result = Wave_parser::getInstance().parse(dataStream);

        file.close();

        if(!std::get<0>(result))
            break;

        QString waveFractalFilePath = QFileDialog::getSaveFileName(
                    this,
                    QObject::tr("Save 'ROAD' file as..."),
                    QDir::homePath() + "/Documents/",
                    QObject::tr("*.road.wave (*.road.wav)"));


        if(waveFractalFilePath.isEmpty())
            break;

        FractalOptions fractalOptions;

        fractalOptions._frameSampleLength = 2048;

        fractalOptions._superFrameLength = ui->superFrameLengthspinBox->value();

        fractalOptions._widestRangeLength = 32;


        switch(ui->lowestRangeLengthcomboBox->currentIndex())
        {
        case 0:
        default:
            fractalOptions._smallestRangeLength = 4;
            break;

        case 1:
            fractalOptions._smallestRangeLength = 8;
            break;

        case 2:
            fractalOptions._smallestRangeLength = 16;
            break;

        case 3:
            fractalOptions._smallestRangeLength = 32;
            break;
        }


        fractalOptions._relativeDomainShift = ui->relativeDomainShiftspinBox->value();


        switch(ui->mixingChannelModeComboBox->currentIndex())
        {
        case 0:
        default:
            fractalOptions._mixingChannelMode = FractalOptions::LPLUSR;
            break;

        case 1:
            fractalOptions._mixingChannelMode = FractalOptions::LMINUSR;
            break;

        case 2:
            fractalOptions._mixingChannelMode = FractalOptions::NONE;
            break;
        }

        pProcessingThread->setFractalEncoderOptions(selectedFilePath, waveFractalFilePath, fractalOptions);

        ProgressProcessingWidget *lptrProgressProcessingWidget = new ProgressProcessingWidget;

        connect(pProcessingThread, SIGNAL(progressValue(quint32)), lptrProgressProcessingWidget,SLOT(setProgressValue(quint32)));

        connect(pProcessingThread, SIGNAL(started()), lptrProgressProcessingWidget,SLOT(show()));

        connect(pProcessingThread, SIGNAL(finished()), lptrProgressProcessingWidget,SLOT(close()));

        connect(lptrProgressProcessingWidget, SIGNAL(interept()), pProcessingThread, SLOT(interept()));

        pProcessingThread->start();


    }
    while(false);
}

void AudioFractalEncoderWidget::showElapsedTime(float time)
{
    if(time == -1.0)
    {
        ui->elapsatedTmelabel->setText("error");

        ui->elapsatedTmelabel->setStyleSheet("color: rgb(255, 0, 0); font: 12pt;");
    }
    else
    {
        time = time/1000.0f;

        QString timeout = QString("%1").arg(time);

        timeout += " c.";

        ui->elapsatedTmelabel->setText(timeout);

        ui->elapsatedTmelabel->setStyleSheet("color: rgb(0, 127, 127); font: 12pt;");
    }
}
