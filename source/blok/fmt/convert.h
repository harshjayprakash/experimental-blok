/**
 * @file   convert.h
 * @brief  Conversion Functions.
 * @author harshjayprakash
 * @date   2025-06-08
 ****************************************************************************************/

#ifndef _BLOK_CONVERT_H_
#define _BLOK_CONVERT_H_

#include "../model/vector.h"
#include <windows.h>

/**
 * @brief Map POINT to TVector2.
 * 
 * @param[in] pt The point to be converted.
 * @return The resulting TVector2.
 */
TVector2 blokConvertPointV(const POINT pt);

/**
 * @brief Map TVector2 to POINT.
 * 
 * @param[in] vec The vector to be converted.
 * @return The resulting POINT.
 */
POINT blokConvertVectorPoint(const TVector2 vec);

/**
 * @brief Map TVector2 to SIZE.
 * 
 * @param[in] vec The vector to be converted.
 * @return The resulting SIZE.
 */
SIZE blokConvertVectorSize(const TVector2 vec);

/**
 * @brief Map TVector2 position and size to RECT.
 * 
 * @param[in] pos The rectangle position.
 * @param[in] size The rectangle size.
 * @return The resulting RECT.
 */
RECT blokConvertVectorRect(const TVector2 pos, const TVector2 size);

/**
 * @brief Get position from RECT.
 * 
 * @param[in] rect The rectangle to retrieve position from.
 * @return The resulting TVector2 representing position.
 */
TVector2 blokConvertRectPositionV(const RECT rect);

/**
 * @brief Get size from RECT.
 * 
 * @param[in] rect The rectangle to retrieve size from.
 * @return The resulting TVector2 representing size. 
 */
TVector2 blokConvertRectSizeV(const RECT rect);

#endif /* _BLOK_CONVERT_H_ */