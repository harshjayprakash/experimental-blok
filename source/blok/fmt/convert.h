/**
 * @file CONVERT.H
 * @date 26-05-2025
 * @brief Provides conversion routines.
 */

#ifndef _BLOK_CONVERT_H_
#define _BLOK_CONVERT_H_

#include "../model/vector.h"
#include <Windows.h>

/**
 * @brief Map POINT to Vector.
 * 
 * @param[in] point   The point to be converted.
 * @return            The resulting vector.
 */
VectorII blokConvertPointV(const POINT point);

/**
 * @brief Map Vector to POINT.
 * 
 * @param[in] vec   The vector to be converted.
 * @return          The resulting point.
 */
POINT blokConvertVectorPoint(const VectorII vec);

/**
 * @brief Map Vector to SIZE.
 * 
 * @param[in] vec   The vector to be converted.
 * @return          The resulting size.
 */
SIZE blokConvertVectorSize(const VectorII vec);

/**
 * @brief Map Vectors to RECT.
 * 
 * @param[in] pos    The position vector.
 * @param[in] size   The size vector.
 * @return           The resulting rectangle.
 */
RECT blokConvertVectorRect(const VectorII pos, const VectorII size);

/**
 * @brief Get Position Vector from RECT.
 * 
 * @param[in] rect   The rectangle to get the position of.
 * @return           The resulting position vector.
 */
VectorII blokConvertRectPositionV(const RECT rect);

/**
 * @brief Get Size Vector from RECT.
 * 
 * @param[in] rect   The rectangle to get the size of.
 * @return           The resulting size vector.
 */
VectorII blokConvertRectSizeV(const RECT rect);

#endif // _BLOK_CONVERT_H_