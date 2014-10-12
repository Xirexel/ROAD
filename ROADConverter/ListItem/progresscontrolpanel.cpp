#include "progresscontrolpanel.h"
#include "ui_progresscontrolpanel.h"

ProgressControlPanel::ProgressControlPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProgressControlPanel)
{
    ui->setupUi(this);
}

ProgressControlPanel::~ProgressControlPanel()
{
    delete ui;
}
