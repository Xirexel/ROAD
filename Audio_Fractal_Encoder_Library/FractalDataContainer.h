#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __FractalDataContainer_h__
#define __FractalDataContainer_h__

// #include "DoubleDataContainer.h"
// #include "UCharDataContainer.h"
// #include "IDoubleDataContainer.h"
// #include "IUCharDataContainer.h"
 #include "IFractalDataContainer.h"

namespace FractalEncoding
{
	class DoubleDataContainer;
	class UCharDataContainer;
	class IDoubleDataContainer;
	class IUCharDataContainer;
	class IFractalDataContainer;
	class FractalDataContainer;
    class FrameFractalItemCollection;
}

namespace FractalEncoding
{
	class FractalDataContainer: public FractalEncoding::IFractalDataContainer
	{
		public: FractalEncoding::DoubleDataContainer* _averContainer;
		public: FractalEncoding::DoubleDataContainer* _extenAverContainer;
		public: FractalEncoding::UCharDataContainer* _indexContainer;
		public: FractalEncoding::UCharDataContainer* _domainContainer;
		public: FractalEncoding::UCharDataContainer* _scaleContainer;

		public: FractalEncoding::IDoubleDataContainer* getAver();

		public: FractalEncoding::IDoubleDataContainer* getExtendAver();

		public: FractalEncoding::IUCharDataContainer* getIndex();

		public: FractalEncoding::IUCharDataContainer* getDomain();

		public: FractalEncoding::IUCharDataContainer* getScale();

		public: FractalDataContainer(unsigned int aSize);

        public: void populate(FractalEncoding::FrameFractalItemCollection* aCollection);

        public: void reset();

        public: virtual ~FractalDataContainer();

	};
}

#endif
