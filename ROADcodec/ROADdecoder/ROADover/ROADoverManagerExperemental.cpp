#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "ROADoverManagerExperemental.h"
#include "ROADover.h"
#include "ROADoverDecodingOptionsExperemental.h"

ROADdecoder::ROADover::ROADoverManagerExperemental::ROADoverManagerExperemental(ROADdecoder::ROADover::ROADover* aRoadOver,
                                                                                ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental* aOptions)
    :ROADoverManager(aRoadOver, aOptions)
{
}

ROADdecoder::ROADover::Result ROADdecoder::ROADover::ROADoverManagerExperemental::decode() {
    Result result = Result::ERROR;


    return result;
}

