#include "FractalFirstOrderItemContainer.h"
#include "FractalFirstOrderItem.h"
#include "FractalAverItem.h"

ROADcoder::ROADCoder::IFractalFirstOrderItem* ROADcoder::ROADoverCoder::FractalFirstOrderItemContainer::getIFractalFirstOrderItem() {
    return this->_fractalFirstOrderItem + this->_fractalFirstOrderItemCount++;
}

ROADcoder::ROADCoder::IFractalAverItem* ROADcoder::ROADoverCoder::FractalFirstOrderItemContainer::getIFractalAverItem() {
    return this->_fractalAverItem + this->_fractalAverItemCount++;
}

ROADcoder::ROADoverCoder::FractalFirstOrderItemContainer::FractalFirstOrderItemContainer(unsigned int aInitLength)
    : _fractalFirstOrderItem(new FractalFirstOrderItem[aInitLength]),
      _fractalAverItem(new FractalAverItem[aInitLength])
{
}

ROADcoder::ROADoverCoder::FractalFirstOrderItemContainer::~FractalFirstOrderItemContainer()
{
    delete[] this->_fractalFirstOrderItem;
    delete[] this->_fractalAverItem;
}

void ROADcoder::ROADoverCoder::FractalFirstOrderItemContainer::resetCounts() {
    this->_fractalAverItemCount = 0;
    this->_fractalFirstOrderItemCount = 0;
}

ROADcoder::ROADoverCoder::FractalAverItem* ROADcoder::ROADoverCoder::FractalFirstOrderItemContainer::getFractalAverItem(unsigned int aIndex) {
    return this->_fractalAverItem + aIndex;
}

ROADcoder::ROADoverCoder::FractalFirstOrderItem* ROADcoder::ROADoverCoder::FractalFirstOrderItemContainer::getFractalFirstOrderItem(unsigned int aIndex) {
    return this->_fractalFirstOrderItem + aIndex;
}

unsigned int ROADcoder::ROADoverCoder::FractalFirstOrderItemContainer::getFractalAverItemCount() {
	return this->_fractalAverItemCount;
}

unsigned int ROADcoder::ROADoverCoder::FractalFirstOrderItemContainer::getFractalFirstOrderItemCount() {
	return this->_fractalFirstOrderItemCount;
}

