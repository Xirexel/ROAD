#include "roadoverwavecoderplugin.h"
#include "roadoverwavecoder.h"
#include "ROADRawDataFormat.h"
#include "roadovercoderfactory.h"


#define UNUSED(expr) do { (void)(expr); } while (0)

ROADoverWAVECoderPlugin::ROADoverWAVECoderPlugin(QObject *parent) :
    QObject(parent)
{
}


IROADoverCoderFactory* ROADoverWAVECoderPlugin::createIROADoverCoderFactory()
{
    return new ROADoverCoderFactory();
}

bool ROADoverWAVECoderPlugin::ROADoverWAVECoderPlugin::checkPlugin() const
{
    return true;
}

QString ROADoverWAVECoderPlugin::name() const
{
    return QString("ROADoverWAVE");
}
