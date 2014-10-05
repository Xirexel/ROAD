#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __DataBuffer_h__
#define __DataBuffer_h__

namespace ROADEncoding
{
	class DataBuffer;
}

namespace ROADEncoding
{
	class DataBuffer
	{
        private: double* _data;
		private: unsigned int _length;

		public: DataBuffer(unsigned int aLength);

        public: ~DataBuffer();

        public: double* getData();

		public: unsigned int getLength();
	};
}

#endif
