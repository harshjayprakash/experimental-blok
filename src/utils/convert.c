#include "convert.h"

VectorII blokConvertCoordV(const COORD coord)
{
    return (VectorII) {coord.X, coord.Y};
}

COORD blokConvertVectorCoord(const VectorII vec)
{
    return (COORD) {vec.x, vec.y};
}

RECT blokConvertVectorRect(const VectorII pos, const VectorII size)
{
    return (RECT) {pos.x, pos.y, pos.x+size.x, pos.y+size.y};
}

VectorII blokConvertRectPositionV(const RECT rect)
{
    return (VectorII) {rect.top, rect.left};
}

VectorII blokConvertRectSizeV(const RECT rect)
{
    return (VectorII) {rect.right-rect.left, rect.bottom-rect.top};
}
