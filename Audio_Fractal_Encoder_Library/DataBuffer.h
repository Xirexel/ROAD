#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __DataBuffer_h__
#define __DataBuffer_h__

namespace FractalEncoding
{
	class DataBuffer;
}

namespace FractalEncoding
{
	class DataBuffer
	{
		private: double* _firstChannel;
		private: double* _secondChannel;
		private: unsigned int _length;

		public: DataBuffer(unsigned int aLength);

        public: ~DataBuffer();

		public: double* getFirstChannel();

		public: double* getSecondChannel();

		public: unsigned int getLength();
	};
}

#endif
