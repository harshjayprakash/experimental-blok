/**
 * @file CONVERT.C
 * @date 26-05-2025
 * @brief Implementation of conversion routines.
 */

#include "convert.h"

VectorII blokConvertPointV(
    const POINT point)
{
    return (VectorII){ point.x, point.y };
}

POINT blokConvertVectorPoint(
    const VectorII vec)
{
    return (POINT){ vec.x, vec.y };
}

SIZE blokConvertVectorSize(
    const VectorII vec)
{
    return (SIZE){ vec.x, vec.y };
}

RECT blokConvertVectorRect(
    const VectorII pos,
    const VectorII size)
{
    return (RECT){ pos.x, pos.y, pos.x + size.x, pos.y + size.y };
}

VectorII blokConvertRectPositionV(
    const RECT rect)
{
    return (VectorII){ rect.top, rect.left };
}

VectorII blokConvertRectSizeV(
    const RECT rect)
{
    return (VectorII){ rect.right - rect.left, rect.bottom - rect.top };
}
