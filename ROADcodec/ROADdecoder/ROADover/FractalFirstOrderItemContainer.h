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

    using namespace PlatformDependencies;
        class FractalFirstOrderItemContainer: public ROADdecoder::ROAD::IFractalFirstOrderItemContainer
		{
            private: ROADdecoder::ROADover::FractalFirstOrderItem* _fractalItems;
			private: ROADdecoder::ROADover::FractalAverItem* _fractalAverItems;
            private: ROADUInt32 _fractalAverItemCount;
            private: ROADUInt32 _fractalItemCount;

            public: ROADdecoder::ROAD::IFractalFirstOrderItem* getIFractalFirstOrderItem(ROADUInt32 aIndex);

            public: ROADdecoder::ROAD::IFractalAverItem* getIFractalAverItem(ROADUInt32 aIndex);

            public: ROADUInt32 getIFractalFirstOrderItemCount();

            public: ROADUInt32 getIFractalAverItemCount();

            public: virtual ~FractalFirstOrderItemContainer();

            public: FractalFirstOrderItemContainer(ROADUInt32 aMaxCount);

            public: void setFractalAverItemCount(ROADUInt32 aFractalAverItemCount);

            public: void setFractalFirstOrderItemCount(ROADUInt32 aFractalItemCount);

            public: ROADdecoder::ROADover::FractalFirstOrderItem* getFractalFirstOrderItem(ROADUInt32 aIndex);

            public: ROADdecoder::ROADover::FractalAverItem* getFractalAverItem(ROADUInt32 aIndex);
		};
	}
}

#endif
