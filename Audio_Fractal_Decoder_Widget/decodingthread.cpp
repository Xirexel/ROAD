#include "decodingthread.h"
#include "IReader.h"

DecodingThread::DecodingThread(IReader *parent) :
    QThread(parent),
    _reader(parent)
{
}

void DecodingThread::run()
{
    _reader->decode();
}
