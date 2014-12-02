#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "FractalItemContainer.h"
#include "FractalItem.h"
#include "FractalAverItem.h"
#include "../ROAD/IFractalItem.h"
#include "../ROAD/IFractalAverItem.h"

ROADdecoder::ROAD::IFractalItem* ROADdecoder::ROADover::FractalItemContainer::getIFractalItem(unsigned int aIndex) {
    return this->_fractalItems + aIndex;
}

ROADdecoder::ROAD::IFractalAverItem* ROADdecoder::ROADover::FractalItemContainer::getIFractalAverItem(unsigned int aIndex) {
    return this->_fractalAverItems + aIndex;
}

unsigned int ROADdecoder::ROADover::FractalItemContainer::getIFractalItemCount() {
    return this->_fractalItemCount;
}

unsigned int ROADdecoder::ROADover::FractalItemContainer::getIFractalAverItemCount() {
    return this->_fractalAverItemCount;
}

ROADdecoder::ROADover::FractalItemContainer::~FractalItemContainer() {
    delete []this->_fractalItems;
    delete []this->_fractalAverItems;
}

ROADdecoder::ROADover::FractalItemContainer::FractalItemContainer(unsigned int aMaxCount)
    : _fractalItems(new FractalItem[aMaxCount]),
      _fractalAverItems(new FractalAverItem[aMaxCount]),
      _fractalAverItemCount(0),
      _fractalItemCount(0)
{
}

void ROADdecoder::ROADover::FractalItemContainer::setFractalAverItemCount(unsigned int aFractalAverItemCount) {
	this->_fractalAverItemCount = aFractalAverItemCount;
}

void ROADdecoder::ROADover::FractalItemContainer::setFractalItemCount(unsigned int aFractalItemCount) {
	this->_fractalItemCount = aFractalItemCount;
}

ROADdecoder::ROADover::FractalItem* ROADdecoder::ROADover::FractalItemContainer::getFractalItem(unsigned int aIndex)
{
    return this->_fractalItems + aIndex;
}

ROADdecoder::ROADover::FractalAverItem* ROADdecoder::ROADover::FractalItemContainer::getFractalAverItem(unsigned int aIndex)
{
    return this->_fractalAverItems + aIndex;
}
