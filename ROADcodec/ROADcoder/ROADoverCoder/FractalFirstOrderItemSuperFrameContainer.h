#ifndef __ROADcoder__ROADoverCoder__FractalFirstOrderItemSuperFrameContainer_h__
#define __ROADcoder__ROADoverCoder__FractalFirstOrderItemSuperFrameContainer_h__


#include <vector>


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
		class FractalFirstOrderItemSuperFrameContainer
		{
			private: unsigned int _count;
            public: std::vector<ROADcoder::ROADoverCoder::FractalFirstOrderItemContainer*> _fractalItemContainerCollection;

            public: FractalFirstOrderItemContainer *getFractalItemContainer(unsigned int aIndex);

			public: FractalFirstOrderItemSuperFrameContainer(unsigned int aSuperFrameLength, unsigned int aMaxFrameRangLength);

			public: unsigned int getCount();

            public: virtual ~FractalFirstOrderItemSuperFrameContainer();
		};
	}
}

#endif
