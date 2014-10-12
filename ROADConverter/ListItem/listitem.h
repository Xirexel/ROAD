#ifndef LISTITEM_H
#define LISTITEM_H

#include <QWidget>

#include "listitem_global.h"

namespace Ui {
class ListItem;
}

class LISTITEMSHARED_EXPORT ListItem : public QWidget
{
    Q_OBJECT

public:

    enum TypeROADoverCoder
    {
        ROADoverWAVECoder
    };

    explicit ListItem(TypeROADoverCoder typeROADoverCoder, QString filePath, QWidget *parent = 0);
    ~ListItem();

    void startEncoding();

    void breakEncoding();

private:
    Ui::ListItem *ui;

    QString _filePath;

    TypeROADoverCoder _typeROADoverCoder;
};

#endif // LISTITEM_H
