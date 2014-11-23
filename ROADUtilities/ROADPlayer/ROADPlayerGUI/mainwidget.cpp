#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "audioplayer.h"

#include <QFile>
#include <QFileDialog>
#include <memory>


#include "../ROADoverWAVE/wavefractal_parser.h"
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
        qint64 len = lreader.readData(lbuffer.get(), lwriteLength);

        loutFile.write(lbuffer.get(), len);

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

    connect(ui->playButton, SIGNAL(clicked()), _player, SLOT(start()));
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::openFractalFile()
{

    QString filePath = QFileDialog::getOpenFileName(
                this,
                QObject::tr("Open 'Fractal' or old format 'WAVE' File"),
                QDir::homePath() + "/Documents",
                QObject::tr("*.wave (*.wav)"));

    if(!QFile::exists(filePath))
        return;

    convert(filePath, QString(QDir::homePath() + "/Documents/1.wav"), 4, 16);

//    _player->setFilePath(filePath, 4, 32, QAudioDeviceInfo::defaultOutputDevice());

//    _player->start();
}

