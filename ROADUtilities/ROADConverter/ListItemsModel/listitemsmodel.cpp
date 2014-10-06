#include "listitemsmodel.h"
#include <QStringListModel>
#include <QMimeData>
#include <QUrl>
#include <QFile>
#include <QDir>
#include <QPluginLoader>



#include "listitem.h"



ListItemsModel::ListItemsModel(QAbstractItemView* itemView, QObject *parent)
    : QAbstractListModel(parent),
      _itemView(itemView)
{
    _rootIndex = createIndex(0, 0);

    updatePluginsCollection(_modelOptions.getPluginROADoverCodersDirPath());
}

ListItemsModel::~ListItemsModel()
{
    clearIROADoverCoderPluginCollection();
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
    ListItem::TypeSource lTypeROADoverCoder;

    if(!checkWaveFile(filePath))
        return;
    else
        lTypeROADoverCoder = ListItem::WAVE;

    int row = _list.count();

    beginInsertRows(QModelIndex(), row, row);

    ListItem* item = new ListItem(lTypeROADoverCoder, this->_vPtrIROADoverCoderPluginCollection, filePath, _modelOptions.getROADoverCoderOptions() );

    _list.append(item);

    connect(item, SIGNAL(updateVisual()), SLOT(updateLayout()));

    connect(item, SIGNAL(deleteFromList()), SLOT(deleteListItem()));

    endInsertRows();

    _itemView->setIndexWidget(index(row, 0), item);

    changePersistentIndex(QModelIndex(), index(row, 0));

    emit layoutChanged();

}

void ListItemsModel::updateLayout()
{
    emit layoutAboutToBeChanged();

    changePersistentIndex(QModelIndex(), index(_list.count(), 0));

    emit layoutChanged();
}

void ListItemsModel::deleteListItem()
{
    QObject * senderQObject = sender();

    ListItem* item = qobject_cast<ListItem*>(senderQObject);

    if(item == nullptr)
        return;

    qint32 index = this->_list.indexOf(item);

    if(index == -1)
        return;

    removeRows(index, 1, QModelIndex());

    updateLayout();

}

Qt::DropActions ListItemsModel::supportedDropActions() const
{
    return Qt::CopyAction;
}

bool ListItemsModel::dropMimeData(const QMimeData *data,
    Qt::DropAction action, int, int, const QModelIndex &)
{
    if (action == Qt::IgnoreAction)
        return true;
bool Result = false;
    if (action == Qt::CopyAction &&  data->hasUrls())
    {

       QList<QUrl> lListQUrt = data->urls();

       for(QUrl lUrl: lListQUrt)
       {
           if(lUrl.isValid() && lUrl.isLocalFile())
           {
               addAudioFile(lUrl.toLocalFile());
               Result = true;
           }
       }

    }
    return Result;    //  is this right?
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


Qt::ItemFlags ListItemsModel::flags(const QModelIndex &) const
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

void ListItemsModel::clearIROADoverCoderPluginCollection()
{
    for(IROADoverCoderPlugin * item: _vPtrIROADoverCoderPluginCollection)
    {
        delete item;
    }

    _vPtrIROADoverCoderPluginCollection.clear();
}

void ListItemsModel::updatePluginsCollection(QString pluginDirPath)
{

    clearIROADoverCoderPluginCollection();


    QDir lpluginsDir(pluginDirPath);

    foreach (QString fileName, lpluginsDir.entryList(QDir::Files))
    {
        QPluginLoader loader(lpluginsDir.absoluteFilePath(fileName));

        QObject *plugin = loader.instance();

        if (plugin)
        {

            IROADoverCoderPlugin *lptrIROADoverCoderPlugin = qobject_cast<IROADoverCoderPlugin *>(plugin);

            if (lptrIROADoverCoderPlugin)
                _vPtrIROADoverCoderPluginCollection.append(lptrIROADoverCoderPlugin);

        }
    }

}
