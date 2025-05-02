#include "convert.h"

VectorII blokConvertCoordV(const COORD coord)
{
    return (VectorII) {coord.X, coord.Y};
}

COORD blokConvertVectorCoord(const VectorII vec)
{
    return (COORD) {vec.x, vec.y};
}

RECT blokConvertVectorRect(const VectorII position, const VectorII size)
{
    return (RECT) {position.x, position.y, position.x+size.x, position.y+size.y};
}

VectorII blokConvertRectPositionV(const RECT rc)
{
    return (VectorII) {rc.top, rc.left};
}

VectorII blokConvertRectSizeV(const RECT rc)
{
    return (VectorII) {rc.right-rc.left, rc.bottom-rc.top};
}
