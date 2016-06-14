#include "FractalFirstOrderItemContainer.h"
#include "FractalFirstOrderItem.h"
#include "FractalAverItem.h"

ROADcoder::ROADCoder::IFractalFirstOrderItem* ROADcoder::ROADoverCoder::FractalFirstOrderItemContainer::getIFractalFirstOrderItem() {
    return this->_fractalFirstOrderItem + this->_fractalFirstOrderItemCount++;
}

ROADcoder::ROADCoder::IFractalAverItem* ROADcoder::ROADoverCoder::FractalFirstOrderItemContainer::getIFractalAverItem() {
    return this->_fractalAverItem + this->_fractalAverItemCount++;
}

ROADcoder::ROADoverCoder::FractalFirstOrderItemContainer::FractalFirstOrderItemContainer(ROADUInt32 aInitLength)
    : _fractalFirstOrderItem(new FractalFirstOrderItem[aInitLength], aInitLength),
      _fractalAverItem(new FractalAverItem[aInitLength], aInitLength)
{
}

ROADcoder::ROADoverCoder::FractalFirstOrderItemContainer::~FractalFirstOrderItemContainer()
{
}

void ROADcoder::ROADoverCoder::FractalFirstOrderItemContainer::resetCounts() {
    this->_fractalAverItemCount = 0;
    this->_fractalFirstOrderItemCount = 0;
}

ROADcoder::ROADoverCoder::FractalAverItem* ROADcoder::ROADoverCoder::FractalFirstOrderItemContainer::getFractalAverItem(ROADUInt32 aIndex) {
    return this->_fractalAverItem + aIndex;
}

ROADcoder::ROADoverCoder::FractalFirstOrderItem* ROADcoder::ROADoverCoder::FractalFirstOrderItemContainer::getFractalFirstOrderItem(ROADUInt32 aIndex) {
    return this->_fractalFirstOrderItem + aIndex;
}

PlatformDependencies::ROADUInt32 ROADcoder::ROADoverCoder::FractalFirstOrderItemContainer::getFractalAverItemCount() {
	return this->_fractalAverItemCount;
}

PlatformDependencies::ROADUInt32 ROADcoder::ROADoverCoder::FractalFirstOrderItemContainer::getFractalFirstOrderItemCount() {
	return this->_fractalFirstOrderItemCount;
}

