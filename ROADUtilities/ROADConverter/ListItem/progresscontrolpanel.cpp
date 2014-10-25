#include "progresscontrolpanel.h"
#include "ui_progresscontrolpanel.h"

ProgressControlPanel::ProgressControlPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProgressControlPanel)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose);

    connect(ui->interuptpushButton, SIGNAL(clicked()), SIGNAL(interept()));
}

ProgressControlPanel::~ProgressControlPanel()
{
    delete ui;
}

void ProgressControlPanel::setProgressValue(qint32 value)
{
    ui->progressBar->setValue(value);
}
