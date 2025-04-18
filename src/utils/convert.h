#ifndef _BLOK_CONVERT_H_
#define _BLOK_CONVERT_H_

#include "../model/vector.h"
#include <Windows.h>

VectorII BlokConvertCoordV(const COORD coord);

COORD BlokConvertVectorCoord(const VectorII vec);

RECT BlokConvertVectorRect(const VectorII position, const VectorII size);

VectorII BlokConvertRectPositionV(const RECT rc);

VectorII BlokConvertRectSizeV(const RECT rc);

VectorIV BlokConvertRectV(const RECT rc);

#endif // _BLOK_CONVERT_H_