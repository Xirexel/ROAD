#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __UCharDataContainer_h__
#define __UCharDataContainer_h__

 #include "IUCharDataContainer.h"

namespace ROADEncoding
{
	class IUCharDataContainer;
	class UCharDataContainer;
}

namespace ROADEncoding
{
    class UCharDataContainer: public ROADEncoding::IUCharDataContainer
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
