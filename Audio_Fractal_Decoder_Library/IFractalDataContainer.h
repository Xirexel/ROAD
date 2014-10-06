#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __IFractalDataContainer_h__
#define __IFractalDataContainer_h__

// #include "IDoubleDataContainer.h"
// #include "IUCharDataContainer.h"
// #include "IUIntDataContainer.h"

namespace FractalDecoding
{
	class IDoubleDataContainer;
	class IUCharDataContainer;
	class IUIntDataContainer;
	class IFractalDataContainer;
}

namespace FractalDecoding
{
	class IFractalDataContainer
	{

		public: virtual FractalDecoding::IDoubleDataContainer* getAver() = 0;

		public: virtual FractalDecoding::IUCharDataContainer* getIndeces() = 0;

		public: virtual FractalDecoding::IUCharDataContainer* getDomain() = 0;

		public: virtual FractalDecoding::IUCharDataContainer* getScales() = 0;

		public: virtual FractalDecoding::IUIntDataContainer* getLengths() = 0;

        public: virtual ~IFractalDataContainer(){}
	};
}

#endif
