#ifndef _BLOK_CONVERT_H_
#define _BLOK_CONVERT_H_

#include "../model/vector.h"
#include <Windows.h>

VectorII blokConvertCoordV(const COORD coord);

POINT blokConvertVectorPoint(const VectorII vec);

SIZE blokConvertVectorSize(const VectorII vec);

RECT blokConvertVectorRect(const VectorII pos, const VectorII size);

VectorII blokConvertRectPositionV(const RECT rect);

VectorII blokConvertRectSizeV(const RECT rect);

#endif // _BLOK_CONVERT_H_