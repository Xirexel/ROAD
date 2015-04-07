#ifndef __Endian__EndianConvertorFactory_h__
#define __Endian__EndianConvertorFactory_h__

#include <memory>

#include "IEndianConvertor.h"
#include "EndianType.h"

namespace Endian
{
    class IEndianConvertor;
}

namespace Endian
{
	class EndianConvertorFactory
	{
        private: Endian::EndianType _localEndianType;


        private: EndianConvertorFactory();

        public: static Endian::EndianConvertorFactory& getInstance();

        public: ~EndianConvertorFactory();

        public: Endian::EndianType getLocalEndianType();

        public: std::unique_ptr<Endian::IEndianConvertor> getIEndianConvertor(Endian::EndianType aType);
	};

}

#endif
