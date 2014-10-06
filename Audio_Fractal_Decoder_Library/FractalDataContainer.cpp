#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "FractalDataContainer.h"
#include "DoubleDataContainer.h"
#include "UCharDataContainer.h"
#include "UIntDataContainer.h"
#include "IDoubleDataContainer.h"
#include "IUCharDataContainer.h"
#include "IUIntDataContainer.h"
#include "IFractalDataContainer.h"

FractalDecoding::IDoubleDataContainer* FractalDecoding::FractalDataContainer::getAver() {
    return &this->_averDataConatainer;
}

FractalDecoding::IUCharDataContainer* FractalDecoding::FractalDataContainer::getIndeces() {
    return &this->_inecesContainer;
}

FractalDecoding::IUCharDataContainer* FractalDecoding::FractalDataContainer::getDomain() {
    return &this->_domainsConatiner;
}

FractalDecoding::IUCharDataContainer* FractalDecoding::FractalDataContainer::getScales() {
    return &this->_scalesContainer;
}

FractalDecoding::IUIntDataContainer* FractalDecoding::FractalDataContainer::getLengths() {
    return &this->_lengthDataContainer;
}

FractalDecoding::FractalDataContainer::FractalDataContainer(unsigned int aLength)
    : _averDataConatainer(FractalDecoding::DoubleDataContainer(aLength)),
      _inecesContainer(FractalDecoding::UCharDataContainer(aLength)),
      _domainsConatiner(FractalDecoding::UCharDataContainer(aLength)),
      _scalesContainer(FractalDecoding::UCharDataContainer(aLength)),
      _lengthDataContainer(FractalDecoding::UIntDataContainer(aLength))
{
}

