/**
 * @file   process.h
 * @brief  Event Processing Declarations
 * @author harshjayprakash
 * @date   2025-08-04
 ****************************************************************************************/

#ifndef ST_PROCESS_H
#define ST_PROCESS_H

#include <windows.h>

/**
 * @brief Handle the `WM_PAINT` message.
 * 
 * @details
 * Paints all the components and controls to an off-screen buffer before copying to the
 * window surface.
 * 
 * @param[in] hWindow   Handle of window.
 */
void stProcessEventOnPaint(HWND hWindow);

/**
 * @brief Handle the `WM_KEYDOWN` message.
 * 
 * @details
 * A wrapper that calls the stAction* functions depending on the virtual key pressed.
 * 
 * @param[in] hWindow      Handle of window.
 * @param[in] virtualKey   Key pressed.
 */
void stProcessEventOnKeyDown(HWND hWindow, WPARAM virtualKey);

/**
 * @brief Handle the `WM_LBUTTONDOWN` message.
 * 
 * @details
 * Handles the click operations on the canvas and interactable components.
 * 
 * @param[in] hWindow    Handle of window.
 * @param[in] mousepos   Mouse position.
 * 
 * @see stActionAddObstruct
 * @see stActionClearObstructs
 * @see stActionToggleCanvasLock
 */
void stProcessEventOnLeftMouseDown(HWND hWindow, LPARAM mousepos);

/**
 * @brief Handle the `WM_RBUTTONDOWN` message.
 * 
 * @details
 * Updates the state of the right mouse button and invokes the remove obstruct action
 * function if the canvas is not locked.
 * 
 * @param[in] hWindow    Handle of window.
 * @param[in] mousepos   Mouse position.
 * 
 * @see stActionRemoveObstruct
 */
void stProcessEventOnRightMouseDown(HWND hWindow, LPARAM mousepos);

/**
 * @brief Handle the `WM_LBUTTONUP` message.
 * 
 * @details
 * Updates the state of the left mouse button stored.
 *
 * @param[in] hWindow    Handle of window.
 * @param[in] mousepos   Mouse position.
 */
void stProcessEventOnLeftMouseUp(HWND hWindow, LPARAM mousepos);

/**
 * @brief Handle the `WM_LBUTTONDOWN` message.
 * 
 * @details
 * Updates the state of the right mouse button stored.
 *
 * @param[in] hWindow    Handle of window.
 * @param[in] mousepos   Mouse position.
 */
void stProcessEventOnRightMouseUp(HWND hWindow, LPARAM mousepos);

/**
 * @brief Handle the `WM_SIZE` message.
 * 
 * @details
 * Updates all the controls and components based on the client window area bounds.
 *
 * @param[in] hWindow    Handle of window.
 * 
 * @see stPanelUpdate
 * @see stCanvasUpdate
 * @see stTextUpdate
 * @see stButtonUpdate
 * @see stProgressBarUpdate
 * @see stToggleUpdate
 */
void stProcessEventOnResize(HWND hWindow);

/**
 * @brief Handle the `WM_MOUSEMOVE` message.
 * 
 * @details
 * Updates the stored mouse position and handles the drag click operation if right
 * or left mouse buttons are down.
 *
 * @param[in] hWindow    Handle of window.
 * @param[in] mousepos   Mouse position.
 * 
 * @see stActionAddObstruct
 * @see stActionRemoveObstruct
 */
void stProcessEventOnMouseHover(HWND hWindow, LPARAM mousepos);

#endif /* ST_PROCESS_H */