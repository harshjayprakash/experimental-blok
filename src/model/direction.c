#include "direction.h"

VectorII BlokDirectionToVector(const Direction direction)
{
    switch (direction)
    {
    case BLOK_DIRECTION_NORTH: return (VectorII) {0, -1};
    case BLOK_DIRECTION_EAST: return (VectorII) {1, 0};
    case BLOK_DIRECTION_SOUTH: return (VectorII) {0, 1};
    case BLOK_DIRECTION_WEST: return (VectorII) {-1, 0};
    default: return (VectorII){0, 0};
    }
}