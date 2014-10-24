#include "listitem.h"
#include "ui_listitem.h"
#include <QFileInfo>
#include <QPixmap>


ListItem::ListItem(TypeSource aTypeSource,
                   QVarLengthArray<IROADoverCoderPlugin *> vPtrIROADoverCoderPlugin,
                   QString filePath,
                   QWidget *parent)
    : QWidget(parent),
      ui(new Ui::ListItem),
      _filePath(filePath),
      _typeROADoverCoder(aTypeSource),
      _ptrIROADoverCoderPluginCollection(vPtrIROADoverCoderPlugin)
{
    ui->setupUi(this);

    QFileInfo lQFileInfo(filePath);

    ui->fileNameLabel->setText(lQFileInfo.baseName());

    switch(aTypeSource)
    {
    case WAVE:

        ui->iconLabel->setPixmap(QPixmap(":/images/Wav.png").scaled(ui->iconLabel->sizeHint(),Qt::KeepAspectRatioByExpanding));

        break;

    }

    for(IROADoverCoderPlugin * item: vPtrIROADoverCoderPlugin)
        ui->comboBoxROADoverCoder->addItem(item->name());

}

ListItem::~ListItem()
{
    delete ui;
}

void ListItem::startEncoding()
{

}

void ListItem::breakEncoding()
{

}
