/**
 * @file direction.h
 * @brief Direction Declarations.
 * @author harshjayprakash
 * @date 2025-07-20
 ****************************************************************************************/

#ifndef ST_DIRECTION_H
#define ST_DIRECTION_H

#include "vector.h"

/**
 * @brief Denotes Compass Rose Direction.
 * 
 * @details
 *  Provides direction based on the four main compass rose each assigned to the clock
 *  intervals.
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
 * @details
 *  Maps the direction to a vector mask denoting the direction with 1 and/or 0 as the
 *  x and y positions.
 * 
 * @param[in] direction Direction to be converted.
 * @return The resulting vector.
 * 
 * @remark
 *  A NULL vector {0, 0} is returned if the direction is invalid.
 * @remark
 *  The can scale the vector using the Vector2* functions.
 */
TVector2 stDirectionToVector(const TDirection direction);

#endif /* ST_DIRECTION_H */