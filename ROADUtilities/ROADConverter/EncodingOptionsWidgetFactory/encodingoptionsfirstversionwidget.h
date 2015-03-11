#ifndef ENCODINGOPTIONSFIRSTVERSIONWIDGET_H
#define ENCODINGOPTIONSFIRSTVERSIONWIDGET_H

#include <QWidget>

#include <memory>


#include "encodingoptionswidget.h"
#include "ROADoverEncodingOptionsFirstVersion.h"

namespace Ui {
class EncodingOptionsFirstVersionWidget;
}

class EncodingOptionsFirstVersionWidget : public EncodingOptions::EncodingOptionsWidget
{
    Q_OBJECT

public:
    explicit EncodingOptionsFirstVersionWidget(std::unique_ptr<ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion>& aOptions, QWidget *parent = 0);
    ~EncodingOptionsFirstVersionWidget();

    std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> getEncodingOptions();

public slots:

    virtual void setState();

private:
    Ui::EncodingOptionsFirstVersionWidget *ui;

    std::unique_ptr<ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion> m_options;


};

#endif // ENCODINGOPTIONSFIRSTVERSIONWIDGET_H
