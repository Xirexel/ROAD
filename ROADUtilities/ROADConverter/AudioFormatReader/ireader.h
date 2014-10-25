#ifndef IREADER_H
#define IREADER_H

#include <QObject>

class IROADoverRawReader;
class IOriginalAudioStreamOptions;

class IReader : public QObject
{
    Q_OBJECT
public:
    explicit IReader(QObject *parent = 0) :
        QObject(parent)
    {
    }

    virtual ~IReader(){}

    virtual qint32 getPercentOfProcessedFile() = 0;

    virtual bool isOpen() = 0;

    virtual void setAtBegin() = 0;

    virtual IROADoverRawReader *getIROADoverRawReader() = 0;

    virtual IOriginalAudioStreamOptions *getIOriginalAudioStreamOptions() = 0;

signals:

public slots:

};

#endif // IREADER_H
