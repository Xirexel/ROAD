#ifndef __ROADdecoder__ROADover__FractalItemSuperFrameContainer_h__
#define __ROADdecoder__ROADover__FractalItemSuperFrameContainer_h__

#include <vector>

#include "platformdependencies.h"

namespace ROADdecoder
{
	namespace ROADover
	{
        class FractalFirstOrderItemContainer;
	}
}

namespace ROADdecoder
{
	namespace ROADover
	{

    using namespace PlatformDependencies;
        class FractalFirstOrderItemSuperFrameContainer
		{
            private: const ROADUInt32 _count;

            public: std::vector<ROADdecoder::ROADover::FractalFirstOrderItemContainer*> _fractalItemContainerCollection;

            public: ROADdecoder::ROADover::FractalFirstOrderItemContainer* getFractalFirstOrderItemContainer(ROADUInt32 aIndex);

            public: FractalFirstOrderItemSuperFrameContainer(ROADUInt32 aSuperFrameLength, ROADUInt32 aMaxFrameRangLength);

            public: ROADUInt32 getCount();

            public: virtual ~FractalFirstOrderItemSuperFrameContainer();
		};
	}
}

#endif
