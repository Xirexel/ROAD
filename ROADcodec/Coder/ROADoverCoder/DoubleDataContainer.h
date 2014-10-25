#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __DoubleDataContainer_h__
#define __DoubleDataContainer_h__

namespace ROADoverEncoding
{
	class DoubleDataContainer;
}

namespace ROADoverEncoding
{
	class DoubleDataContainer
	{
		private: double* _data;

		public: DoubleDataContainer(unsigned int aLength);

        public: virtual ~DoubleDataContainer();

		public: void setData(double* aData);

		public: double* getData();
	};
}

#endif
