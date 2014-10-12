#include "listitemsmodel.h"
#include <QStringListModel>
#include <QMimeData>
#include <QUrl>
#include <QFile>



#include "listitem.h"



ListItemsModel::ListItemsModel(QAbstractItemView* itemView, QObject *parent)
    : QAbstractListModel(parent),
      _itemView(itemView)
{
    _rootIndex = createIndex(0, 0);
}

ListItemsModel::~ListItemsModel()
{
}

int ListItemsModel::rowCount(const QModelIndex &parent) const
{
    return (parent.isValid()) ? 0 : _list.count();
}

QVariant ListItemsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::SizeHintRole)
    {
        if(index.row() <0)
            return QVariant();

        return _list.at(index.row())->sizeHint();
    }

    if (role != Qt::DisplayRole)
        return QVariant();

    if (index.row() < 0 || index.row() >= rowCount(index.parent()))
        return QVariant();

    return QVariant();
}

void ListItemsModel::addAudioFile(QString filePath)
{
    ListItem::TypeROADoverCoder lTypeROADoverCoder;

    if(!checkWaveFile(filePath))
        return;
    else
        lTypeROADoverCoder = ListItem::ROADoverWAVECoder;

    int row = _list.count();

    beginInsertRows(QModelIndex(), row, row);

    ListItem* item = new ListItem(lTypeROADoverCoder, filePath);

    _list.append(item);

    endInsertRows();

    _itemView->setIndexWidget(index(row, 0), item);

    changePersistentIndex(QModelIndex(), index(row, 0));

    emit layoutChanged();

}

Qt::DropActions ListItemsModel::supportedDropActions() const
{
    return Qt::CopyAction;
}

bool ListItemsModel::dropMimeData(const QMimeData *data,
    Qt::DropAction action, int row, int column, const QModelIndex &parent)
{
    if (action == Qt::IgnoreAction)
        return true;

    if (action == Qt::CopyAction &&  data->hasUrls())
    {
       QList<QUrl> lListQUrt = data->urls();

       for(QUrl lUrl: lListQUrt)
       {
           if(lUrl.isValid() && lUrl.isLocalFile())
           {
               addAudioFile(lUrl.toLocalFile());
           }
       }
    }
}

bool ListItemsModel::removeRows(int row, int count, const QModelIndex &parent)
{

    if (parent.isValid())
        return false;

    int lastRow = row + count - 1;

    for (int i = lastRow; i >= row; --i)
    {
        beginRemoveRows(parent, i, i);

        _list.takeAt(i)->deleteLater();

        endRemoveRows();
    }

    return true;
}


Qt::ItemFlags ListItemsModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsDropEnabled;
}

QStringList ListItemsModel::mimeTypes() const
{
    QStringList types;

    types << "text/uri-list";

    return types;
}

bool ListItemsModel::checkWaveFile(QString file)
{
    bool result = false;

    QFile lQFile(file);

    do
    {
        if(!lQFile.open(QIODevice::ReadOnly))
            break;

        QDataStream dataStream(&lQFile);

        qint8 id[4];   // идентификатор типа файла

        quint32 size;   // размер оставшейся части файла

        int lReadLength = dataStream.readRawData((char *)id, 4);

        if(!lReadLength == 4)
            break;

        if(id[0] != 'R'
                || id[1] != 'I'
                || id[2] != 'F'
                || id[3] != 'F')
            break;

        dataStream >> size;

        lReadLength = dataStream.readRawData((char *)id, 4);

        if(!lReadLength == 4)
            break;

        if(id[0] != 'W'
                || id[1] != 'A'
                || id[2] != 'V'
                || id[3] != 'E')
            break;

        lQFile.seek(size - 4);

        if(!lQFile.atEnd())
            break;

        result = true;

    }
    while(false);

    lQFile.close();

    return result;
}


void ListItemsModel::updateModelOptions(ModelOptions modelOptions)
{
    this->_modelOptions = modelOptions;
}
