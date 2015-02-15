#include "FractalAverItem.h"

PlatformDependencies::ROADReal ROADdecoder::ROADover::FractalAverItem::getAver() {
    return this->_aver;
}

PlatformDependencies::ROADUInt32 ROADdecoder::ROADover::FractalAverItem::getLength() {
    return this->_length;
}

void ROADdecoder::ROADover::FractalAverItem::setAver(ROADReal aAver) {
	this->_aver = aAver;
}

void ROADdecoder::ROADover::FractalAverItem::setLength(ROADUInt32 aLength) {
	this->_length = aLength;
}

void ROADdecoder::ROADover::FractalAverItem::setFractalItemIndex(ROADUInt8 aFractalItemIndex)
{
    this->_fractalItemIndex = aFractalItemIndex;
}

PlatformDependencies::ROADUInt8 ROADdecoder::ROADover::FractalAverItem::getFractalItemIndex()
{
    return this->_fractalItemIndex;
}

PlatformDependencies::ROADUInt32 ROADdecoder::ROADover::FractalAverItem::getPosition()
{
    return this->_position;
}

void ROADdecoder::ROADover::FractalAverItem::setPosition(ROADUInt32 aPosition)
{
    this->_position = aPosition;
}
