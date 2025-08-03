/**
 * @file   vector.c
 * @brief  Vector Implementation.
 * @author harshjayprakash
 * @date   2025-07-22
 ****************************************************************************************/

#include "vector.h"
#include <stdlib.h>

int stVector2Copy(TVector2 *pDest, const TVector2 src)
{
    if (pDest == NULL)
    {
        return 0;
    }

    pDest->x = src.x;
    pDest->y = src.y;

    return 1;
}

int stVector2Equals(const TVector2 veca, const TVector2 vecb)
{
    return (veca.x == vecb.x && veca.y == vecb.y);
}

TVector2 stVector2Offset(const TVector2 vec, const TVector2 offsetVec)
{
    return (TVector2){vec.x + offsetVec.x, vec.y + offsetVec.y};
}

TVector2 stVector2Multiply(const TVector2 veca, const TVector2 vecb)
{
    return (TVector2){veca.x * vecb.x, veca.y * vecb.y};
}