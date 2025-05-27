/**
 * @file ACTION.H
 * @date 27-05-2025
 * @brief Provides the action routines.
 */

#ifndef _BLOK_ACTION_H_
#define _BLOK_ACTION_H_

#include "../../model/direction.h"
#include "../../context.h"
#include <windows.h>
#include <windowsx.h>

/**
 * @brief Move the box.
 * 
 * @param[in out] pViewport   The pointer to the viewport.
 * @param[in out] pState      The pointer to the object state.
 * @param[in]     hWindow     The window handle.
 * @param[in]     direction   The direction the box should move.
 * @return                    0 for failure, 1 for success.
 */
int blokActionMoveBox(
    Viewport *pViewport, State *pState, HWND hWindow, Direction direction);

/**
 * @brief Toggle the grid lines.
 * 
 * @param[in out] pViewport   The pointer to the viewport.
 * @param[in]     hWindow     The window handle.
 * @return                    0 for failure, 1 for success.
 */
int blokActionToggleGridLines(Viewport *pViewport, HWND hWindow);

/**
 * @brief Toggle the interface visibility.
 * 
 * @param[in out] pViewport   The pointer to the viewport.
 * @param[in]     hWindow     The window handle.
 * @return                    0 for failure, 1 for success.
 */
int blokActionToggleInterface(Viewport *pViewport, HWND hWindow);

/**
 * @brief Toggle the canvas lock.
 * 
 * @param[in out] pViewport   The pointer to the viewport.
 * @param[in]     hWindow     The window handle.
 * @return                    0 for failure, 1 for success.
 */
int blokActionToggleCanvasLock(Viewport *pViewport, HWND hWindow);

/**
 * @brief Change the program theme.
 * 
 * @param[in out] pGraphics   The pointer to the graphics.
 * @param[in]     hWindow     The window handle.
 * @return                    0 for failure, 1 for success.
 */
int blokActionChangeTheme(Graphics *pGraphics, HWND hWindow);

/**
 * @brief Add an obstruct.
 * 
 * @param[in out] pViewport   The pointer to the viewport.
 * @param[in out] pState      The pointer to the object state.
 * @param[in]     hWindow     The window handle.
 * @param[in]     pPoint      (Optional) The point to be added.
 * @return                    0 for failure, 1 for success.
 */
int blokActionAddObstruct(
    Viewport *pViewport, State *pState, HWND hWindow, const POINT *pPoint);

/**
 * @brief Remove an obstruct.
 * 
 * @param[in out] pViewport   The pointer to the viewport.
 * @param[in out] pState      The pointer to the object state.
 * @param[in]     hWindow     The window handle.
 * @param[in]     point       The point to be removed.
 * @return                    0 for failure, 1 for success.
 */
int blokActionRemoveObstruct(
    Viewport *pViewport, State *pState, HWND hWindow, const POINT point);

/**
 * @brief Clear all obstructs.
 * 
 * @param[in out] pViewport   The pointer to the viewport.
 * @param[in out] pState      The pointer to the object state.
 * @param[in]     hWindow     The window handle.
 * @return                    0 for failure, 1 for success.
 */
int blokActionClearObstructs(Viewport *pViewport, State *pState, HWND hWindow);

#endif // _BLOK_ACTION_H_