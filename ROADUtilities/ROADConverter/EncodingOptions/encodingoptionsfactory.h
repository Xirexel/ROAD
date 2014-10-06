#ifndef ENCODINGOPTIONS_H
#define ENCODINGOPTIONS_H

#include <memory>


#include "encodingoptions_global.h"
//#include "IROADoverEncodingOptions.h"


namespace ROADcoder
{
    namespace ROADoverCoder
    {
        class IROADoverEncodingOptions;
    }
}


class ENCODINGOPTIONSSHARED_EXPORT EncodingOptionsFactory
{
public:

    static std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> getIROADoverEncodingOptions(unsigned int aROADFormat);

    static void persistIROADoverEncodingOptions(std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> &aOptions);

    EncodingOptionsFactory() = delete;
};

#endif // ENCODINGOPTIONS_H
