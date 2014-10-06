#ifndef FRACTALCHANKS_H
#define FRACTALCHANKS_H


#include <QtCore/qglobal.h>


#include "wave_parser.h"

struct __FRACFORMAT
{
        quint32 _format;
        quint32 _superFrameLength;
        quint32 _frameRangeLength;
        quint32 _domainShift;
        quint32 _domainShiftScale;
        quint32 _originalAmountOfChannels;
        quint32 _averDiffMode;
        quint32 _encriptionCode;
};

struct __FRACDESCR
{

    __FRACDESCR()
    {
        _chunkHead.id[0] = 'R';

        _chunkHead.id[1] = 'O';

        _chunkHead.id[2] = 'A';

        _chunkHead.id[3] = 'D';
    }

    bool operator == (const __FRACDESCR &arg)
    {
        return this->_chunkHead.id[0] == arg._chunkHead.id[0]
                && this->_chunkHead.id[1] == arg._chunkHead.id[1]
                && this->_chunkHead.id[2] == arg._chunkHead.id[2]
                && this->_chunkHead.id[3] == arg._chunkHead.id[3];
    }

        __WAVECHUNKHEAD _chunkHead;

        __FRACFORMAT _format;
};

struct __FRACMAP
{

    __FRACMAP()
    {
        _chunkHead.id[0] = 'M';

        _chunkHead.id[1] = 'A';

        _chunkHead.id[2] = 'P';

        _chunkHead.id[3] = ' ';

    }

    bool operator == (const __FRACMAP &arg)
    {
        return this->_chunkHead.id[0] == arg._chunkHead.id[0]
                && this->_chunkHead.id[1] == arg._chunkHead.id[1]
                && this->_chunkHead.id[2] == arg._chunkHead.id[2]
                && this->_chunkHead.id[3] == arg._chunkHead.id[3];
    }
        __WAVECHUNKHEAD _chunkHead;
};

struct __FRACDESCRINDECES
{

    __FRACDESCRINDECES()
    {
        _chunkHead.id[0] = 'F';

        _chunkHead.id[1] = 'I';

        _chunkHead.id[2] = 'N';

        _chunkHead.id[3] = 'D';

    }

    bool operator == (const __FRACDESCRINDECES &arg)
    {
        return this->_chunkHead.id[0] == arg._chunkHead.id[0]
                && this->_chunkHead.id[1] == arg._chunkHead.id[1]
                && this->_chunkHead.id[2] == arg._chunkHead.id[2]
                && this->_chunkHead.id[3] == arg._chunkHead.id[3];
    }
        __WAVECHUNKHEAD _chunkHead;
};





#endif // FRACTALCHANKS_H
