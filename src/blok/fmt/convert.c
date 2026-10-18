#include "convert.h"

TVector2 BlokConvertVector2FromPoint(const POINT pt)
{
    return (TVector2){pt.x, pt.y};
}

POINT BlokConvertPointFromVector2(const TVector2 vec)
{
    return (POINT){vec.x, vec.y};
}

SIZE BlokConvertSizeFromVector2(const TVector2 vec)
{
    return (SIZE){vec.x, vec.y};
}

RECT BlokConvertRectFromVector2s(const TVector2 pos, const TVector2 size)
{
    return (RECT){pos.x, pos.y, pos.x + size.x, pos.y + size.y};
}

TVector2 BlokConvertVector2PositionFromRect(const RECT rect)
{
    return (TVector2){rect.top, rect.left};
}

TVector2 BlokConvertSizeVector2FromRect(const RECT rect)
{
    return (TVector2){rect.right - rect.left, rect.bottom - rect.top};
}
