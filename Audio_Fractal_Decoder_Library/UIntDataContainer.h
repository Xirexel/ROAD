#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __UIntDataContainer_h__
#define __UIntDataContainer_h__

 #include "IUIntDataContainer.h"

namespace FractalDecoding
{
	class IUIntDataContainer;
	class UIntDataContainer;
}

namespace FractalDecoding
{
	class UIntDataContainer: public FractalDecoding::IUIntDataContainer
	{
		private: unsigned int _count;
		private: unsigned int* _data;

		public: unsigned int* getData();

		public: unsigned int getCount();

		public: void setCount(unsigned int aValue);

		public: UIntDataContainer(unsigned int aLength);

        public: virtual ~UIntDataContainer();
	};
}

#endif
