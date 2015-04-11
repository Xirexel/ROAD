#ifndef BYTECONVERTOR_H
#define BYTECONVERTOR_H

#include "IDataWriteDriver.h"

namespace ROADcoder
{
    namespace ROADoverCoder
    {
    using namespace PlatformDependencies;

        class ByteConvertor
        {


        public: template<typename Element>
            static void converts(ROADcoder::Driver::IDataWriteDriver *aPtrIDataWriteDriver,
                                 PtrROADReal aData,
                                 ROADUInt64 aLength)
            {
                for(decltype(aLength) lIndex = 0;
                    lIndex < aLength;
                    ++lIndex)
                {
                    aPtrIDataWriteDriver->operator <<((Element)*aData++);
                }
            }
        };
    }
}

#endif // BYTECONVERTOR_H
