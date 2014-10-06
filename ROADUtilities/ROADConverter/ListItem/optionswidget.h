#ifndef OPTIONSWIDGET_H
#define OPTIONSWIDGET_H


#include <memory>


#include <QWidget>
#include <QMap>


namespace ROADcoder
{
    namespace ROADoverCoder
    {
        class IROADoverEncodingOptions;
    }
}


namespace Ui {
class OptionsWidget;
}

class OptionsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OptionsWidget(std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> &aOptionsROADoverCoder, QWidget *parent = 0);
    ~OptionsWidget();

private:
    Ui::OptionsWidget *ui;

    QMap<QString, unsigned int> m_dicROADFormats;

    std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> _optionsROADoverCoder;

    void setEncodingOptionsWidget(std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> &aOptionsROADoverCoder);

signals:

    void updateOptions(std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> &_optionsROADoverCoder);

    void closeWidget();

private slots:
    void updateEncodingOptionsWidget(QString aIndex);

    void updateState(bool aState);

    void confirmOptions();
};

#endif // OPTIONSWIDGET_H
