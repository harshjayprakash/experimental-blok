/**
 * @file direction.h
 * @brief Direction enumeration and conversion declaration.
 * @author harshjayprakash
 * @date 2025-07-19
 ****************************************************************************************/

#ifndef _BLOK_DIRECTION_H_
#define _BLOK_DIRECTION_H_

#include "vector.h"

/**
 * @brief Denotes compass rose direction.
 * 
 * Provides direction based on the four main compass rose each assigned to the clock
 * intervals.
 */
typedef enum _Direction
{
    BLOK_DIRECTION_UNSET = 0,
    BLOK_DIRECTION_NORTH = 12,
    BLOK_DIRECTION_EAST = 3,
    BLOK_DIRECTION_SOUTH = 6,
    BLOK_DIRECTION_WEST = 9,
} TDirection;

/**
 * @brief Convert Direction to Vector.
 * 
 * @param[in] direction Direction to be converted.
 * @return The resulting vector.
 */
TVector2 blokDirectionToVector(const TDirection direction);

#endif /* _BLOK_DIRECTION_H_ */