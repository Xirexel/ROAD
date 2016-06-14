#ifndef IDECODEDSAMPLETYPETOOUTPUTTYPESAMPLE_H
#define IDECODEDSAMPLETYPETOOUTPUTTYPESAMPLE_H

#include "platformdependencies.h"
#include "IDataWriteDriver.h"

namespace ROADcoder
{
    namespace ROADoverCoder
    {
    using namespace PlatformDependencies;

        class IDecodedSampleTypeToRawDataSampleType
        {
            public: virtual void writeRawData(ROADcoder::Driver::IDataWriteDriver& aIDataWriteDriver, ROADReal *aData, ROADUInt32 ldoubleBufferLength) = 0;
            public: virtual ~IDecodedSampleTypeToRawDataSampleType(){}
        };
    }
}

#endif // IDECODEDSAMPLETYPETOOUTPUTTYPESAMPLE_H
