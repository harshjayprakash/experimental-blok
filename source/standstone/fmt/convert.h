/**
 * @file convert.h
 * @brief Conversion functions declarations.
 * @author harshjayprakash
 * @date 2025-07-19
 ****************************************************************************************/

#ifndef ST_CONVERT_H
#define ST_CONVERT_H

#include "../model/vector.h"
#include <windows.h>

/**
 * @brief Converts Win32 POINT to TVector2
 * 
 * Maps the values from POINT to TVector2 without modification.
 * 
 * @param[in] pt The point to be converted.
 * @return A TVector2.
 */
TVector2 stConvertPointV(const POINT pt);

/**
 * @brief Converts TVector2 to Win32 POINT.
 * 
 * Maps the values from TVector2 to POINT without modification.
 * 
 * @param[in] vec The vector to be converted.
 * @return A POINT.
 */
POINT stConvertVectorPoint(const TVector2 vec);

/**
 * @brief Converts TVector2 to Win32 SIZE.
 * 
 * Maps the values from TVector2 to SIZE without modification.
 * 
 * @param[in] vec The vector to be converted.
 * @return A SIZE.
 */
SIZE stConvertVectorSize(const TVector2 vec);

/**
 * @brief Converts two TVector2s to Win32 RECT.
 * 
 * Maps the two TVector2s to the resulting RECT, where position denotes the top and left
 * values. The size is used to calculate the right and bottom values.
 * 
 * @param[in] pos  The position of the rectangle.
 * @param[in] size The size of the rectangle.
 * @return A RECT.
 */
RECT stConvertVectorRect(const TVector2 pos, const TVector2 size);

/**
 * @brief Retrieves position from Win32 RECT.
 * 
 * Retrieves the top and left values as the position mapped to the TVector2 type.
 * 
 * @param[in] rect The rectangle to retrieve the position from.
 * @return A TVector2 denoting position.
 */
TVector2 stConvertRectPositionV(const RECT rect);

/**
 * @brief Retrieves size from Win32 RECT.
 * 
 * Retrieves the size by calculating the difference between values:
 * `height = bottom - top`, `width = right - left`.
 * 
 * @param[in] rect The rectangle to retrieve the size from.
 * @return A TVector2 denoting size.
 */
TVector2 stConvertRectSizeV(const RECT rect);

#endif /* ST_CONVERT_H */