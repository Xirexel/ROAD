#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __DoubleDataContainer_h__
#define __DoubleDataContainer_h__

 #include "IDoubleDataContainer.h"

namespace FractalEncoding
{
	class IDoubleDataContainer;
	class DoubleDataContainer;
}

namespace FractalEncoding
{
	class DoubleDataContainer: public FractalEncoding::IDoubleDataContainer
	{
		private: unsigned int _count;
		private: double* _data;

		public: double* getData();

		public: unsigned int getCount();

		public: DoubleDataContainer(unsigned int aLength);

        public: virtual ~DoubleDataContainer();

		public: void setCount(unsigned int aCount);
	};
}

#endif
