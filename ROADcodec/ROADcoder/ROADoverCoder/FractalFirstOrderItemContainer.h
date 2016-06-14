#ifndef __ROADcoder__ROADoverCoder__FractalFirstOrderItemContainer_h__
#define __ROADcoder__ROADoverCoder__FractalFirstOrderItemContainer_h__

#include "../ROADCoder/IFractalFirstOrderItemContainer.h"
#include "memorydefine.h"

namespace ROADcoder
{
	namespace ROADCoder
	{
		class IFractalFirstOrderItem;
		class IFractalAverItem;
		class IFractalFirstOrderItemContainer;
	}
	namespace ROADoverCoder
	{
		class FractalFirstOrderItem;
		class FractalAverItem;
		class FractalFirstOrderItemContainer;
	}
}

namespace ROADcoder
{
	namespace ROADoverCoder
	{
    using namespace PlatformDependencies;

        // fractal data container
		class FractalFirstOrderItemContainer: public ROADcoder::ROADCoder::IFractalFirstOrderItemContainer
		{
            private: UniqueMassive_ptr<ROADcoder::ROADoverCoder::FractalFirstOrderItem> _fractalFirstOrderItem;
            private: UniqueMassive_ptr<ROADcoder::ROADoverCoder::FractalAverItem> _fractalAverItem;
            private: ROADUInt32 _fractalAverItemCount;
            private: ROADUInt32 _fractalFirstOrderItemCount;

			public: ROADcoder::ROADCoder::IFractalFirstOrderItem* getIFractalFirstOrderItem();

			public: ROADcoder::ROADCoder::IFractalAverItem* getIFractalAverItem();

            public: virtual ~FractalFirstOrderItemContainer();

            public: FractalFirstOrderItemContainer(ROADUInt32 aInitLength);

			public: void resetCounts();

            public: ROADcoder::ROADoverCoder::FractalAverItem* getFractalAverItem(ROADUInt32 aIndex);

            public: ROADcoder::ROADoverCoder::FractalFirstOrderItem* getFractalFirstOrderItem(ROADUInt32 aIndex);

            public: ROADUInt32 getFractalAverItemCount();

            public: ROADUInt32 getFractalFirstOrderItemCount();
		};
	}
}

#endif
