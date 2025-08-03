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
    /**
     * @brief Position of the square.
     */
    TVector2 position;

    /**
     * @brief Size of the square.
     */
    TVector2 size;
} TSquare;

#endif /* ST_SQUARE_H */