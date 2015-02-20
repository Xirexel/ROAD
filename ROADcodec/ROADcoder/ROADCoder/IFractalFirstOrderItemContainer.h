#ifndef __ROADcoder__ROADCoder__IFractalFirstOrderItemContainer_h__
#define __ROADcoder__ROADCoder__IFractalFirstOrderItemContainer_h__


namespace ROADcoder
{
	namespace ROADCoder
	{
        class IFractalFirstOrderItem;
        class IFractalAverItem;
	}
}

namespace ROADcoder
{
    namespace ROADCoder
    {
        class IFractalFirstOrderItemContainer
		{

            public: virtual ROADcoder::ROADCoder::IFractalFirstOrderItem* getIFractalFirstOrderItem() = 0;

			public: virtual ROADcoder::ROADCoder::IFractalAverItem* getIFractalAverItem() = 0;

            public: virtual ~IFractalFirstOrderItemContainer(){}
		};
	}
}

#endif
