#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __CharDataContainer_h__
#define __CharDataContainer_h__

 #include "ICharDataContainer.h"

namespace ROADoverEncoding
{
	class ICharDataContainer;
	class CharDataContainer;
}

namespace ROADoverEncoding
{
	class CharDataContainer: public ROADoverEncoding::ICharDataContainer
	{
		private: char* _data;
		private: unsigned int _length;

		public: CharDataContainer(unsigned int aLength);

        public: virtual ~CharDataContainer();

		public: char* getData();

		public: unsigned int getLength();
	};
}

#endif
