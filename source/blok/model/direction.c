#include "direction.h"

TVector2 blokDirectionToVector(
    const TDirection direction)
{
    switch (direction)
    {
    case BLOK_DIRECTION_NORTH:
        return (TVector2){ 0, -1 };

    case BLOK_DIRECTION_EAST:
        return (TVector2){ 1, 0 };

    case BLOK_DIRECTION_SOUTH:
        return (TVector2){ 0, 1 };

    case BLOK_DIRECTION_WEST:
        return (TVector2){ -1, 0 };

    default:
        return (TVector2){ 0, 0 };
    }
}