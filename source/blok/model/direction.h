#ifndef _BLOK_DIRECTION_H_
#define _BLOK_DIRECTION_H_

#include "vector.h"

typedef enum _Direction {
    BLOK_DIRECTION_UNSET = 0,
    BLOK_DIRECTION_NORTH = 12,
    BLOK_DIRECTION_EAST = 3,
    BLOK_DIRECTION_SOUTH = 6,
    BLOK_DIRECTION_WEST = 9,
} TDirection;

TVector2 blokDirectionToVector(const TDirection direction);

#endif /* _BLOK_DIRECTION_H_ */