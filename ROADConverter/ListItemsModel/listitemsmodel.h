#ifndef LISTITEMSMODEL_H
#define LISTITEMSMODEL_H

#include <QAbstractListModel>
#include <QAbstractItemView>


#include "listitemsmodel_global.h"

#include "modeloptions.h"

class ListItem;


class LISTITEMSMODELSHARED_EXPORT ListItemsModel: public QAbstractListModel
{
    Q_OBJECT


public:
    explicit ListItemsModel(QAbstractItemView* itemView, QObject *parent = 0);
    virtual ~ListItemsModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role) const;

    QStringList mimeTypes() const;

    Qt::ItemFlags flags(const QModelIndex &index) const;

    bool dropMimeData(const QMimeData *data,
        Qt::DropAction action, int row, int column, const QModelIndex &parent);

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

    bool checkWaveFile(QString file);

};

#endif // LISTITEMSMODEL_H
