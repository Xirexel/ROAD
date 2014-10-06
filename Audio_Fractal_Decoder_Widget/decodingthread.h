#ifndef DECODINGTHREAD_H
#define DECODINGTHREAD_H

#include <QThread>

class IReader;

class DecodingThread : public QThread
{
    Q_OBJECT
public:
    explicit DecodingThread(IReader *parent = 0);

protected:

    virtual void run();

private:

    IReader *_reader;

signals:

public slots:

};

#endif // DECODINGTHREAD_H
