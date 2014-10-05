#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __FractalItem_h__
#define __FractalItem_h__

 #include "IFractalItem.h"

namespace ROADEncoding
{
	class IFractalItem;
	class FractalItem;
}

namespace ROADEncoding
{
    class FractalItem: public ROADEncoding::IFractalItem
	{
		private: double _aver;
		private: unsigned int _domain;
		private: float _scale;
		private: unsigned int _index;
		private: bool _direction;
		private: bool _silence;

		public: void setAver(double aValue);

		public: void setDomain(unsigned int aValue);

		public: void setScale(float aValue);

		public: void setIndex(unsigned int aValue);

		public: void setDirection(bool aValue);

		public: void setSilence(bool aValue);

		public: double getAver();

		public: unsigned int getDomain();

		public: float getScale();

		public: unsigned int getIndex();

		public: bool isDirection();

		public: bool isSilence();
	};
}

#endif
