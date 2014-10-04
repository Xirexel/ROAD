#include "progressprocessingwidget.h"
#include "ui_progressprocessingwidget.h"

ProgressProcessingWidget::ProgressProcessingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProgressProcessingWidget)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    connect(ui->pushButton, SIGNAL(clicked()), SIGNAL(interept()));

    Qt::WindowFlags flags = Qt::CustomizeWindowHint|Qt::WindowTitleHint|Qt::MSWindowsFixedSizeDialogHint;

    this->setWindowFlags(flags);

}

ProgressProcessingWidget::~ProgressProcessingWidget()
{
    delete ui;
}

void ProgressProcessingWidget::setProgressValue(quint32 value)
{
    ui->progressBar->setValue(value);
}
