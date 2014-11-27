#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "ROADoverManagerExperemental.h"
#include "ROADover.h"
#include "ROADoverDecodingOptionsExperemental.h"

ROADdecoder::ROADover::ROADoverManagerExperemental::ROADoverManagerExperemental(ROADdecoder::ROADover::ROADover* aRoadOver,
                                                                                ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental* aOptions)
    :ROADoverManager(aRoadOver,
                     aOptions->getAmountOfChannels(),
                     4,
                     aOptions->getSamplesPerRang() *
                     aOptions->getFrameRangLength() *
                     aOptions->getSuperframeLength()),
      _options(aOptions)
{
}

ROADdecoder::ROADover::Result ROADdecoder::ROADover::ROADoverManagerExperemental::decode() {
    Result result = Result::ERROR;

    this->_roadOver->lockResource();

    unsigned int lreadLength = this->_roadOver->readROADdata(this->_bufferROADdata);



    this->_roadOver->unlockResource();

    return result;
}

ROADdecoder::ROADover::ROADoverManagerExperemental::~ROADoverManagerExperemental()
{
    delete _options;
}
