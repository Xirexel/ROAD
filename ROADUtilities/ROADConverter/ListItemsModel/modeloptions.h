#ifndef MODELOPTIONS_H
#define MODELOPTIONS_H
#include "listitemsmodel_global.h"
#include "../ListItem/roadovercoderoptions.h"


class LISTITEMSMODELSHARED_EXPORT ModelOptions
{
public:

public:    

    explicit ModelOptions();

    ROADoverCoderOptions getROADoverCoderOptions();

    void setROADoverCoderOptions(ROADoverCoderOptions aROADoverCoderOptions);

    QString getPluginROADoverCodersDirPath();

    void setPluginROADoverCodersDirPath(QString aPluginROADoverCodersDirPath);

private:

    ROADoverCoderOptions _localROADoverCoderOptions;

    QString _pluginROADoverCodersDirPath;
};

#endif // MODELOPTIONS_H
