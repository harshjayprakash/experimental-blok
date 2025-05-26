/**
 * @file DIRECTION.C
 * @date 22-05-2025
 * @brief Implementation of the direction to vector routine.
 */

#include "direction.h"

VectorII blokDirectionToVector(
    const Direction direction)
{
    switch (direction) {
    case BLOK_DIRECTION_NORTH:
        return (VectorII){ 0, -1 };

    case BLOK_DIRECTION_EAST:
        return (VectorII){ 1, 0 };

    case BLOK_DIRECTION_SOUTH:
        return (VectorII){ 0, 1 };

    case BLOK_DIRECTION_WEST:
        return (VectorII){ -1, 0 };

    default:
        return (VectorII){ 0, 0 };
    }
}