#include "modeloptions.h"
#include "QApplication"



 ModelOptions::ModelOptions()
     : _localROADoverCoderOptions(0),
       _pluginROADoverCodersDirPath(QString(QApplication::applicationDirPath() + "/Plugins/ROADoverCoderPlugins"))

 {

 }

unsigned int ModelOptions::getROADoverCoderOptions()
{
    return this->_localROADoverCoderOptions;
}

void ModelOptions::setROADoverCoderOptions(unsigned int aROADoverCoderOptions)
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
