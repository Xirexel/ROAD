#ifndef __ROADcoder__ROADoverCoder__FractalFirstOrderItemSuperFrameContainer_h__
#define __ROADcoder__ROADoverCoder__FractalFirstOrderItemSuperFrameContainer_h__


#include <vector>


#include "platformdependencies.h"


namespace ROADcoder
{
	namespace ROADoverCoder
	{
        class FractalFirstOrderItemContainer;
		class FractalFirstOrderItemSuperFrameContainer;
	}
}

namespace ROADcoder
{
	namespace ROADoverCoder
	{
    using namespace PlatformDependencies;

		class FractalFirstOrderItemSuperFrameContainer
		{
            private: ROADUInt32 _count;
            public: std::vector<ROADcoder::ROADoverCoder::FractalFirstOrderItemContainer*> _fractalItemContainerCollection;

            public: FractalFirstOrderItemContainer *getFractalItemContainer(ROADUInt32 aIndex);

            public: FractalFirstOrderItemSuperFrameContainer(ROADUInt32 aSuperFrameLength, ROADUInt32 aMaxFrameRangLength);

            public: ROADUInt32 getCount();

            public: virtual ~FractalFirstOrderItemSuperFrameContainer();
		};
	}
}

#endif
