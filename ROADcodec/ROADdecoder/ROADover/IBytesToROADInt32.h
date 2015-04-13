#ifndef IBYTESTOROADINT32_H
#define IBYTESTOROADINT32_H

#include "platformdependencies.h"

namespace ROADdecoder
{
    namespace ROADover
    {
    using namespace PlatformDependencies;

        class IBytesToROADInt32
        {
            public: virtual ~IBytesToROADInt32(){}

            public: virtual void setAtBeginning(PtrROADByte aData) = 0;

            public: virtual ROADInt32 getROADInt32() = 0;
        };
    }
}

#endif // IBYTESTOROADINT32_H
