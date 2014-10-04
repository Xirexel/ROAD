#ifndef PROCESSINGTHREAD_H
#define PROCESSINGTHREAD_H

#include <QObject>
#include <QThread>
#include <memory>



struct FractalOptions
{
    quint32 _frameSampleLength;

    quint32 _superFrameLength;

    quint32 _widestRangeLength;

    quint32 _smallestRangeLength;

    quint32 _relativeDomainShift;

    enum MixingChannelMode
    {
        LPLUSR, LMINUSR, NONE

    } _mixingChannelMode;

};


class ProcessingThread : public QThread
{
    Q_OBJECT
public:
    explicit ProcessingThread(QObject *parent = 0);

    void setFractalEncoderOptions(QString waveFilePath,
                                  QString waveFractalFilePath,
                                  FractalOptions fractalOptions);

private:

    QString _waveFilePath;
    QString _waveFractalFilePath;

    FractalOptions _fractalOptions;

protected:
    virtual void run();

signals:
    void progressValue(quint32 value);

    void elapsedTime(float time);


public slots:
    void interept();


};

#endif // PROCESSINGTHREAD_H
