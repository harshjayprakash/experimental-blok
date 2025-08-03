/**
 * @file   convert.c
 * @brief  Conversion Helpers Implementation.
 * @author harshjayprakash
 * @date   2025-07-20
 ****************************************************************************************/

#include "convert.h"

TVector2 stConvertVector2FromPoint(
    const POINT pt)
{
    return (TVector2){ pt.x, pt.y };
}

POINT stConvertPointFromVector2(
    const TVector2 vec)
{
    return (POINT){ vec.x, vec.y };
}

SIZE stConvertSizeFromVector2(
    const TVector2 vec)
{
    return (SIZE){ vec.x, vec.y };
}

RECT stConvertRectFromVector2s(
    const TVector2 pos,
    const TVector2 size)
{
    return (RECT){ pos.x, pos.y, pos.x + size.x, pos.y + size.y };
}

TVector2 stConvertVector2PositionFromRect(
    const RECT rect)
{
    return (TVector2){ rect.top, rect.left };
}

TVector2 stConvertSizeVector2FromRect(
    const RECT rect)
{
    return (TVector2){ rect.right - rect.left, rect.bottom - rect.top };
}
