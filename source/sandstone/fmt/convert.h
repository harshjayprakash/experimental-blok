/**
 * @file   convert.h
 * @brief  Conversion Helper Declarations.
 * @author harshjayprakash
 * @date   2025-08-03
 ****************************************************************************************/

#ifndef ST_CONVERT_H
#define ST_CONVERT_H

#include "../model/vector.h"
#include <windows.h>

/**
 * @brief Converts Win32 POINT to a TVector2
 * 
 * @details
 * Copies the `x` and `y` fields from the POINT structure into the `TVector2` format.
 * 
 * @param[in] pt   Structure with point coordinates.
 * @return A TVector2 structure.
 */
TVector2 stConvertVector2FromPoint(const POINT pt);

/**
 * @brief Converts TVector2 to a Win32 POINT.
 * 
 * @details
 * Assigns the `x` and `y` fields from the TVector2 to a POINT structure.
 * 
 * @param[in] vec   Vector to be mapped.
 * @return A POINT structure.
 */
POINT stConvertPointFromVector2(const TVector2 vec);

/**
 * @brief Converts TVector2 to a Win32 SIZE.
 * 
 * @details
 * Interprets the vector's `x` and `y` fields as width and height.
 * 
 * @param[in] vec   Vector to be mapped.
 * @return A SIZE structure.
 */
SIZE stConvertSizeFromVector2(const TVector2 vec);

/**
 * @brief Builds a Win32 RECT from position and size vectors.
 * 
 * @details
 * Uses `pos` as the top-left corner and adds `size` to compute the bottom-right edge.
 * 
 * @param[in] pos    Vector representing the origin.
 * @param[in] size   Vector representing the width and height.
 * @return A RECT with calculated boundaries.
 */
RECT stConvertRectFromVector2s(const TVector2 pos, const TVector2 size);

/**
 * @brief Extracts the top-left position from a RECT into a TVector2.
 * 
 * @details
 * Returns a vector representing the `top` and `left` fields of the RECT.
 * 
 * @param[in] rect   A RECT structure.
 * @return A TVector2 containing position data.
 */
TVector2 stConvertVector2PositionFromRect(const RECT rect);

/**
 * @brief Computes size from a RECT and returns as a TVector2.
 * 
 * @details
 * Calculates width and height using `right - left` and `bottom - top`.
 * 
 * @param[in] rect   A RECT structure.
 * @return A TVector2 representing size.
 */
TVector2 stConvertSizeVector2FromRect(const RECT rect);

#endif /* ST_CONVERT_H */