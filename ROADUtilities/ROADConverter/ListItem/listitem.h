#ifndef LISTITEM_H
#define LISTITEM_H

#include <QWidget>
#include <QVarLengthArray>
#include <memory>

#include "listitem_global.h"
#include "interfaces.h"
#include "roadovercoderoptions.h"

namespace Ui {
class ListItem;
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
                      QVarLengthArray<IROADoverCoderPlugin *> vPtrIROADoverCoderPlugin,
                      QString filePath,
                      ROADoverCoderOptions aROADoverCoderOptions,
                      QWidget *parent = 0);
    ~ListItem();

private:
    Ui::ListItem *ui;

    QString _filePath;

    QString _outputFilePath;

    TypeSource _typeROADoverCoder;

    QVarLengthArray<IROADoverCoderPlugin *> _ptrIROADoverCoderPluginCollection;

    std::unique_ptr<EncodingThread> _smartPTREncodingThread;

    std::unique_ptr<IReader> _smartPTRIReader;

    ROADoverCoderOptions _optionsROADoverCoder;

private slots:


    void startEncoding();

    void breakEncoding();

    void enableItem();

    void updatePercentage();

signals:

    void updateVisual();

    void deleteFromList();


};

#endif // LISTITEM_H
