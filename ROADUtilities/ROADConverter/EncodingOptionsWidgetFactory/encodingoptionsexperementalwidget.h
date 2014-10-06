#ifndef ENCODINGOPTIONSEXPEREMENTALWIDGET_H
#define ENCODINGOPTIONSEXPEREMENTALWIDGET_H


#include <memory>


#include "encodingoptionswidget.h"
#include "ROADoverEncodingOptionsExperemental.h"




namespace Ui {
class EncodingOptionsExperementalWidget;
}

class EncodingOptionsExperementalWidget : public EncodingOptions::EncodingOptionsWidget
{
    Q_OBJECT

public:
    explicit EncodingOptionsExperementalWidget(std::unique_ptr<ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental>& aOptions, QWidget *parent = 0);

    ~EncodingOptionsExperementalWidget();

    std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> getEncodingOptions();

public slots:

    virtual void setState();

private:
    Ui::EncodingOptionsExperementalWidget *ui;

    std::unique_ptr<ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental> m_options;
};


#endif // ENCODINGOPTIONSEXPEREMENTALWIDGET_H
