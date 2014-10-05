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

namespace ROADEncoding
{
	class DoubleDataContainer;
	class UCharDataContainer;
	class IDoubleDataContainer;
	class IUCharDataContainer;
	class IFractalDataContainer;
	class FractalDataContainer;
    class FrameFractalItemCollection;
}

namespace ROADEncoding
{
    class FractalDataContainer: public ROADEncoding::IFractalDataContainer
	{
        public: ROADEncoding::DoubleDataContainer* _averContainer;
        public: ROADEncoding::DoubleDataContainer* _extenAverContainer;
        public: ROADEncoding::UCharDataContainer* _indexContainer;
        public: ROADEncoding::UCharDataContainer* _domainContainer;
        public: ROADEncoding::UCharDataContainer* _scaleContainer;

        public: ROADEncoding::IDoubleDataContainer* getAver();

        public: ROADEncoding::IDoubleDataContainer* getExtendAver();

        public: ROADEncoding::IUCharDataContainer* getIndex();

        public: ROADEncoding::IUCharDataContainer* getDomain();

        public: ROADEncoding::IUCharDataContainer* getScale();

		public: FractalDataContainer(unsigned int aSize);

        public: void populate(ROADEncoding::FrameFractalItemCollection* aCollection);

        public: void reset();

        public: virtual ~FractalDataContainer();

	};
}

#endif
