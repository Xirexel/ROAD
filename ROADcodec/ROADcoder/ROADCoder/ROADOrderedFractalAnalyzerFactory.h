#include <string>
#include <vector>
#include <exception>
#include <memory>

#ifndef __ROADcoder__ROADCoder__ROADOrderedFractalAnalyzerFactory_h__
#define __ROADcoder__ROADCoder__ROADOrderedFractalAnalyzerFactory_h__

 #include "IROADFractalAnalyzerFactory.h"

namespace ROADcoder
{
	namespace ROADCoder
	{
		class IROADFractalAnalyzerFactory;
		class ROADOrderedFractalAnalyzerFactory;
	}
}

namespace ROADcoder
{
	namespace ROADCoder
	{
		class ROADOrderedFractalAnalyzerFactory
		{

        public: static std::unique_ptr<ROADcoder::ROADCoder::IROADFractalAnalyzerFactory> getIROADFractalAnalyzerFactory(unsigned int aOrder);
		};
	}
}

#endif
