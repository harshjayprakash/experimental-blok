#ifndef _BLOK_CONVERT_H_
#define _BLOK_CONVERT_H_

#include "../model/vector.h"
#include <windows.h>

TVector2 blokConvertPointV(const POINT pt);

POINT blokConvertVectorPoint(const TVector2 vec);

SIZE blokConvertVectorSize(const TVector2 vec);

RECT blokConvertVectorRect(const TVector2 pos, const TVector2 size);

TVector2 blokConvertRectPositionV(const RECT rect);

TVector2 blokConvertRectSizeV(const RECT rect);

#endif /* _BLOK_CONVERT_H_ */