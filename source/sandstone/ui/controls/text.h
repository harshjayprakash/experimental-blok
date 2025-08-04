/**
 * @file   text.h
 * @brief  Text Declarations
 * @author harshjayprakash
 * @date   2025-08-04
 ****************************************************************************************/

#ifndef ST_TEXT_H
#define ST_TEXT_H

#include <windows.h>

#define ST_TEXT_SIZE 60

/**
 * @brief Text control.
 */
typedef struct _Text
{
    WCHAR data[ST_TEXT_SIZE]; /**< The text. */
    RECT region;              /**< The text region. */
    SIZE size;                /**< The text size. */
    SIZE margin;              /**< The text margin. */
    POINT position;           /**< The text position. */
} TText;

/**
 * @brief Update text geometry and layout.
 * 
 * @details
 * Sets or updates position and size. Computes the `region`.
 * 
 * @param[in, out] pText    Pointer to text.
 * @param[in]      pPoint   Pointer to point denoting position.
 * @param[in]      pSize    Pointer to size.
 * @return `1` on success, `0` on failure.
 * 
 * @remarks
 * - This function must be called with all arguments for control initialisation.
 */
int stTextUpdateEx(TText *pText, const POINT *pPoint, const SIZE *pSize,
                   const SIZE *pMargin);

/**
 * @brief Shorthand for updating text position only.
 * 
 * @details
 * Delegates to `stTextUpdateEx` with size of NULL.
 * 
 * @param[in, out] pText    Pointer to text.
 * @param[in]      pPoint   Pointer to point denoting position.
 * @return `1` on success, `0` on failure.
 * 
 * @remarks
 * - For initialisation please use the `stTextUpdateEx` function.
 */
int stTextUpdate(TText *pText, const POINT *pPosition);

#endif /* ST_TEXT_H */