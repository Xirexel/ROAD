#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QCloseEvent>
#include <QFileDialog>

#include "listitemsmodel.h"
#include "optionswidget.h"


MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget),
    _ptrOptionsWidget(new OptionsWidget)
{
    ui->setupUi(this);

    connect(ui->addfilespushButton, SIGNAL(clicked()), SLOT(addFiles()));

    connect(ui->optionspushButton, SIGNAL(clicked()), SLOT(openOptionsWidget()));

    connect(_ptrOptionsWidget, SIGNAL(updateModelOptions()), SLOT(updateModelOptions()));

    Qt::WindowFlags flags = Qt::CustomizeWindowHint
            |Qt::WindowShadeButtonHint;

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

void MainWidget::addFiles()
{
    QStringList listFilesPath = QFileDialog::getOpenFileNames(
                this,
                QObject::tr("Add Audio Files"),
                "/home",
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
