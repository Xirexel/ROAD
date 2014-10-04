#ifndef IREADER_H
#define IREADER_H


#include <QObject>



class QDataStream;


class IReader: public QObject
{
    Q_OBJECT

public:

    IReader(QDataStream *dataStream, QObject *parent = 0)
        : QObject(parent),
          _dataStream(dataStream)
    {}

    virtual qint64 readData(char *data, qint64 maxlen)=0;

    virtual qint64 getSampleAmount()=0;

    virtual void setPosition(qint64 position)=0;

    virtual void decode(){}

protected:

    QDataStream *_dataStream;

signals:

    void finish();

    void pos(qint64 value);

};

#endif // IREADER_H
