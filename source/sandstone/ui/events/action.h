/**
 * @file   action.h
 * @brief  State Actions Declarations
 * @author harshjayprakash
 * @date   2025-08-04
 ****************************************************************************************/

#ifndef ST_ACTION_H
#define ST_ACTION_H

#include "../../core/context.h"
#include "../../model/direction.h"
#include <windows.h>
#include <windowsx.h>

/**
 * @brief Moves the box.
 * 
 * @details
 * Checks if the box is movable in the given direction. If movable, the box is moved
 * and the coordinates text is updated. The appropriate regions are invalidated.
 * 
 * @param[in, out] pViewport   Pointer to viewport.
 * @param[in, out] pState      Pointer to object state.
 * @param[in]      hWindow     Handle to window.
 * @param[in]      direction   Direction to move.
 * @return `1` for success (or box is not movable), `0` for failure.
 * 
 * @see stStateIsBoxMovable
 * @see stStateMoveBox
 */
int stActionMoveBox(TViewport *pViewport, TObjectState *pState, HWND hWindow,
                    TDirection direction);

/**
 * @brief Toggle grid lines.
 * 
 * @details
 * Toggles the `isGridVisible` UI flag and invalidates the canvas region.
 * 
 * @param[in, out] pViewport   Pointer to viewport.
 * @param[in]      hWindow     Handle to window.
 * @return `1` for success, `0` for failure.
 * 
 * @see TViewport
 * 
 * @remarks
 * - The flag is used to determine whether the grid should be painted in the
 *   `stProcessEventOnPaint` function.
 */
int stActionToggleGridLines(TViewport *pViewport, HWND hWindow);

/**
 * @brief Toggle interface.
 * 
 * @details
 * Toggles the `isInterfaceVisible` UI flag and invalidates the canvas region.
 * 
 * @param[in, out] pViewport   Pointer to viewport.
 * @param[in]      hWindow     Handle to window.
 * @return `1` for success, `0` for failure.
 * 
 * @see TViewport
 * 
 * @remarks
 * - The flag is used to determine whether the interface should be painted in the
 *   `stProcessEventOnPaint` function.
 */
int stActionToggleInterface(TViewport *pViewport, HWND hWindow);

/**
 * @brief Toggle canvas lock.
 * 
 * @details
 * Toggles the `isCanvasLocked` UI flag and updates the toggle button visual state.
 * 
 * @param[in, out] pViewport   Pointer to viewport.
 * @param[in]      hWindow     Handle to window.
 * @return `1` for success, `0` for failure.
 * 
 * @see TToggle
 * @see stToggleUpdateSelected
 * 
 * @remarks
 * - The flag is used to determine whether any clicks via the cursor should be able to
 *   interact with the canvas.
 */
int stActionToggleCanvasLock(TViewport *pViewport, HWND hWindow);

/**
 * @brief Change theme.
 * 
 * @details
 * A wrapper for the switch theme graphics function and then invalidates the whole
 * window client area.
 * 
 * @param[in, out] pGraphics   Pointer to graphics context.
 * @param[in]      hWindow     Handle to window.
 * @return `1` for success, `0` for failure.
 * 
 * @see stGraphicsSwitchTheme
 */
int stActionChangeTheme(TGraphics *pGraphics, HWND hWindow);

/**
 * @brief Add obstruct.
 * 
 * @details
 * Checks the given new point. If this value is NULL, a point position will be randomly
 * generated. The function attempts to add this obstruct, update the count text, then
 * the progress bar. The appropriate regions are invalidated.
 * 
 * @param[in, out] pViewport   Pointer to viewport.
 * @param[in, out] pState      Pointer to object state.
 * @param[in]      hWindow     Handle to window.
 * @param[in]      pPoint      Pointer to new point.
 * @return `1` for success, `0` for failure.
 * 
 * @see stStateAddObstruct
 * @see stProgressBarUpdateValueEx
 */
int stActionAddObstruct(TViewport *pViewport, TObjectState *pState, HWND hWindow,
                        const POINT *pPoint);

/**
 * @brief Remove obstruct.
 * 
 * @details
 * Translates the point to TVector2, then attempts to remove the point. The obstruct
 * count text and progress bar is updated. The appropriate regions are invalidated. 
 * 
 * @param[in, out] pViewport   Pointer to viewport.
 * @param[in, out] pState      Pointer to object state.
 * @param[in]      hWindow     Handle to window.
 * @param[in]      point       Point to remove.
 * @return `1` for success, `0` for failure.
 * 
 * @see stStateRemoveObstruct
 * @see stProgressBarUpdateValueEx
 */
int stActionRemoveObstruct(TViewport *pViewport, TObjectState *pState, HWND hWindow,
                           const POINT point);

/**
 * @brief Clear obstructs.
 * 
 * @details
 * Attempts to clear all obstructs, updates the counter and progress bar. The appropriate
 * regions are invalidated. 
 * 
 * @param[in, out] pViewport   Pointer to viewport.
 * @param[in, out] pState      Pointer to object state.
 * @param[in]      hWindow     Handle to window.
 * @return `1` for success, `0` for failure.
 * 
 * @see stStateClearObstructs
 * @see stProgressBarUpdateValue
 */
int stActionClearObstructs(TViewport *pViewport, TObjectState *pState, HWND hWindow);

/**
 * @brief Generate random obstructs.
 * 
 * @details
 * Clears all obstructs and generates a number of obstructs based on the size of the
 * client area.
 * 
 * @param[in, out] pViewport   Pointer to viewport.
 * @param[in, out] pState      Pointer to object state.
 * @param[in]      hWindow     Handle to window.
 * @return `1` for success, `0` for failure.
 * 
 * @see stActionClearObstructs
 * @see stActionAddObstruct
 * 
 * @note
 * This is part of partially completed maze generation feature.
 */
int stActionGenerateRandomObstructs(TViewport *pViewport, TObjectState *pState,
                                    HWND hWindow);

#endif /* ST_ACTION_H */