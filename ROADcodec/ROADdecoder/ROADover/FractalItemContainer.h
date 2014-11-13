#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADdecoder__ROADover__FractalItemContainer_h__
#define __ROADdecoder__ROADover__FractalItemContainer_h__

 #include "../ROAD/IFractalItem.h"
 #include "../ROAD/IFractalAverItem.h"
 #include "../ROAD/IFractalItemContainer.h"
// #include "ROADdecoder/ROADover/FractalItem.h"
// #include "ROADdecoder/ROADover/FractalAverItem.h"

namespace ROADdecoder
{
	namespace ROAD
	{
		class IFractalItem;
		class IFractalAverItem;
		class IFractalItemContainer;
	}
	namespace ROADover
	{
		class FractalItem;
		class FractalAverItem;
		class FractalItemContainer;
	}
}

namespace ROADdecoder
{
	namespace ROADover
	{
		class FractalItemContainer: public ROADdecoder::ROAD::IFractalItemContainer
		{
			private: ROADdecoder::ROADover::FractalItem* _fractalItems;
			private: ROADdecoder::ROADover::FractalAverItem* _fractalAverItems;
			private: unsigned int _fractalAverItemCount;
			private: unsigned int _fractalItemCount;

			public: ROADdecoder::ROAD::IFractalItem* getIFractalItem(unsigned int aIndex);

			public: ROADdecoder::ROAD::IFractalAverItem* getIFractalAverItem(unsigned int aIndex);

			public: unsigned int getIFractalItemCount();

			public: unsigned int getIFractalAverItemCount();

            public: ~FractalItemContainer();

			public: FractalItemContainer(unsigned int aMaxCount);

			public: void setFractalAverItemCount(unsigned int aFractalAverItemCount);

			public: void setFractalItemCount(unsigned int aFractalItemCount);
		};
	}
}

#endif
