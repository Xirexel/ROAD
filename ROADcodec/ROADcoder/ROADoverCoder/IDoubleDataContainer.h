#ifndef __ROADcoder__ROADoverCoder__IDoubleDataContainer_h__
#define __ROADcoder__ROADoverCoder__IDoubleDataContainer_h__


namespace ROADcoder
{
	namespace ROADoverCoder
	{
		class IDoubleDataContainer
		{

			public: virtual double* getData() = 0;

            public: virtual unsigned int getLength() = 0;

            public: virtual ~IDoubleDataContainer(){}

		};
	}
}

#endif
