#ifndef _STREAM_H_
#define _STREAM_H_

#include <Stdafx.h>
#include "type.h"
#include "utilsCommon.h"
using namespace std;

namespace utils
{
    DLL_EXPORT_UTILS bool zlibCompress(const ByteArray& srcData, ByteArray& dstData);
    DLL_EXPORT_UTILS bool zlibDecompress(const ByteArray& srcData, ByteArray& dstData);
}

#endif //_STREAM_H_