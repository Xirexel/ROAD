#include <QHBoxLayout>


#include "mainwidget.h"
#include "audiofractalencoderwidget.h"
#include "audiofractaldecoderwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout *lQHBoxLayout = new QHBoxLayout;

    this->setLayout(lQHBoxLayout);

    lQHBoxLayout->addWidget(new AudioFractalEncoderWidget);

    lQHBoxLayout->addWidget(new AudioFractalDecoderWidget);

    Qt::WindowFlags flags = Qt::CustomizeWindowHint
            |Qt::WindowTitleHint
            |Qt::MSWindowsFixedSizeDialogHint
            |Qt::WindowCloseButtonHint;

    this->setWindowFlags(flags);

    this->updateGeometry();

    QSize lHintSize = this->sizeHint();

    if(lHintSize.isValid())
    {
        this->resize(lHintSize);
    }

}

MainWidget::~MainWidget()
{

}
