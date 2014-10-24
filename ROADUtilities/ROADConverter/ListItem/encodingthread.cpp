#include "encodingthread.h"


#include "interfaces.h"


EncodingThread::EncodingThread(IROADoverCoder *aPtrIROADoverCoder, QObject *parent) :
    QThread(parent)
{
    _smartPtrIROADoverCoder.reset(aPtrIROADoverCoder);
}

void EncodingThread::run()
{
    Result result = ERROR;

    bool isRunning = true;

    while(isRunning)
    {
        result =_smartPtrIROADoverCoder->doEncoding();

        switch(result)
        {
            case ERROR:
            {
                isRunning = false;
            }
            break;

            case DONE:
            break;

        case FINISHFILE:
            {
                isRunning = false;
            }
            break;
        }

        emit updatePercentageProgress();

        if (QThread::currentThread()->isInterruptionRequested())
        {
            result = ERROR;

            break;
        }
    }


    if(result == ERROR)
    {
        _smartPtrIROADoverCoder->reject();
    }
    else
    {
        _smartPtrIROADoverCoder->flushAndCloseFile();
    }

}

void EncodingThread::interept()
{
    this->requestInterruption();
}
