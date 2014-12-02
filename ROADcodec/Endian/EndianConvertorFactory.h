#include <string>
#include <vector>
#include <exception>
#include <memory>
using namespace std;

#ifndef __Endian__EndianConvertorFactory_h__
#define __Endian__EndianConvertorFactory_h__

#include "IEndianConvertor.h"
#include "EndianType.h"


//#include "endian_global.h"

namespace Endian
{
	class IEndianConvertor;
	// enum EndianType;
	class EndianConvertorFactory;
}

namespace Endian
{
    class EndianConvertorFactory
    {
        public: static std::unique_ptr<Endian::IEndianConvertor> getIEndianConvertor(Endian::EndianType aType);

        private: EndianConvertorFactory() = delete;

        private: virtual ~EndianConvertorFactory() = delete;
	};
}

#endif
