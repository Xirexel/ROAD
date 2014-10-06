#ifndef WAVE_CHUNK_H
#define WAVE_CHUNK_H

#include "qglobal.h"


struct __WAVECHUNKHEAD
{
        char id[4];   // идентификатор типа файла
        quint32 size;   // размер оставшейся части файла

};

struct __WAVEDESCR
{
        __WAVECHUNKHEAD chunkHead;   // размер оставшейся части файла
        char wave[4];  // формат файла

        __WAVEDESCR()
        {
            chunkHead.id[0] = 'R';
            chunkHead.id[1] = 'I';
            chunkHead.id[2] = 'F';
            chunkHead.id[3] = 'F';


            wave[0] = 'W';
            wave[1] = 'A';
            wave[2] = 'V';
            wave[3] = 'E';
        }

};

struct __WAVEFORMAT
{
        __WAVECHUNKHEAD chunkHead;
        quint16 format;     // аудио формат
        quint16 channels;    // число каналов
        quint32 sampleRate;    // частота дискретизации
        quint32 byteRate;     // скорость потока
        quint16 blockAlign;  // смещение блока выборки
        quint16 bitsPerSample;   // разрядность выборки

        __WAVEFORMAT()
        {
            chunkHead.id[0] = 'f';
            chunkHead.id[1] = 'm';
            chunkHead.id[2] = 't';
            chunkHead.id[3] = ' ';
        }

};

struct __WAVEDESCRDATA
{
        __WAVECHUNKHEAD chunkHead;

        __WAVEDESCRDATA()
        {
            chunkHead.id[0] = 'd';
            chunkHead.id[1] = 'a';
            chunkHead.id[2] = 't';
            chunkHead.id[3] = 'a';
        }
};


#endif // WAVE_CHUNK_H
