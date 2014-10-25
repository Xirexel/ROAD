#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "FractalDataContainer.h"
#include "IDoubleDataContainer.h"
#include "IUCharDataContainer.h"
#include "IUIntDataContainer.h"
#include "IFractalDataContainer.h"
#include "DoubleDataContainer.h"
#include "UCharDataContainer.h"
#include "UIntDataContainer.h"

ROADdecoding::IDoubleDataContainer* ROADover::FractalDataContainer::getAver() {
    return &_averDataConatainer;
}

ROADdecoding::IUCharDataContainer* ROADover::FractalDataContainer::getIndeces() {
    return &_inecesContainer;
}

ROADdecoding::IUCharDataContainer* ROADover::FractalDataContainer::getDomain() {
    return &_domainsConatiner;
}

ROADdecoding::IUCharDataContainer* ROADover::FractalDataContainer::getScales() {
    return &_scalesContainer;
}

ROADdecoding::IUIntDataContainer* ROADover::FractalDataContainer::getLengths() {
    return &_lengthDataContainer;
}

ROADover::FractalDataContainer::FractalDataContainer(unsigned int aLength)
    : _averDataConatainer(ROADover::DoubleDataContainer(aLength)),
      _inecesContainer(ROADover::UCharDataContainer(aLength)),
      _domainsConatiner(ROADover::UCharDataContainer(aLength)),
      _scalesContainer(ROADover::UCharDataContainer(aLength)),
      _lengthDataContainer(ROADover::UIntDataContainer(aLength))
{
}

