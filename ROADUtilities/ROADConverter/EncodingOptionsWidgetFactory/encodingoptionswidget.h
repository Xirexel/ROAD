#ifndef ENCODINGOPTIONSWIDGET_H
#define ENCODINGOPTIONSWIDGET_H

#include <QWidget>
#include <memory>


//#include "IROADoverEncodingOptions.h"


namespace ROADcoder
{
    namespace ROADoverCoder
    {
        class IROADoverEncodingOptions;
    }
}

namespace EncodingOptions {

class EncodingOptionsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit EncodingOptionsWidget(QWidget *parent = 0);

    virtual std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> getEncodingOptions() = 0;

signals:

    void updatedState(bool aState);

public slots:

    virtual void setState() = 0;

};

}

#endif // ENCODINGOPTIONSWIDGET_H
