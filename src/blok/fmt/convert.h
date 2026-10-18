#ifndef BLOK_CONVERT_H
#define BLOK_CONVERT_H

#include "../model/vector.h"
#include <windows.h>

TVector2 BlokConvertVector2FromPoint(const POINT pt);

POINT BlokConvertPointFromVector2(const TVector2 vec);

SIZE BlokConvertSizeFromVector2(const TVector2 vec);

RECT BlokConvertRectFromVector2s(const TVector2 pos, const TVector2 size);

TVector2 BlokConvertVector2PositionFromRect(const RECT rect);

TVector2 BlokConvertSizeVector2FromRect(const RECT rect);

#endif /* BLOK_CONVERT_H */