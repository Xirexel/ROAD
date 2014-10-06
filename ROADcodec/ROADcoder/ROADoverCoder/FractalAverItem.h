#ifndef __ROADcoder__ROADoverCoder__FractalAverItem_h__
#define __ROADcoder__ROADoverCoder__FractalAverItem_h__

#include "../ROADCoder/IFractalAverItem.h"

namespace ROADcoder
{
	namespace ROADCoder
	{
		class IFractalAverItem;
	}
	namespace ROADoverCoder
	{
		class FractalAverItem;
	}
}

namespace ROADcoder
{
	namespace ROADoverCoder
	{
		class FractalAverItem: public ROADcoder::ROADCoder::IFractalAverItem
		{
			private: double _aver;
			private: unsigned int _length;
			private: unsigned int _index;

			public: void setAver(double aValue);

			public: void setLength(unsigned int aValue);

			public: void setIndex(unsigned int aValue);

			public: double getAver();

			public: unsigned int getLength();

			public: unsigned int getIndex();
		};
	}
}

#endif
