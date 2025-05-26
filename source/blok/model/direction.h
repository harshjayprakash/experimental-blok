/**
 * @file DIRECTION.H
 * @date 22-05-2025
 * @brief Provides the direction enumeration and convert to vector routine.
 */

#ifndef _BLOK_DIRECTION_H_
#define _BLOK_DIRECTION_H_

#include "vector.h"

/**
 * @brief Direction.
 * 
 * @details
 * Denotes the directions of the compass rose, and values of the clock. An unset
 * direction has been provided as a default state.
 */
typedef enum _Direction {
    BLOK_DIRECTION_UNSET = 0,
    BLOK_DIRECTION_NORTH = 12,
    BLOK_DIRECTION_EAST = 3,
    BLOK_DIRECTION_SOUTH = 6,
    BLOK_DIRECTION_WEST = 9,
} Direction;

/**
 * @brief Direction to Vector.
 * 
 * @details
 * Converts the direction to a two dimensional vector by a magnitude interval of -1 and
 * 1. An unset or invalid direction will return a null vector {0, 0}.
 * 
 * @param[in] direction   The direction to be converted.
 * @return                The vector denoting direction.
 */
VectorII blokDirectionToVector(const Direction direction);

#endif // _BLOK_DIRECTION_H_