#include "vector.h"

void BlokVectorIICopy(VectorII *dest, const VectorII src)
{
    if (!dest) { return; }

    dest->x = src.x;
    dest->y = src.y;
}

void BlokVectorIVCopy(VectorIV *dest, const VectorIV src)
{
    if (!dest) { return; }

    dest->x = src.x;
    dest->y = src.y;
    dest->z = src.z;
    dest->w = src.w;
}

int BlokVectorIIEquals(const VectorII veca, const VectorII vecb)
{
    return (veca.x == vecb.x && veca.y == vecb.y);
}

VectorII BlokVectorIIAdd(const VectorII veca, const VectorII vecb)
{
    return (VectorII) {veca.x+vecb.x, veca.y+vecb.y};
}

VectorII BlokVectorIISubtract(const VectorII veca, const VectorII vecb)
{
    return (VectorII) {veca.x-vecb.x, veca.y-vecb.y};
}

VectorII BlokVectorIIMultiply(const VectorII veca, const VectorII vecb)
{
    return (VectorII) {veca.x*vecb.x, veca.y*vecb.y};
}