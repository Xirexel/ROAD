#include "progresscontrolpanel.h"
#include "ui_progresscontrolpanel.h"


ProgressControlPanel::ProgressControlPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProgressControlPanel)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose);

    connect(ui->interuptpushButton, SIGNAL(clicked()), SIGNAL(interept()));

    mTime.start();
}

ProgressControlPanel::~ProgressControlPanel()
{
    delete ui;
}

void ProgressControlPanel::setProgressValue(qint32 value)
{
    auto ldiff = value - ui->progressBar->value();

    if(ldiff > 0)
    {
        auto lcurrentTime = mTime.restart();

        float ltimeQuant = ((float)lcurrentTime)/((float) ldiff);

        float lsub = 100 - value;

        float lestTime = (ltimeQuant * lsub) / 1000.0f;

        ui->mEstimatedTimeLabel->setText(QString("Esimated time: %1 sec").arg(lestTime, 0, 'f', 2));
    }

    ui->progressBar->setValue(value);
}
