#include "vector.h"

void blokVectorIICopy(VectorII *dest, const VectorII src)
{
    if (!dest) { return; }

    dest->x = src.x;
    dest->y = src.y;
}

void blokVectorIVCopy(VectorIV *dest, const VectorIV src)
{
    if (!dest) { return; }

    dest->x = src.x;
    dest->y = src.y;
    dest->z = src.z;
    dest->w = src.w;
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