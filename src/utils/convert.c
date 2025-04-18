#include "convert.h"

VectorII BlokConvertCoordV(const COORD coord)
{
    return (VectorII) {coord.X, coord.Y};
}

COORD BlokConvertVectorCoord(const VectorII vec)
{
    return (COORD) {vec.x, vec.y};
}

RECT BlokConvertVectorRect(const VectorII position, const VectorII size)
{
    return (RECT) {position.x, position.y, position.x+size.x, position.y+size.y};
}

VectorII BlokConvertRectPositionV(const RECT rc)
{
    return (VectorII) {rc.top, rc.left};
}

VectorII BlokConvertRectSizeV(const RECT rc)
{
    return (VectorII) {rc.right-rc.left, rc.bottom-rc.top};
}

VectorIV BlokConvertRectV(const RECT rc)
{
    return (VectorIV) {rc.left, rc.top, rc.right, rc.bottom};
}