#include "convert.h"

TVector2 blokConvertPointV(
    const POINT point)
{
    return (TVector2){ point.x, point.y };
}

POINT blokConvertVectorPoint(
    const TVector2 vec)
{
    return (POINT){ vec.x, vec.y };
}

SIZE blokConvertVectorSize(
    const TVector2 vec)
{
    return (SIZE){ vec.x, vec.y };
}

RECT blokConvertVectorRect(
    const TVector2 pos,
    const TVector2 size)
{
    return (RECT){ pos.x, pos.y, pos.x + size.x, pos.y + size.y };
}

TVector2 blokConvertRectPositionV(
    const RECT rect)
{
    return (TVector2){ rect.top, rect.left };
}

TVector2 blokConvertRectSizeV(
    const RECT rect)
{
    return (TVector2){ rect.right - rect.left, rect.bottom - rect.top };
}
