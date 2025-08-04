/**
 * @file   square.h
 * @brief  Square Declarations.
 * @author harshjayprakash
 * @date   2025-07-22
 ****************************************************************************************/

#ifndef ST_SQUARE_H
#define ST_SQUARE_H

#include "vector.h"

/**
 * @brief Square Entity.
 */
typedef struct _Square
{
    TVector2 position; /**< Position of the square. */
    TVector2 size;     /**< Size of the square. */
} TSquare;

#endif /* ST_SQUARE_H */