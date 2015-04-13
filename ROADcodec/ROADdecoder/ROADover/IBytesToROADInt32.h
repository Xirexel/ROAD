#ifndef IBYTESTOROADINT32_H
#define IBYTESTOROADINT32_H


#include <memory>


#include "platformdependencies.h"

namespace ROADdecoder
{
    namespace ROADover
    {
    using namespace PlatformDependencies;

        class IBytesToROADInt32
        {
            public: virtual ~IBytesToROADInt32(){}

            public: virtual void convert(std::shared_ptr<ROADByte> aData,
                                                ROADUInt64 aLength,
                                                PtrROADInt32 aROADInt32Data,
                                                ROADUInt64 aFrameSampleLength) = 0;

        };
    }
}

#endif // IBYTESTOROADINT32_H
