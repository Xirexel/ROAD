#ifndef ENCODINGTHREAD_H
#define ENCODINGTHREAD_H

#include <QThread>
#include <memory>


#include "interfaces.h"

class EncodingThread : public QThread
{
    Q_OBJECT
public:
    explicit EncodingThread(IROADoverCoder * aPtrIROADoverCoder,QObject *parent = 0);

protected:

    void run()Q_DECL_OVERRIDE;

signals:

    void updatePercentageProgress();


public slots:
    void interept();


private:

    std::unique_ptr<IROADoverCoder> _smartPtrIROADoverCoder;

};

#endif // ENCODINGTHREAD_H
