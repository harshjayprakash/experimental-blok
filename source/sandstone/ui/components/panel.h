/**
 * @file   panel.h
 * @brief  Panel Declarations.
 * @author harshjayprakash
 * @date   2025-07-23
 ****************************************************************************************/

#ifndef ST_PANEL_H
#define ST_PANEL_H

#include <windows.h>

/**
 * @brief Represents the Panel Component.
 *
 * @details
 * Stores the panel dimensions. Use the stPanel* functions to manage these attributes.
 */
typedef struct _Panel
{
    RECT region;    /**< Panel region. */
    SIZE margin;    /**< Panel margin. */
    POINT position; /**< Position of the panel. */
    SIZE size;      /**< Size of the panel. */
} TPanel;

/**
 * @brief Update the panel component (extended version)
 *
 * @details
 * Update the panel dimensions.
 *
 * @param[in, out] pPanel       Pointer to the panel to be updated.
 * @param[in]      pWindowRgn   Pointer to the window client region.
 * @param[in]      pSize        Pointer to the SIZE denoting panel size.
 * @param[in]      pMargin      Pointer to the SIZE denoting the panel margin.
 * @return `1` for success, `0` for failure.
 *
 * @remarks
 * - This extended version of the function must be called once for the initialisation,
 *   with all arguments given. After this, the standard version can be called as it
 *   eliminates the optional components.
 */
int stPanelUpdateEx(TPanel *pPanel, const RECT *pWindowRgn, const SIZE *pSize,
                    const SIZE *pMargin);

/**
 * @brief Update the panel component.
 *
 * @details
 * Update the panel dimensions, ignoring optional components from the extended version of
 * the function.
 *
 * @param[in, out] pPanel       Pointer to the panel to be updated.
 * @param[in]      pWindowRgn   Pointer to the window client region.
 * @return `1` for success, `0` for failure.
 *
 * @remark
 * - The extended version of the function must be called first for initialisation.
 */
int stPanelUpdate(TPanel *pPanel, const RECT *pWindowRgn);

#endif /* ST_PANEL_H */