#ifndef _BLOK_CONVERT_H_
#define _BLOK_CONVERT_H_

#include "../model/vector.h"
#include <Windows.h>

VectorII blokConvertCoordV(const COORD coord);

COORD blokConvertVectorCoord(const VectorII vec);

RECT blokConvertVectorRect(const VectorII position, const VectorII size);

VectorII blokConvertRectPositionV(const RECT rc);

VectorII blokConvertRectSizeV(const RECT rc);

VectorIV blokConvertRectV(const RECT rc);

#endif // _BLOK_CONVERT_H_