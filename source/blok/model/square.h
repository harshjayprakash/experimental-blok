/**
 * @file SQUARE.H
 * @date 23-05-2023
 * @brief Provides the square structure.
 */

#ifndef _BLOK_SQUARE_H_
#define _BLOK_SQUARE_H_

#include "vector.h"

/**
 * @brief Square.
 * 
 * @details
 * Represents the square object.
 */
typedef struct _Square {
    VectorII position;   /**< The square's position. */
    VectorII size;       /**< The square size. */
} Square;

#endif // _BLOK_SQUARE_H_