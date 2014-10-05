#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __IFractalDataContainer_h__
#define __IFractalDataContainer_h__

// #include "IDoubleDataContainer.h"
// #include "IUCharDataContainer.h"

namespace ROADEncoding
{
	class IDoubleDataContainer;
	class IUCharDataContainer;
    class IROADDataContainer;
}

namespace ROADEncoding
{
    class IROADDataContainer
	{

        public: virtual ROADEncoding::IDoubleDataContainer* getAver() = 0;

        public: virtual ROADEncoding::IDoubleDataContainer* getExtendAver() = 0;

        public: virtual ROADEncoding::IUCharDataContainer* getIndex() = 0;

        public: virtual ROADEncoding::IUCharDataContainer* getDomain() = 0;

        public: virtual ROADEncoding::IUCharDataContainer* getScale() = 0;

        public: virtual ~IROADDataContainer(){}
	};
}

#endif
