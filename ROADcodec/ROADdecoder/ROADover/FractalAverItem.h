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
			private: unsigned char _fractalItemIndex;
			private: unsigned int _position;

			public: double getAver();

			public: unsigned int getLength();

			public: unsigned int getPosition();

			public: void setAver(double aAver);

			public: void setLength(unsigned int aLength);

			public: void setFractalItemIndex(unsigned char aFractalItemIndex);

			public: unsigned char getFractalItemIndex();

			public: void setPosition(unsigned int aPosition);
		};
	}
}

#endif
