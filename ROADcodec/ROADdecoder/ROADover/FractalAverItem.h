#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADdecoder__ROADover__FractalAverItem_h__
#define __ROADdecoder__ROADover__FractalAverItem_h__

#include "../ROAD/IFractalAverItem.h"

namespace ROADdecoder
{
	namespace ROAD
	{
		class IFractalAverItem;
	}
	namespace ROADover
	{
		class FractalAverItem;
	}
}

namespace ROADdecoder
{
	namespace ROADover
	{
		class FractalAverItem: public ROADdecoder::ROAD::IFractalAverItem
		{
			private: double _aver;
			private: unsigned int _length;

			public: double getAver();

			public: unsigned int getLength();

			public: void setAver(double aAver);

			public: void setLength(unsigned int aLength);
		};
	}
}

#endif
