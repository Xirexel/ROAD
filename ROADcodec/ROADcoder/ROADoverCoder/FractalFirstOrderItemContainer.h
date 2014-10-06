#ifndef __ROADcoder__ROADoverCoder__FractalFirstOrderItemContainer_h__
#define __ROADcoder__ROADoverCoder__FractalFirstOrderItemContainer_h__

#include "../ROADCoder/IFractalFirstOrderItemContainer.h"

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
		class FractalFirstOrderItemContainer: public ROADcoder::ROADCoder::IFractalFirstOrderItemContainer
		{
			private: ROADcoder::ROADoverCoder::FractalFirstOrderItem* _fractalFirstOrderItem;
			private: ROADcoder::ROADoverCoder::FractalAverItem* _fractalAverItem;
			private: unsigned int _fractalAverItemCount;
			private: unsigned int _fractalFirstOrderItemCount;

			public: ROADcoder::ROADCoder::IFractalFirstOrderItem* getIFractalFirstOrderItem();

			public: ROADcoder::ROADCoder::IFractalAverItem* getIFractalAverItem();

            public: virtual ~FractalFirstOrderItemContainer();

            public: FractalFirstOrderItemContainer(unsigned int aInitLength);

			public: void resetCounts();

			public: ROADcoder::ROADoverCoder::FractalAverItem* getFractalAverItem(unsigned int aIndex);

			public: ROADcoder::ROADoverCoder::FractalFirstOrderItem* getFractalFirstOrderItem(unsigned int aIndex);

			public: unsigned int getFractalAverItemCount();

			public: unsigned int getFractalFirstOrderItemCount();
		};
	}
}

#endif
