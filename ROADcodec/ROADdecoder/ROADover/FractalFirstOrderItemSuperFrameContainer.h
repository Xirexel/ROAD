#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADdecoder__ROADover__FractalItemSuperFrameContainer_h__
#define __ROADdecoder__ROADover__FractalItemSuperFrameContainer_h__



namespace ROADdecoder
{
	namespace ROADover
	{
        class FractalFirstOrderItemContainer;
        class FractalFirstOrderItemSuperFrameContainer;
	}
}

namespace ROADdecoder
{
	namespace ROADover
	{
        class FractalFirstOrderItemSuperFrameContainer
		{
            private: const unsigned int _count;

            public: std::vector<ROADdecoder::ROADover::FractalFirstOrderItemContainer*> _fractalItemContainerCollection;

            public: ROADdecoder::ROADover::FractalFirstOrderItemContainer* getFractalFirstOrderItemContainer(unsigned int aIndex);

            public: FractalFirstOrderItemSuperFrameContainer(unsigned int aSuperFrameLength, unsigned int aMaxFrameRangLength);

			public: unsigned int getCount();

            public: virtual ~FractalFirstOrderItemSuperFrameContainer();
		};
	}
}

#endif
