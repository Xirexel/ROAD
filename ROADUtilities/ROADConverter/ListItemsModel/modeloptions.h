#ifndef MODELOPTIONS_H
#define MODELOPTIONS_H
#include "listitemsmodel_global.h"

#include <QString>


class LISTITEMSMODELSHARED_EXPORT ModelOptions
{
public:

public:    

    explicit ModelOptions();

    unsigned int getROADoverCoderOptions();

    void setROADoverCoderOptions(unsigned int aROADoverCoderOptions);

    QString getPluginROADoverCodersDirPath();

    void setPluginROADoverCodersDirPath(QString aPluginROADoverCodersDirPath);

private:

    unsigned int _localROADoverCoderOptions;

    QString _pluginROADoverCodersDirPath;
};

#endif // MODELOPTIONS_H
