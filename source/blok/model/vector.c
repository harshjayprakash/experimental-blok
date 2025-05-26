/**
 * \file VECTOR.C
 * \date 24-05-2025
 * \brief Implementation of the vector operation routines.
 */

#include "vector.h"
#include <stdlib.h>

int blokVectorIICopy(
    VectorII *pDest,
    const VectorII src)
{
    if (pDest == NULL) {
        return 0;
    }

    pDest->x = src.x;
    pDest->y = src.y;

    return 1;
}

int blokVectorIIEquals(
    const VectorII veca,
    const VectorII vecb)
{
    return (veca.x == vecb.x && veca.y == vecb.y);
}

VectorII blokVectorIIOffset(
    const VectorII vec,
    const VectorII offsetVec)
{
    return (VectorII){ vec.x + offsetVec.x, vec.y + offsetVec.y };
}

VectorII blokVectorIIMultiply(
    const VectorII veca,
    const VectorII vecb)
{
    return (VectorII){ veca.x * vecb.x, veca.y * vecb.y };
}