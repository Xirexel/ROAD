#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QCloseEvent>
#include <QFileDialog>
#include <QMouseEvent>

#include "listitemsmodel.h"
#include "optionswidget.h"


MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget),
    _ptrOptionsWidget(new OptionsWidget),
    _pressLeftButtonMouse(false)

{
    ui->setupUi(this);

    setMouseTracking(false);

    connect(ui->addfilespushButton, SIGNAL(clicked()), SLOT(addFiles()));

    connect(ui->optionspushButton, SIGNAL(clicked()), SLOT(openOptionsWidget()));

    connect(_ptrOptionsWidget, SIGNAL(updateModelOptions()), SLOT(updateModelOptions()));


    Qt::WindowFlags flags = Qt::FramelessWindowHint;

    this->setWindowFlags(flags);

    QItemSelectionModel *m = ui->listAudioTrackView->selectionModel();

    _ptrListItemsModel = new ListItemsModel(ui->listAudioTrackView, this);

    ui->listAudioTrackView->setModel(_ptrListItemsModel);

    delete m;

}

MainWidget::~MainWidget()
{
    _ptrOptionsWidget->close();

    delete _ptrOptionsWidget;

    delete ui;
}

void MainWidget::closeEvent(QCloseEvent *event)
{
    event->accept();
}

void MainWidget::mousePressEvent(QMouseEvent * event)
{
    if(event->button() == Qt::LeftButton)
    {
        _pressLeftButtonMouse = true;

        _prevPosition = event->globalPos();
    }
}

void MainWidget::mouseReleaseEvent(QMouseEvent * event)
{
    if(event->button() == Qt::LeftButton)
    {
        _pressLeftButtonMouse = false;
    }
}

void MainWidget::mouseMoveEvent(QMouseEvent * event)
{
    if(_pressLeftButtonMouse)
    {
        QPoint diff = _prevPosition - event->globalPos();

        this->move(this->pos()-=diff);

         _prevPosition = event->globalPos();
    }
}

void MainWidget::addFiles()
{


    QStringList listFilesPath = QFileDialog::getOpenFileNames(
                this,
                QObject::tr("Add Audio Files"),
                QDir::homePath() + "/Documents",
                QObject::tr("Audio formats (*.wav *.wave)"));

    QStringList::Iterator it = listFilesPath.begin();

    while(it != listFilesPath.end()) {
        _ptrListItemsModel->addAudioFile(*it);
        ++it;
    }
}

void MainWidget::openOptionsWidget()
{
    _ptrOptionsWidget->show();
}

void MainWidget::updateModelOptions()
{
    _ptrListItemsModel->updateModelOptions(_ptrOptionsWidget->getModelOptions());
}
