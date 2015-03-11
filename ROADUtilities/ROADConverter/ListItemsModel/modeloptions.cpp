#include "modeloptions.h"
#include "QApplication"


#include "encodingoptionsfactory.h"


 ModelOptions::ModelOptions()
     : _localROADoverCoderOptions(EncodingOptionsFactory::getAsDefaultIROADoverEncodingOptions()),
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

    EncodingOptionsFactory::setAsDefaultIROADoverEncodingOptions(aROADoverCoderOptions);
}

QString ModelOptions::getPluginROADoverCodersDirPath()
{
    return this->_pluginROADoverCodersDirPath;
}

void ModelOptions::setPluginROADoverCodersDirPath(QString aPluginROADoverCodersDirPath)
{
    this->_pluginROADoverCodersDirPath = aPluginROADoverCodersDirPath;
}
