#ifndef BLOK_DIRECTION_H
#define BLOK_DIRECTION_H

#include "vector.h"

typedef enum _Direction
{
    BLOK_DIRECTION_UNSET = 0,
    BLOK_DIRECTION_NORTH = 12,
    BLOK_DIRECTION_EAST = 3,
    BLOK_DIRECTION_SOUTH = 6,
    BLOK_DIRECTION_WEST = 9,
} TDirection;

TVector2 BlokDirectionToVector(const TDirection direction);

#endif /* BLOK_DIRECTION_H */