#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __FractalDataContainer_h__
#define __FractalDataContainer_h__

#include "DoubleDataContainer.h"
#include "UCharDataContainer.h"
#include "UIntDataContainer.h"
// #include "IDoubleDataContainer.h"
// #include "IUCharDataContainer.h"
// #include "IUIntDataContainer.h"
 #include "IFractalDataContainer.h"

namespace FractalDecoding
{
	class DoubleDataContainer;
	class UCharDataContainer;
	class UIntDataContainer;
	class IDoubleDataContainer;
	class IUCharDataContainer;
	class IUIntDataContainer;
	class IFractalDataContainer;
	class FractalDataContainer;
}

namespace FractalDecoding
{
	class FractalDataContainer: public FractalDecoding::IFractalDataContainer
	{
		private: FractalDecoding::DoubleDataContainer _averDataConatainer;
		private: FractalDecoding::UCharDataContainer _inecesContainer;
		private: FractalDecoding::UCharDataContainer _domainsConatiner;
		private: FractalDecoding::UCharDataContainer _scalesContainer;
		private: FractalDecoding::UIntDataContainer _lengthDataContainer;

		public: FractalDecoding::IDoubleDataContainer* getAver();

		public: FractalDecoding::IUCharDataContainer* getIndeces();

		public: FractalDecoding::IUCharDataContainer* getDomain();

		public: FractalDecoding::IUCharDataContainer* getScales();

		public: FractalDecoding::IUIntDataContainer* getLengths();

		public: FractalDataContainer(unsigned int aLength);
	};
}

#endif
