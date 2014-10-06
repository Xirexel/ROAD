#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __CharDataContainer_h__
#define __CharDataContainer_h__

namespace ROADoverEncoding
{
	class CharDataContainer;
}

namespace ROADoverEncoding
{
	class CharDataContainer
	{
		private: double* _data;

		public: CharDataContainer(unsigned int aLength);

		public: void setData(double* aData);

		public: double* getData();
	};
}

#endif
