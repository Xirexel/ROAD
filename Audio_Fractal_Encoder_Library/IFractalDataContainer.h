#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __IFractalDataContainer_h__
#define __IFractalDataContainer_h__

// #include "IDoubleDataContainer.h"
// #include "IUCharDataContainer.h"

namespace FractalEncoding
{
	class IDoubleDataContainer;
	class IUCharDataContainer;
	class IFractalDataContainer;
}

namespace FractalEncoding
{
	class IFractalDataContainer
	{

		public: virtual FractalEncoding::IDoubleDataContainer* getAver() = 0;

		public: virtual FractalEncoding::IDoubleDataContainer* getExtendAver() = 0;

		public: virtual FractalEncoding::IUCharDataContainer* getIndex() = 0;

		public: virtual FractalEncoding::IUCharDataContainer* getDomain() = 0;

		public: virtual FractalEncoding::IUCharDataContainer* getScale() = 0;

        public: virtual ~IFractalDataContainer(){}
	};
}

#endif
