#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __UCharDataContainer_h__
#define __UCharDataContainer_h__

 #include "IUCharDataContainer.h"

namespace FractalEncoding
{
	class IUCharDataContainer;
	class UCharDataContainer;
}

namespace FractalEncoding
{
	class UCharDataContainer: public FractalEncoding::IUCharDataContainer
	{
		private: unsigned int _count;
		private: unsigned char* _data;

		public: unsigned char* getData();

		public: unsigned int getCount();

		public: UCharDataContainer(unsigned int aLength);

        public: virtual ~UCharDataContainer();

		public: void setCount(unsigned int aCount);
	};
}

#endif
