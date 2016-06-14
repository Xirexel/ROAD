#ifndef __ROADcoder__ROADCoder__ROADOrderedFractalAnalyzerFactory_h__
#define __ROADcoder__ROADCoder__ROADOrderedFractalAnalyzerFactory_h__

#include <memory>

#include "memorydefine.h"
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

        public: static Unique_ptr<ROADcoder::ROADCoder::IROADFractalAnalyzerFactory> getIROADFractalAnalyzerFactory(ROADUInt32 aOrder);
		};
	}
}

#endif
