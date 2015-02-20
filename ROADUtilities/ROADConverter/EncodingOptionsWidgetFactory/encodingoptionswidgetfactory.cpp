#include "encodingoptionswidgetfactory.h"
#include "encodingoptionsexperementalwidget.h"
#include "EncodingOptionsFirstVersionWidget.h"
#include "ROADoverEncodingOptionsFactory.h"
#include "ROADoverEncodingOptionsFirstVersion.h"
#include "encodingoptionsfactory.h"

using namespace EncodingOptions;

std::unique_ptr<EncodingOptions::EncodingOptionsWidget> EncodingOptionsWidgetFactory::getEncodingOptionsWidget(unsigned int aType)
{
    using namespace ROADcoder::ROADoverCoder;

//    std::unique_ptr<EncodingOptionsWidget> result;

    auto lencodingOptions = EncodingOptionsFactory::getIROADoverEncodingOptions(aType);

    return getEncodingOptionsWidget(lencodingOptions);

//    do
//    {

//        switch (aType) {
//        case EXPEREMENTAL:
//        {
//            std::unique_ptr<ROADoverEncodingOptionsExperemental> loptions(dynamic_cast<ROADoverEncodingOptionsExperemental*>(lencodingOptions.release()));

//            if(!loptions)
//                break;

//            result.reset(new EncodingOptionsExperementalWidget(loptions));
//        }

//            break;
//        case FIRSTVERSION:

//        {

//            std::unique_ptr<ROADoverEncodingOptionsFirstVersion> loptions(dynamic_cast<ROADoverEncodingOptionsFirstVersion*>(lencodingOptions.release()));

//            result.reset(new EncodingOptionsFirstVersionWidget(loptions));

//        }
//        default:
//            break;
//        }

//    }while(false);

//    return result;
}

std::unique_ptr<EncodingOptions::EncodingOptionsWidget> EncodingOptionsWidgetFactory::getEncodingOptionsWidget(std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> &aOptions)
{
    using namespace ROADcoder::ROADoverCoder;

    std::unique_ptr<EncodingOptionsWidget> result;

    do
    {

        if(!aOptions)
            break;

        switch (aOptions->getROADFormatMode()) {
        case EXPEREMENTAL:

        {

            std::unique_ptr<ROADoverEncodingOptionsExperemental> loptions(dynamic_cast<ROADoverEncodingOptionsExperemental*>(aOptions.release()));

            result.reset(new EncodingOptionsExperementalWidget(loptions));

        }

            break;
        case FIRSTVERSION:

        {

            std::unique_ptr<ROADoverEncodingOptionsFirstVersion> loptions(dynamic_cast<ROADoverEncodingOptionsFirstVersion*>(aOptions.release()));

            result.reset(new EncodingOptionsFirstVersionWidget(loptions));

        }

            break;


        default:
            break;
        }

    }while(false);

    return result;
}

std::map<QString, unsigned int> EncodingOptionsWidgetFactory::getEncodingOptions()
{
    using namespace ROADcoder::ROADoverCoder;

    std::map<QString, unsigned int> lresult;

    std::vector<unsigned int> llistFormats = ROADoverEncodingOptionsFactory::getSupportedFormats();

    for(auto item: llistFormats)
    {
        if(item == EXPEREMENTAL)
            lresult["ROAD Experemental"] = EXPEREMENTAL;

        if(item == FIRSTVERSION)
            lresult["ROAD First Version"] = FIRSTVERSION;
    }

    return lresult;
}
