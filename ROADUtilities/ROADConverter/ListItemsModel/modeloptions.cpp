#include "modeloptions.h"
#include "QApplication"



 ModelOptions::ModelOptions()
     : _pluginROADoverCodersDirPath(QString(QApplication::applicationDirPath() + "/Plugins/ROADoverCoderPlugins"))
 {

 }

ROADoverCoderOptions ModelOptions::getROADoverCoderOptions()
{
    return this->_localROADoverCoderOptions;
}

void ModelOptions::setROADoverCoderOptions(ROADoverCoderOptions aROADoverCoderOptions)
{
    this->_localROADoverCoderOptions = aROADoverCoderOptions;
}

QString ModelOptions::getPluginROADoverCodersDirPath()
{
    return this->_pluginROADoverCodersDirPath;
}

void ModelOptions::setPluginROADoverCodersDirPath(QString aPluginROADoverCodersDirPath)
{
    this->_pluginROADoverCodersDirPath = aPluginROADoverCodersDirPath;
}
