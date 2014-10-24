#ifndef LISTITEM_H
#define LISTITEM_H

#include <QWidget>
#include <QVarLengthArray>

#include "listitem_global.h"
#include "interfaces.h"

namespace Ui {
class ListItem;
}

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
                      QWidget *parent = 0);
    ~ListItem();

    void startEncoding();

    void breakEncoding();

private:
    Ui::ListItem *ui;

    QString _filePath;

    TypeSource _typeROADoverCoder;

    QVarLengthArray<IROADoverCoderPlugin *> _ptrIROADoverCoderPluginCollection;
};

#endif // LISTITEM_H
