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
		class FractalItemContainer;
		class FractalItemSuperFrameContainer;
	}
}

namespace ROADdecoder
{
	namespace ROADover
	{
		class FractalItemSuperFrameContainer
		{
            private: const unsigned int _count;

			public: std::vector<ROADdecoder::ROADover::FractalItemContainer*> _fractalItemContainerCollection;

			public: ROADdecoder::ROADover::FractalItemContainer* getFractalItemContainer(unsigned int aIndex);

			public: FractalItemSuperFrameContainer(unsigned int aSuperFrameLength, unsigned int aMaxFrameRangLength);

			public: unsigned int getCount();

            public: virtual ~FractalItemSuperFrameContainer();
		};
	}
}

#endif
