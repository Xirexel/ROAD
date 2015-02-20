#include "FractalFirstOrderItemContainer.h"
#include "FractalFirstOrderItem.h"
#include "FractalAverItem.h"
#include "../ROAD/IFractalFirstOrderItem.h"
#include "../ROAD/IFractalAverItem.h"

ROADdecoder::ROAD::IFractalFirstOrderItem* ROADdecoder::ROADover::FractalFirstOrderItemContainer::getIFractalFirstOrderItem(ROADUInt32 aIndex) {
    return this->_fractalItems + aIndex;
}

ROADdecoder::ROAD::IFractalAverItem* ROADdecoder::ROADover::FractalFirstOrderItemContainer::getIFractalAverItem(ROADUInt32 aIndex) {
    return this->_fractalAverItems + aIndex;
}

PlatformDependencies::ROADUInt32 ROADdecoder::ROADover::FractalFirstOrderItemContainer::getIFractalFirstOrderItemCount() {
    return this->_fractalItemCount;
}

PlatformDependencies::ROADUInt32 ROADdecoder::ROADover::FractalFirstOrderItemContainer::getIFractalAverItemCount() {
    return this->_fractalAverItemCount;
}

ROADdecoder::ROADover::FractalFirstOrderItemContainer::~FractalFirstOrderItemContainer() {
    delete []this->_fractalItems;
    delete []this->_fractalAverItems;
}

ROADdecoder::ROADover::FractalFirstOrderItemContainer::FractalFirstOrderItemContainer(ROADUInt32 aMaxCount)
    : _fractalItems(new FractalFirstOrderItem[aMaxCount]),
      _fractalAverItems(new FractalAverItem[aMaxCount]),
      _fractalAverItemCount(0),
      _fractalItemCount(0)
{
}

void ROADdecoder::ROADover::FractalFirstOrderItemContainer::setFractalAverItemCount(ROADUInt32 aFractalAverItemCount) {
	this->_fractalAverItemCount = aFractalAverItemCount;
}

void ROADdecoder::ROADover::FractalFirstOrderItemContainer::setFractalFirstOrderItemCount(ROADUInt32 aFractalItemCount) {
	this->_fractalItemCount = aFractalItemCount;
}

ROADdecoder::ROADover::FractalFirstOrderItem* ROADdecoder::ROADover::FractalFirstOrderItemContainer::getFractalFirstOrderItem(ROADUInt32 aIndex)
{
    return this->_fractalItems + aIndex;
}

ROADdecoder::ROADover::FractalAverItem* ROADdecoder::ROADover::FractalFirstOrderItemContainer::getFractalAverItem(ROADUInt32 aIndex)
{
    return this->_fractalAverItems + aIndex;
}
