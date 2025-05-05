#include "vector.h"

void blokVectorIICopy(VectorII *pDest, const VectorII src)
{
    if (!pDest) { return; }

    pDest->x = src.x;
    pDest->y = src.y;
}

int blokVectorIIEquals(const VectorII veca, const VectorII vecb)
{
    return (veca.x == vecb.x && veca.y == vecb.y);
}

VectorII blokVectorIIAdd(const VectorII veca, const VectorII vecb)
{
    return (VectorII) {veca.x+vecb.x, veca.y+vecb.y};
}

VectorII blokVectorIISubtract(const VectorII veca, const VectorII vecb)
{
    return (VectorII) {veca.x-vecb.x, veca.y-vecb.y};
}

VectorII blokVectorIIMultiply(const VectorII veca, const VectorII vecb)
{
    return (VectorII) {veca.x*vecb.x, veca.y*vecb.y};
}