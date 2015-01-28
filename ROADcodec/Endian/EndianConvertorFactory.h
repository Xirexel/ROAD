#ifndef __Endian__EndianConvertorFactory_h__
#define __Endian__EndianConvertorFactory_h__

#include <memory>

#include "IEndianConvertor.h"
#include "EndianType.h"

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
        private: static Endian::EndianType _localEndianType;


        private: EndianConvertorFactory();

        public: static Endian::EndianConvertorFactory& getInstance();

        public: ~EndianConvertorFactory();

        public: std::unique_ptr<Endian::IEndianConvertor> getIEndianConvertor(Endian::EndianType aType);
	};
}

#endif
