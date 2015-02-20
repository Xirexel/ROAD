#include "ROADover.h"
#include "ROADoverEncodingOptionsExperemental.h"
#include "ROADoverEncodingOptionsFirstVersion.h"
#include "ROADoverManagerExperemental.h"
#include "ROADoverManagerFirstVersion.h"



ROADcoder::ROADoverCoder::ROADover::ROADover(std::unique_ptr<IROADoverEncodingOptions> &aOptions)
{
    auto lOptions = aOptions->clone();

    switch (lOptions->getROADFormatMode()) {
    case ROADcoder::ROADoverCoder::EXPEREMENTAL:
    {
        auto loptions = dynamic_cast<ROADoverEncodingOptionsExperemental*>(lOptions.release());

        _manager.reset(new ROADoverManagerExperemental(this, loptions));
    }
        break;
    case ROADcoder::ROADoverCoder::FIRSTVERSION:
    {
        auto loptions = dynamic_cast<ROADoverEncodingOptionsFirstVersion*>(lOptions.release());

        _manager.reset(new ROADoverManagerFirstVersion(this, loptions));
    }
        break;
    default:
    {
        class CreateROADoverException: public std::exception
        {
        public:

            CreateROADoverException() _GLIBCXX_USE_NOEXCEPT
            {

            }

            virtual const char* what() const _GLIBCXX_USE_NOEXCEPT
            {
                return "Error of creating of ROADover!!!";
            }

            ~CreateROADoverException() _GLIBCXX_USE_NOEXCEPT
            {

            }
        };

        throw new CreateROADoverException;

    }
        break;
    } ;

}



PlatformDependencies::ROADUInt32 ROADcoder::ROADoverCoder::ROADover::getRangSampleLength()
{
    ROADUInt32 result = 0;

    result = _manager->getRangSampleLength();

    return result;
}

PlatformDependencies::ROADUInt32 ROADcoder::ROADoverCoder::ROADover::getBitsPerSample()
{
    ROADUInt32 result = 0;

    result = _manager->getBitsPerSample();

    return result;

}

std::tuple<PlatformDependencies::PtrROADByte, PlatformDependencies::ROADUInt32> ROADcoder::ROADoverCoder::ROADover::getFractalFormatRawData()
{
    std::tuple<PtrROADByte, ROADUInt32> result;

    result = _manager->getFractalFormatRawData();

    return result;
}

ROADcoder::ROADoverCoder::Result ROADcoder::ROADoverCoder::ROADover::doOneStepEncoding()
{
    return _manager->encode();
}

ROADcoder::ROADoverCoder::ROADover::~ROADover()
{
}
