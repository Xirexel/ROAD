#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __CRCProcessor_h__
#define __CRCProcessor_h__

namespace ROADoverEncoding
{
	class CRCProcessor;
}

namespace ROADoverEncoding
{
	class CRCProcessor
	{

		public: unsigned int computeCRC32(char* aData, unsigned int aLength);
	};
}

#endif
