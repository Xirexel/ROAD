#include "encodingoptionswidgetfactory.h"
#include "encodingoptionsexperementalwidget.h"
#include "ROADoverEncodingOptionsFactory.h"
#include "encodingoptionsfactory.h"

using namespace EncodingOptions;

std::unique_ptr<EncodingOptions::EncodingOptionsWidget> EncodingOptionsWidgetFactory::getEncodingOptionsWidget(unsigned int aType)
{
    using namespace ROADcoder::ROADoverCoder;

    std::unique_ptr<EncodingOptionsWidget> result;

    auto lencodingOptions = EncodingOptionsFactory::getIROADoverEncodingOptions(aType);

    do
    {

        std::unique_ptr<ROADoverEncodingOptionsExperemental> loptions(dynamic_cast<ROADoverEncodingOptionsExperemental*>(lencodingOptions.release()));

        if(!loptions)
            break;

        switch (aType) {
        case 0:

            result.reset(new EncodingOptionsExperementalWidget(loptions));


            break;
        default:
            break;
        }

    }while(false);

    return result;
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
        case 0:

        {

            std::unique_ptr<ROADoverEncodingOptionsExperemental> loptions(dynamic_cast<ROADoverEncodingOptionsExperemental*>(aOptions.release()));

            result.reset(new EncodingOptionsExperementalWidget(loptions));

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
        if(item == 0)
            lresult["ROAD Experemental"] = 0;
    }

    return lresult;
}
