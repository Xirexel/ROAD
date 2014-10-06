#ifndef PERSISTROADENCODINGOPTIONS_H
#define PERSISTROADENCODINGOPTIONS_H


#include <memory>


#include "IROADoverEncodingOptions.h"

namespace EncodingOptions {

class PersistROADEncodingOptions
{

public:

    static PersistROADEncodingOptions& getInstance();

    std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> loadIROADoverEncodingOptions(unsigned int aROADFormat);

    void persistIROADoverEncodingOptions(std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> &aPtrOptions);

private:
    PersistROADEncodingOptions();

    PersistROADEncodingOptions(const PersistROADEncodingOptions&) = delete;

    PersistROADEncodingOptions& operator= (const PersistROADEncodingOptions&) = delete;

    std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> loadROADoverEncodingOptionsExperemental();

    void persistROADoverEncodingOptionsExperemental(ROADcoder::ROADoverCoder::IROADoverEncodingOptions * aPtrOptions);


};

}


#endif // PERSISTROADENCODINGOPTIONS_H
