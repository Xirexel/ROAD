#ifndef ENCODINGOPTIONSWIDGETFACTORY_H
#define ENCODINGOPTIONSWIDGETFACTORY_H


#include <memory>
#include <map>


#include "encodingoptionswidgetfactory_global.h"
#include "encodingoptionswidget.h"
//#include "IROADoverEncodingOptions.h"

namespace EncodingOptions {

class ENCODINGOPTIONSWIDGETFACTORYSHARED_EXPORT EncodingOptionsWidgetFactory
{

public:
    EncodingOptionsWidgetFactory() = delete;
    EncodingOptionsWidgetFactory(const EncodingOptionsWidgetFactory&) = delete;
    EncodingOptionsWidgetFactory& operator=(const EncodingOptionsWidgetFactory&) = delete;

    static std::unique_ptr<EncodingOptions::EncodingOptionsWidget> getEncodingOptionsWidget(unsigned int aType);

    static std::unique_ptr<EncodingOptions::EncodingOptionsWidget> getEncodingOptionsWidget(std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> &aOptions);

    static std::map<QString, unsigned int> getEncodingOptions();



};

}


#endif // ENCODINGOPTIONSWIDGETFACTORY_H
