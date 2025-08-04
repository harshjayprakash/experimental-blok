/**
 * @file   toggle.h
 * @brief  Toggle Button Declarations
 * @author harshjayprakash
 * @date   2025-08-04
 ****************************************************************************************/

#ifndef ST_TOGGLE_H
#define ST_TOGGLE_H

#include <windows.h>

/**
 * @brief Toggle button control.
 */
typedef struct _Toggle
{
    RECT region;       /**< Toggle region. */
    POINT position;    /**< Toggle position. */
    SIZE size;         /**< Toggle size. */
    SIZE margin;       /**< Toggle outer margin. */
    RECT selectRegion; /**< Toggle selectable region. */
    SIZE selectMargin; /**< Toggle inner margin. */
    BOOL selected;     /**< Is selected state. */
} TToggle;

/**
 * @brief Updates the toggle button geometry and layout metadata.
 * 
 * @details
 * Set or updates position, size, margin and inner margin. Computes the `region` and
 * the `selectRegion`. If any pointer is NULL, the corresponding values are left
 * unchanged.
 * 
 * @param[in, out] pToggle         Pointer to toggle.
 * @param[in]      pPosition       Pointer to the position.
 * @param[in]      pSize           Pointer to the size.
 * @param[in]      pMargin         Pointer to the size denoting the margin.
 * @param[in]      pSelectMargin   Pointer to the size denoting inner margin.
 * @return `1` on success, `0` on failure.
 * 
 * @remarks
 * - This function must be called with all arguments for control initialisation.
 */
int stToggleUpdateEx(TToggle *pToggle, const POINT *pPosition, const SIZE *pSize,
                     const SIZE *pMargin, const SIZE *pSelectMargin);

/**
 * @brief Shorthand for updating toggle position only.
 * 
 * @details
 * Delegates to `stToggleUpdateEx` with other arguments as NULL.
 * 
 * @param[in, out] pToggle         Pointer to toggle.
 * @param[in]      pPosition       Pointer to the position.
 * @return `1` on success, `0` on failure.
 * 
 * @remarks
 * - For initialisation please use the `stTextUpdateEx` function.
 */
int stToggleUpdate(TToggle *pToggle, const POINT *pPosition);

/**
 * @br1ef Update toggle selected state.
 * 
 * @details
 * Sets the `selected` attribute.
 * 
 * @param[in, out] pToggle    Pointer to toggle.
 * @param[in]      selected   Selected state.
 * @return `1` on success, `0` on failure.
 */
int stToggleUpdateSelected(TToggle *pToggle, const BOOL selected);

#endif /* ST_TOGGLE_H */