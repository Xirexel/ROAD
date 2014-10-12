#include "listitem.h"
#include "ui_listitem.h"
#include <QFileInfo>
#include <QPixmap>


ListItem::ListItem(TypeROADoverCoder typeROADoverCoder, QString filePath, QWidget *parent)
    : QWidget(parent),
      ui(new Ui::ListItem),
      _filePath(filePath),
      _typeROADoverCoder(typeROADoverCoder)
{
    ui->setupUi(this);

    QFileInfo lQFileInfo(filePath);

    ui->fileNameLabel->setText(lQFileInfo.baseName());

    switch(typeROADoverCoder)
    {
    case ROADoverWAVECoder:

        ui->iconLabel->setPixmap(QPixmap(":/images/Wav.png").scaled(ui->iconLabel->sizeHint(),Qt::KeepAspectRatioByExpanding));

        break;

    }

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
