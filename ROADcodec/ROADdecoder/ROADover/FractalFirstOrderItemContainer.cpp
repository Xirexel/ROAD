#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "FractalFirstOrderItemContainer.h"
#include "FractalFirstOrderItem.h"
#include "FractalAverItem.h"
#include "../ROAD/IFractalFirstOrderItem.h"
#include "../ROAD/IFractalAverItem.h"

ROADdecoder::ROAD::IFractalFirstOrderItem* ROADdecoder::ROADover::FractalFirstOrderItemContainer::getIFractalFirstOrderItem(unsigned int aIndex) {
    return this->_fractalItems + aIndex;
}

ROADdecoder::ROAD::IFractalAverItem* ROADdecoder::ROADover::FractalFirstOrderItemContainer::getIFractalAverItem(unsigned int aIndex) {
    return this->_fractalAverItems + aIndex;
}

unsigned int ROADdecoder::ROADover::FractalFirstOrderItemContainer::getIFractalFirstOrderItemCount() {
    return this->_fractalItemCount;
}

unsigned int ROADdecoder::ROADover::FractalFirstOrderItemContainer::getIFractalAverItemCount() {
    return this->_fractalAverItemCount;
}

ROADdecoder::ROADover::FractalFirstOrderItemContainer::~FractalFirstOrderItemContainer() {
    delete []this->_fractalItems;
    delete []this->_fractalAverItems;
}

ROADdecoder::ROADover::FractalFirstOrderItemContainer::FractalFirstOrderItemContainer(unsigned int aMaxCount)
    : _fractalItems(new FractalFirstOrderItem[aMaxCount]),
      _fractalAverItems(new FractalAverItem[aMaxCount]),
      _fractalAverItemCount(0),
      _fractalItemCount(0)
{
}

void ROADdecoder::ROADover::FractalFirstOrderItemContainer::setFractalAverItemCount(unsigned int aFractalAverItemCount) {
	this->_fractalAverItemCount = aFractalAverItemCount;
}

void ROADdecoder::ROADover::FractalFirstOrderItemContainer::setFractalFirstOrderItemCount(unsigned int aFractalItemCount) {
	this->_fractalItemCount = aFractalItemCount;
}

ROADdecoder::ROADover::FractalFirstOrderItem* ROADdecoder::ROADover::FractalFirstOrderItemContainer::getFractalFirstOrderItem(unsigned int aIndex)
{
    return this->_fractalItems + aIndex;
}

ROADdecoder::ROADover::FractalAverItem* ROADdecoder::ROADover::FractalFirstOrderItemContainer::getFractalAverItem(unsigned int aIndex)
{
    return this->_fractalAverItems + aIndex;
}
