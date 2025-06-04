/**
 * @file PANEL.H
 * @date 02-05-2025
 * @brief Provides the panel component structure and update routines.
 */

#ifndef _BLOK_PANEL_H_
#define _BLOK_PANEL_H_

#include <windows.h>

/**
 * @brief Panel component.
 *
 * @details
 * Represents the panel component properties.
 */
typedef struct _Panel {
    RECT region;      /**< The panel region. */
    SIZE margin;      /**< The panel margin. */
    POINT position;   /**< The panel position. */
    SIZE size;        /**< The panel size. */
} Panel;

/**
 * @brief Update the panel (extended).
 * 
 * @note
 * This routine must be called to initialise the panel. All the arguments must be provided
 * in this first call.
 *
 * @param[in out] pPanel       The pointer to the panel.
 * @param[in]     pWindowRgn   The window region.
 * @param[in]     pSize        The size.
 * @param[in]     pMargin      The margin.
 * @return                     0 for failure, 1 for success. 
 */
int blokPanelUpdateEx(
    Panel *pPanel, const RECT *pWindowRgn, const SIZE *pSize, const SIZE *pMargin);

/**
 * @brief Update the panel.
 *
 * @note
 * The extended version of this routine must be called first.
 * 
 * @param[in out] pPanel       The pointer to the panel.
 * @param[in]     pWindowRgn   The window region.
 * @return                     0 for failure, 1 for success.
 */
int blokPanelUpdate(Panel *pPanel, const RECT *pWindowRgn);

#endif // _BLOK_PANEL_H_