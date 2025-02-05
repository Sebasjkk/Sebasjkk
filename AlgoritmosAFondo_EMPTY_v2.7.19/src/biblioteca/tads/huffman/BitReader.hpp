#ifndef _TARR_BITREADER_
#define _TARR_BITREADER_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "../../funciones/strings.hpp"
#include "../../funciones/files.hpp"

using namespace std;

struct BitReader
{
   FILE* f;
   char buf;
   int idx;
};

BitReader bitReader(FILE* f)
{
   BitReader b;
   b.f = f;
   b.buf = 0;
   b.idx = 8;
   return b;
}

int bitReaderRead(BitReader& br)
{
   unsigned int ret;
   if(br.idx==8)
   {
      br.buf= read<char>(br.f);
      br.idx=0;
   }
   unsigned int mask= 10000000;
   ret = br.buf&mask;
   br.buf = br.buf<<1;
   br.idx++;
   return ret/10000000;
}

#endif
