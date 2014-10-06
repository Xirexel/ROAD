#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADdecoder__ROAD__IROADFractalBuilderFactory_h__
#define __ROADdecoder__ROAD__IROADFractalBuilderFactory_h__

namespace ROADdecoder
{
	namespace ROAD
	{
		class IROADFractalBuilderFactory;
	}
}

namespace ROADdecoder
{
	namespace ROAD
	{
		class IROADFractalBuilderFactory
		{

			public: virtual unsigned int getOrder() = 0;

            public: virtual ~IROADFractalBuilderFactory(){}
		};
	}
}

#endif
