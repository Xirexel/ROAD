#ifndef FRACTALTOWAVECONVERTER_H
#define FRACTALTOWAVECONVERTER_H

#include <QObject>


class FractalToWaveConverter : public QObject
{
    Q_OBJECT
public:
    explicit FractalToWaveConverter(QObject *parent = 0);

    void convert(QString source, QString destination, quint32 samplesPerRange, quint32 bitsPerSample);

private:



signals:

public slots:

};

#endif // FRACTALTOWAVECONVERTER_H
