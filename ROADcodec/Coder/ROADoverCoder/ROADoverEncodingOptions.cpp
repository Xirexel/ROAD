#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "ROADoverEncodingOptions.h"
#include "MixingChannelsMode.h"

void ROADoverEncoding::ROADoverEncodingOptions::setMixingChannelsMode(ROADoverEncoding::MixingChannelsMode aMixingChannelsMode) {
	this->_mixingChannelsMode = aMixingChannelsMode;
}

ROADoverEncoding::MixingChannelsMode ROADoverEncoding::ROADoverEncodingOptions::getMixingChannelsMode() {
	return this->_mixingChannelsMode;
}

