#ifndef LISTITEMSMODEL_H
#define LISTITEMSMODEL_H

#include <QAbstractListModel>
#include <QAbstractItemView>


#include "listitemsmodel_global.h"

#include "modeloptions.h"

class ListItem;
class IROADoverCoderPlugin;


class LISTITEMSMODELSHARED_EXPORT ListItemsModel: public QAbstractListModel
{
    Q_OBJECT


public:
    explicit ListItemsModel(QAbstractItemView* itemView, QObject *parent = 0);
    virtual ~ListItemsModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role) const;

    QStringList mimeTypes() const;

    Qt::ItemFlags flags(const QModelIndex &) const;

    bool dropMimeData(const QMimeData *data,
        Qt::DropAction action, int, int, const QModelIndex &);

    bool removeRows(int row, int count, const QModelIndex &parent);

    Qt::DropActions supportedDropActions() const;

    void addAudioFile(QString filePath);

    void updateModelOptions(ModelOptions modelOptions);

private:

    Q_DISABLE_COPY(ListItemsModel)

    QAbstractItemView* _itemView;

    QModelIndex _rootIndex;

    QList<ListItem*> _list;

    ModelOptions _modelOptions;

    QVarLengthArray<IROADoverCoderPlugin *> _vPtrIROADoverCoderPluginCollection;



    bool checkWaveFile(QString file);

    void updatePluginsCollection(QString pluginDirPath);

    void clearIROADoverCoderPluginCollection();

private slots:

    void updateLayout();

    void deleteListItem();

};

#endif // LISTITEMSMODEL_H
