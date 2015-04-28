#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "audioplayer.h"

#include <QFile>
#include <QFileDialog>


#include <memory>

#include <iostream>

#include "wavefractalreader.h"


void convert(QString source, QString destination, quint32 samplesPerRange, quint32 bitsPerSample)
{
    WaveFractalReader lreader(source, samplesPerRange, bitsPerSample);


    if(!lreader.isOpen())
        return;

    QFile loutFile(destination);


    if(!loutFile.open(QIODevice::WriteOnly))
        return;



    qint64 lsizeData = lreader.getSizeOfData();


    __WAVEDESCR lwaveDescr;

    lwaveDescr.chunkHead.id[0] = 'R';

    lwaveDescr.chunkHead.id[1] = 'I';

    lwaveDescr.chunkHead.id[2] = 'F';

    lwaveDescr.chunkHead.id[3] = 'F';

    lwaveDescr.chunkHead.size = 36 + lsizeData;


    lwaveDescr.wave[0] = 'W';

    lwaveDescr.wave[1] = 'A';

    lwaveDescr.wave[2] = 'V';

    lwaveDescr.wave[3] = 'E';







    __WAVEFORMAT lformat;

    lformat.chunkHead.id[0] = 'f';

    lformat.chunkHead.id[1] = 'm';

    lformat.chunkHead.id[2] = 't';

    lformat.chunkHead.id[3] = ' ';

    lformat.chunkHead.size = 16;


    lformat.format = 1;

    lformat.bitsPerSample = lreader.getBitsPerSample();

    lformat.blockAlign = lreader.getBlockAlign();

    lformat.byteRate = lreader.getByteRate();

    lformat.channels = lreader.getChannels();

    lformat.sampleRate = lreader.getByteRate() / lreader.getBlockAlign();




    __WAVEDESCRDATA ldata;

    ldata.chunkHead.id[0] = 'd';

    ldata.chunkHead.id[1] = 'a';

    ldata.chunkHead.id[2] = 't';

    ldata.chunkHead.id[3] = 'a';


    ldata.chunkHead.size = lsizeData;




    loutFile.write((char*)&lwaveDescr, sizeof(lwaveDescr));

    loutFile.write((char*)&lformat, sizeof(lformat));

    loutFile.write((char*)&ldata, sizeof(ldata));



    quint64 lwriteLength = lformat.blockAlign * 512;

    qint64 readLength = 0;


    std::unique_ptr<char> lbuffer;

    lbuffer.reset(new char[lwriteLength]);

    while(readLength < lsizeData)
    {
    //    std::cerr << "1" << std::endl;
        qint64 len = lreader.readData(lbuffer.get(), lwriteLength);

    //    std::cerr << "2" << std::endl;

        auto lptrBuffer = lbuffer.get();

        qint64 diff = len;

        while(diff > 0)
        {

            diff = diff - loutFile.write(lptrBuffer, diff);
        }

     //   std::cerr << "3" << std::endl;
        readLength += len;
    }

    loutFile.close();
}



MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget),
    _player(new AudioPlayer(this))
{
    ui->setupUi(this);

    Qt::WindowFlags flags = Qt::CustomizeWindowHint
            |Qt::WindowTitleHint
            |Qt::MSWindowsFixedSizeDialogHint
            |Qt::WindowCloseButtonHint;

    this->setWindowFlags(flags);

    connect(ui->openFileButton, SIGNAL(clicked()), SLOT(openFractalFile()));

    connect(ui->playButton, SIGNAL(clicked()), SLOT(play_pause()));

    connect(ui->stopButton, SIGNAL(clicked()), _player, SLOT(stop()));

    connect(ui->horizontalSlider, SIGNAL(sliderMoved(int)) , _player, SLOT(setTrackPosition(int)));

    connect(_player, SIGNAL(setRange(int,int)), ui->horizontalSlider, SLOT(setRange(int,int)));

    connect(_player, SIGNAL(getTrackPosition(int)), SLOT(setPositionTraker(int)));

    connect(_player, SIGNAL(finish()), SLOT(checkState()));






    connect(ui->saveIntoWAVEFilepushButton, SIGNAL(clicked()), SLOT(saveIntoWaveFile()));

    connect(ui->outputDevicesComboBox, SIGNAL(currentIndexChanged(int)), SLOT(changeOutputDevice(int)));

    connect(ui->selectOutFrequencyComboBox, SIGNAL(currentIndexChanged(int)), SLOT(changeFrequency(int)));

    connect(ui->bitsPerSampleComboBox, SIGNAL(currentIndexChanged(int)), SLOT(changeOutputBitsPerSample(int)));



    const QAudioDeviceInfo &defaultDeviceInfo = QAudioDeviceInfo::defaultOutputDevice();

    ui->outputDevicesComboBox->addItem(defaultDeviceInfo.deviceName(), qVariantFromValue(defaultDeviceInfo));

    for (const QAudioDeviceInfo &deviceInfo: QAudioDeviceInfo::availableDevices(QAudio::AudioOutput))
    {
        if (deviceInfo != defaultDeviceInfo)
            ui->outputDevicesComboBox->addItem(deviceInfo.deviceName(), qVariantFromValue(deviceInfo));
    }
}

MainWidget::~MainWidget()
{
    _player->stop();

    delete ui;
}

void MainWidget::openFractalFile()
{
    QString filePath = QFileDialog::getOpenFileName(
                this,
                QObject::tr("Open 'Fractal' or old format 'WAVE' File"),
                QDir::homePath() + "/Documents",
                QObject::tr("*.wave (*.wav)"));

    ui->saveIntoWAVEFilepushButton->setEnabled(false);

    _filePath = filePath;

    updateAudioPlayer();
}

void MainWidget::updateAudioPlayer()
{

    if(!QFile::exists(_filePath))
        return;

    auto lFractalInfo = AudioPlayer::getFractalInfo(_filePath);

    if(!lFractalInfo)
        return;

    _player->stop();


    ui->outputFrequencyPanel->setEnabled(true);

    ui->outputBitsPerSamplePanel->setEnabled(true);

    ui->selectingOutputDevicePanel->setEnabled(true);

    ui->controlPanel->setEnabled(true);




    ui->bitsPerSampleComboBox->clear();

    if((*lFractalInfo)._originalBitsPerSample > 8)
    {
        quint32 lStep = (*lFractalInfo)._originalBitsPerSample;

        while(lStep <= 32)
        {
            ui->bitsPerSampleComboBox->addItem(QString("%1 Bits").arg(lStep), lStep);

            lStep *= 2;
        }

    }
    else
    {
        ui->bitsPerSampleComboBox->addItem(QString("%1 Bits").arg((*lFractalInfo)._originalBitsPerSample), (*lFractalInfo)._originalBitsPerSample);
    }


    QAudioDeviceInfo lAudioDeviceInfo = ui->outputDevicesComboBox->currentData().value<QAudioDeviceInfo>();

    QList<int> listSupportSampleRates = lAudioDeviceInfo.supportedSampleRates();

    if(listSupportSampleRates.count() == 0)
        return;

    ui->selectOutFrequencyComboBox->clear();

    int lLowScaleFrequency = 1;

    while(true)
    {
        if((*lFractalInfo)._originalFrequency * lLowScaleFrequency >= listSupportSampleRates.at(0))
            break;

        lLowScaleFrequency *= 2;
    }

    for(decltype(lLowScaleFrequency) stepFrequency = lLowScaleFrequency;
        (*lFractalInfo)._originalFrequency * stepFrequency <= listSupportSampleRates.at(listSupportSampleRates.count() - 1);
        stepFrequency *= 2)
    {
        ui->selectOutFrequencyComboBox->addItem(QString("%1 Hz").arg((*lFractalInfo)._originalFrequency * stepFrequency), stepFrequency);
    }





    ui->saveIntoWAVEFilepushButton->setEnabled(true);

    _player->setFilePath(_filePath, ui->selectOutFrequencyComboBox->currentData().value<quint32>(),
                         ui->bitsPerSampleComboBox->currentData().value<quint32>(),
                         ui->outputDevicesComboBox->currentData().value<QAudioDeviceInfo>());

}

void MainWidget::setPositionTraker(int value)
{

    ui->horizontalSlider->setSliderPosition(value);

}


void MainWidget::play_pause()
{
    _player->pause();

    checkState();
}

void MainWidget::checkState()
{

    if(_player->getState() == QAudio::ActiveState)
        ui->playButton->setText("Pause");
    else
        ui->playButton->setText("Play");
}

void MainWidget::saveIntoWaveFile()
{
    QString filePath = QFileDialog::getSaveFileName(
                this,
                QObject::tr("Save into 'WAVE' File"),
                QDir::homePath() + "/Documents",
                QObject::tr("*.wave (*.wav)"));

    convert(_filePath, filePath,  ui->selectOutFrequencyComboBox->currentData().value<quint32>(), ui->bitsPerSampleComboBox->currentData().value<quint32>());
}

void MainWidget::changeOutputDevice(int)
{

    updateAudioPlayer();

}

void MainWidget::changeFrequency(int)
{

    if(!QFile::exists(_filePath))
        return;

    _player->stop();

    _player->setFilePath(_filePath, ui->selectOutFrequencyComboBox->currentData().value<quint32>(), ui->bitsPerSampleComboBox->currentData().value<quint32>(),
                         ui->outputDevicesComboBox->currentData().value<QAudioDeviceInfo>());
}

void MainWidget::changeOutputBitsPerSample(int)
{

    if(!QFile::exists(_filePath))
        return;

    _player->stop();

    _player->setFilePath(_filePath, ui->selectOutFrequencyComboBox->currentData().value<quint32>(), ui->bitsPerSampleComboBox->currentData().value<quint32>(),
                         ui->outputDevicesComboBox->currentData().value<QAudioDeviceInfo>());

}
