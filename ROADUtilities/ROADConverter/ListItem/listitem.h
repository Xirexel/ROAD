#ifndef LISTITEM_H
#define LISTITEM_H

#include <QWidget>
#include <QVarLengthArray>
#include <memory>

#include "listitem_global.h"
#include "interfaces.h"

namespace Ui {
class ListItem;
}


namespace ROADcoder
{
    namespace ROADoverCoder
    {
        class IROADoverEncodingOptions;
    }
}

class EncodingThread;
class IReader;

class LISTITEMSHARED_EXPORT ListItem : public QWidget
{
    Q_OBJECT

public:

    enum TypeSource
    {
        WAVE
    };

    explicit ListItem(TypeSource aTypeSource,
                      QVarLengthArray<IROADoverCoderFactory *> vPtrIROADoverCoderFactory,
                      QString filePath,
                      unsigned int aROADoverCoderOptions,
                      QWidget *parent = 0);
    ~ListItem();

private:
    Ui::ListItem *ui;

    QString _filePath;

    QString _outputFilePath;

    TypeSource _typeROADoverCoder;

    QVarLengthArray<IROADoverCoderFactory *> _vPtrIROADoverCoderFactoryCollection;

    std::unique_ptr<EncodingThread> _smartPTREncodingThread;

    std::unique_ptr<IReader> _smartPTRIReader;

    std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> _optionsROADoverCoder;

private slots:


    void startEncoding();

    void breakEncoding();

    void enableItem();

    void updatePercentage();

    void showOptions();

    void updateOptions(std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> &aOptionsROADoverCoder);

signals:

    void updateVisual();

    void deleteFromList();


};

#endif // LISTITEM_H
