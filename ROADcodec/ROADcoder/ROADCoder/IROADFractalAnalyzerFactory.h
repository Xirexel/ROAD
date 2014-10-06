#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADcoder__ROADCoder__IROADFractalAnalyzerFactory_h__
#define __ROADcoder__ROADCoder__IROADFractalAnalyzerFactory_h__

namespace ROADcoder
{
	namespace ROADCoder
	{
		class IROADFractalAnalyzerFactory;
	}
}

namespace ROADcoder
{
	namespace ROADCoder
	{
		class IROADFractalAnalyzerFactory
		{

            public: virtual ~IROADFractalAnalyzerFactory(){}

			public: virtual unsigned int getOrder() = 0;
		};
	}
}

#endif
