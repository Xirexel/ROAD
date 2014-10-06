#include "audiofractaldecoderwidget.h"
#include "ui_audiofractaldecoderwidget.h"
#include "audiowavefractalplayer.h"
#include "wavefractal_parser.h"
#include "fractaltowaveconverter.h"


#include <QFileDialog>
#include <QFileInfo>


AudioFractalDecoderWidget::AudioFractalDecoderWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AudioFractalDecoderWidget),
    _player(new AudioWaveFractalPlayer(this)),
    _converter(new FractalToWaveConverter(this))
{
    ui->setupUi(this);

    connect(ui->openWaveFileButton, SIGNAL(clicked()), SLOT(openWaveFractalFile()));

    connect(ui->playButton, SIGNAL(clicked()), SLOT(play_pause()));

    connect(ui->stopButton, SIGNAL(clicked()), _player, SLOT(stop()));

    connect(ui->horizontalSlider, SIGNAL(sliderMoved(int)) , _player, SLOT(setTrackPosition(int)));

    connect(_player, SIGNAL(setRange(int,int)), ui->horizontalSlider, SLOT(setRange(int,int)));

    connect(_player, SIGNAL(getTrackPosition(int)), SLOT(setPositionTraker(int)));

    connect(_player, SIGNAL(finish()), SLOT(checkState()));

    connect(ui->selectOutFrequencyComboBox, SIGNAL(currentIndexChanged(int)), SLOT(changeFrequency(int)));

    connect(ui->decodeIntoWaveFileButton, SIGNAL(clicked()), SLOT(decodeIntoWaveFile()));

    connect(ui->outputDevicesComboBox, SIGNAL(currentIndexChanged(int)), SLOT(changeOutputDevice(int)));

    connect(ui->bitsPerSampleComboBox, SIGNAL(currentIndexChanged(int)), SLOT(changeOutputBitsPerSample(int)));



    const QAudioDeviceInfo &defaultDeviceInfo = QAudioDeviceInfo::defaultOutputDevice();

    ui->outputDevicesComboBox->addItem(defaultDeviceInfo.deviceName(), qVariantFromValue(defaultDeviceInfo));

    for (const QAudioDeviceInfo &deviceInfo: QAudioDeviceInfo::availableDevices(QAudio::AudioOutput))
    {
        if (deviceInfo != defaultDeviceInfo)
            ui->outputDevicesComboBox->addItem(deviceInfo.deviceName(), qVariantFromValue(deviceInfo));
    }


}

AudioFractalDecoderWidget::~AudioFractalDecoderWidget()
{
    _player->stop();

    delete ui;
}

void AudioFractalDecoderWidget::setPositionTraker(int value)
{

    ui->horizontalSlider->setSliderPosition(value);

}

void AudioFractalDecoderWidget::decodeIntoWaveFile()
{

    QString filePath = QFileDialog::getSaveFileName(
                this,
                QObject::tr("Save 'Wave' file as..."),
                QDir::homePath() + "/Documents",
                QObject::tr("*.wave (*.wav)"));


    quint32 lsamplesPerRange = 1;



    bool ok = false;

    lsamplesPerRange = ui->selectOutFrequencyComboBox->itemData(ui->selectOutFrequencyComboBox->currentIndex()).toInt(&ok);

    if(!ok)
        return;

    _converter->convert(selectedFilePath, filePath, lsamplesPerRange, ui->bitsPerSampleComboBox->currentData().value<quint32>());

}

void AudioFractalDecoderWidget::play_pause()
{
    _player->pause();

    checkState();
}

void AudioFractalDecoderWidget::checkState()
{

    if(_player->getState() == QAudio::ActiveState)
        ui->playButton->setText("Pause");
    else
        ui->playButton->setText("Play");
}

void AudioFractalDecoderWidget::changeOutputBitsPerSample(int index)
{
    if(index < 0)
        return;

    _player->stop();


    _player->setFilePath(selectedFilePath, ui->selectOutFrequencyComboBox->currentData().value<quint32>(),
                         ui->bitsPerSampleComboBox->currentData().value<quint32>(),
                         ui->outputDevicesComboBox->currentData().value<QAudioDeviceInfo>());

}

void AudioFractalDecoderWidget::changeOutputDevice(int index)
{

    _player->stop();

}

void AudioFractalDecoderWidget::changeFrequency(int index)
{
    if(index < 0)
        return;

    _player->stop();

    quint32 lsamplesPerRange = 1;

    bool ok = false;

    lsamplesPerRange = ui->selectOutFrequencyComboBox->itemData(index).toInt(&ok);

    if(ok)
        _player->setFilePath(selectedFilePath, lsamplesPerRange, ui->bitsPerSampleComboBox->currentData().value<quint32>(),
                             ui->outputDevicesComboBox->currentData().value<QAudioDeviceInfo>());


}

void AudioFractalDecoderWidget::openWaveFractalFile()
{
    _player->stop();

    QString filePath = QFileDialog::getOpenFileName(
                this,
                QObject::tr("Open 'Fractal' or old format 'WAVE' File"),
                QDir::homePath() + "/Documents",
                QObject::tr("*.wave (*.wav)"));

    QFileInfo fileinfo(filePath);

    resetWidget();

    if(!fileinfo.exists())
        return;

    QFile file(filePath);

    if(!file.open(QIODevice::ReadOnly))
        return;

    do
    {
        QDataStream dataStream(&file);

        auto result = WaveFractal_parser::getInstance().parse(dataStream);

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


        ui->label_8->setText(QString("%1").arg(lwaveformat.format));

        ui->label_14->setText(QString("%1").arg(lwaveformat.channels));

        ui->label_20->setText(QString("%1").arg(lwaveformat.sampleRate));

        ui->label_16->setText(QString("%1").arg(lwaveformat.byteRate));

        ui->label_26->setText(QString("%1").arg(lwaveformat.bitsPerSample));



        __WAVEDESCRDATA lwavedescrdata = std::get<1>(result).getWavedescrdata();

        temp = QString(lwavedescrdata.chunkHead.id);

        temp = temp.section("",0,4);

        ui->label_27->setText(temp);

        ui->label_28->setText(QString("%1").arg(lwavedescrdata.chunkHead.size));



        ui->playButton->setEnabled(true);

        ui->stopButton->setEnabled(true);

        ui->horizontalSlider->setEnabled(true);

        quint32 lsamplesPerRange = 1;

        ui->bitsPerSampleComboBox->clear();

        if(std::get<1>(result).isWaveFractal())
        {
            ui->groupBox_4->setEnabled(true);

            if(lwaveformat.bitsPerSample > 8)
            {
                quint32 lStep = lwaveformat.bitsPerSample;

                while(lStep <= 32)
                {
                    ui->bitsPerSampleComboBox->addItem(QString("%1 Bits").arg(lStep), lStep);

                    lStep *= 2;
                }

            }
            else
            {
                ui->bitsPerSampleComboBox->addItem(QString("%1 Bits").arg(lwaveformat.bitsPerSample), lwaveformat.bitsPerSample);
            }

            __FRACDESCR lfractalDescriptor = std::get<1>(std::get<1>(result).getFracdescr());

            ui->labelFractalFormat->setText(QString("%1").arg(lfractalDescriptor._format._format));

            ui->labelSuperFrameLength->setText(QString("%1").arg(lfractalDescriptor._format._superFrameLength));

            ui->labelFrameRangeLength->setText(QString("%1").arg(lfractalDescriptor._format._frameRangeLength));

            ui->labelRelativeDomainShift->setText(QString("%1").arg(lfractalDescriptor._format._domainShift));

            QString lModeChannelMixing = "None";

            switch (lfractalDescriptor._format._averDiffMode) {
            case 0:

                lModeChannelMixing = "L+R";

                break;
            case 1:

                lModeChannelMixing = "L-R";

                break;
            case 2:

                lModeChannelMixing = "None";

                break;
            default:
                break;
            }

            ui->labelMixingChannelsMode->setText(lModeChannelMixing);


            QAudioDeviceInfo lAudioDeviceInfo = QAudioDeviceInfo::defaultOutputDevice();

            QList<int> listSupportSampleRates = lAudioDeviceInfo.supportedSampleRates();

            if(listSupportSampleRates.count() == 0)
                break;

            ui->selectOutFrequencyComboBox->clear();

            quint32 lLowScaleFrequency = 1;

            while(true)
            {
                if(lwaveformat.sampleRate * lLowScaleFrequency >= listSupportSampleRates.at(0))
                    break;

                lLowScaleFrequency *= 2;
            }

            for(decltype(lLowScaleFrequency) stepFrequency = lLowScaleFrequency;
                lwaveformat.sampleRate * stepFrequency <= listSupportSampleRates.at(listSupportSampleRates.count() - 1);
                stepFrequency *= 2)
            {
                ui->selectOutFrequencyComboBox->addItem(QString("%1 Hz").arg(lwaveformat.sampleRate * stepFrequency), stepFrequency);
            }

            if(lsamplesPerRange == 0)
                lsamplesPerRange = 1;

            ui->decodeIntoWaveFileButton->setEnabled(true);
        }
        else
            ui->decodeIntoWaveFileButton->setEnabled(false);

        _player->setFilePath(filePath, ui->selectOutFrequencyComboBox->currentData().value<quint32>(), ui->bitsPerSampleComboBox->currentData().value<quint32>(),
                             ui->outputDevicesComboBox->currentData().value<QAudioDeviceInfo>());

        selectedFilePath = filePath;


    }
    while(false);

    file.close();
}

void AudioFractalDecoderWidget::resetWidget()
{
    ui->playButton->setEnabled(false);

    ui->stopButton->setEnabled(false);

    ui->horizontalSlider->setEnabled(false);

    ui->groupBox_4->setEnabled(false);



    ui->label_12->setText("");

    ui->label_6->setText("");

    ui->label_10->setText("");



    ui->label_8->setText("");

    ui->label_14->setText("");

    ui->label_20->setText("");

    ui->label_16->setText("");

    ui->label_26->setText("");



    ui->label_27->setText("");

    ui->label_28->setText("");

    selectedFilePath = "Empty";
}
