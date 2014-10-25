#ifndef ROADOVERWAVECODERPLUGIN_H
#define ROADOVERWAVECODERPLUGIN_H

#include <QObject>
#include "../../ListItem/interfaces.h"

class ROADoverWAVECoderPlugin : public QObject,
                                public IROADoverCoderPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "ROADConvertor.IROADoverCoderPlugin")
    Q_INTERFACES(IROADoverCoderPlugin)

public:
    explicit ROADoverWAVECoderPlugin(QObject *parent = 0);

    virtual IROADoverCoder* createIROADoverCoder(IROADoverRawReader* ptrReader,
                                                 IROADoverCoderOptions *aIROADoverCoderOptions,
                                                 IOriginalAudioStreamOptions *
                                                 aOriginalAudioStreamOptions,
                                                 QString outputFile);

    virtual bool checkPlugin() const;

    virtual QString name() const;

signals:

public slots:

};

#endif // ROADOVERWAVECODERPLUGIN_H
