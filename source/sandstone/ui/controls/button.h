/**
 * @file   button.h
 * @brief  Button Declarations
 * @author harshjayprakash
 * @date   2025-08-04
 ****************************************************************************************/

#ifndef ST_BUTTON_H
#define ST_BUTTON_H

#include <windows.h>

#define ST_BUTTON_TEXT_SIZE 60

/**
 * @brief Button control.
 */
typedef struct _Button
{
    WCHAR text[ST_BUTTON_TEXT_SIZE]; /**< The button text. */
    RECT region;                     /**< The button region. */
    SIZE size;                       /**< The button size. */
    SIZE margin;                     /**< The button margin. */
    POINT position;                  /**< The button position. */
} TButton;

/**
 * @brief Updates the button geometry and layout metadata.
 * 
 * @details
 * Sets or updates position, size ands margin. If any pointer is NULL, the corresponding
 * value is left unchanged.
 * 
 * @param[in, out] pButton   Pointer to button.
 * @param[in]      pPos      Pointer to point denoting position.
 * @param[in]      pSize     Pointer to size.
 * @param[in]      pMargin   Pointer to size denoting margin.
 * @return `1` for success, `0` for failure.
 * 
 * @remarks
 * - This function must be called with all arguments for control initialisation.
 */
int stButtonUpdateEx(TButton *pButton, const POINT *pPos, const SIZE *pSize,
                     const SIZE *pMargin);

/**
 * @brief Shorthand for updating button position only.
 *
 * @details
 * A wrapper for `stButtonUpdateEx`, removing all the optional parameters.
 *
 * @param[in, out] pButton   Pointer to button.
 * @param[in]      pPos      Pointer to point denoting position.
 * @return `1` for success, `0` for failure.
 * 
 * @remarks
 * - The `stButtonUpdateEx` must be called for first time initialisation.
 */
int stButtonUpdate(TButton *pButton, const POINT *pPos);

#endif /* ST_BUTTON_H */