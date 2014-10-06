#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADdecoder__ROADover__FractalItemContainer_h__
#define __ROADdecoder__ROADover__FractalItemContainer_h__

 #include "../ROAD/IFractalFirstOrderItem.h"
 #include "../ROAD/IFractalAverItem.h"
 #include "../ROAD/IFractalFirstOrderItemContainer.h"
// #include "ROADdecoder/ROADover/FractalItem.h"
// #include "ROADdecoder/ROADover/FractalAverItem.h"

namespace ROADdecoder
{
	namespace ROAD
	{
        class IFractalFirstOrderItem;
		class IFractalAverItem;
        class IFractalFirstOrderItemContainer;
	}
	namespace ROADover
	{
        class FractalFirstOrderItem;
		class FractalAverItem;
        class FractalFirstOrderItemContainer;
	}
}

namespace ROADdecoder
{
	namespace ROADover
	{
        class FractalFirstOrderItemContainer: public ROADdecoder::ROAD::IFractalFirstOrderItemContainer
		{
            private: ROADdecoder::ROADover::FractalFirstOrderItem* _fractalItems;
			private: ROADdecoder::ROADover::FractalAverItem* _fractalAverItems;
			private: unsigned int _fractalAverItemCount;
			private: unsigned int _fractalItemCount;

            public: ROADdecoder::ROAD::IFractalFirstOrderItem* getIFractalFirstOrderItem(unsigned int aIndex);

			public: ROADdecoder::ROAD::IFractalAverItem* getIFractalAverItem(unsigned int aIndex);

            public: unsigned int getIFractalFirstOrderItemCount();

			public: unsigned int getIFractalAverItemCount();

            public: virtual ~FractalFirstOrderItemContainer();

            public: FractalFirstOrderItemContainer(unsigned int aMaxCount);

			public: void setFractalAverItemCount(unsigned int aFractalAverItemCount);

            public: void setFractalFirstOrderItemCount(unsigned int aFractalItemCount);

            public: ROADdecoder::ROADover::FractalFirstOrderItem* getFractalFirstOrderItem(unsigned int aIndex);

            public: ROADdecoder::ROADover::FractalAverItem* getFractalAverItem(unsigned int aIndex);
		};
	}
}

#endif
