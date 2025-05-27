/**
 * @file PROCESS.H
 * @date 27-05-2025
 * @brief Provides the event processing routines.
 */

#ifndef _BLOK_PROCESS_H_
#define _BLOK_PROCESS_H_

#include <windows.h>

/**
 * @brief Process the "WM_PAINT" event.
 * 
 * @param[in] hWindow   The window handle.
 */
void blokProcessEventOnPaint(HWND hWindow);

/**
 * @brief Process the "WM_KEYDOWN" event.
 * 
 * @param[in] hWindow      The window handle.
 * @param[in] virtualKey   The key pressed.
 */
void blokProcessEventOnKeyDown(HWND hWindow, WPARAM virtualKey);

/**
 * @brief Process the "WM_LBUTTONDOWN" event.
 * 
 * @param[in] hWindow    The window handle.
 * @param[in] mousepos   The mouse position at event.
 */
void blokProcessEventOnLeftMouseDown(HWND hWindow, LPARAM mousepos);

/**
 * @brief Process the "WM_RBUTTONDOWN" event.
 * 
 * @param[in] hWindow    The window handle.
 * @param[in] mousepos   The mouse position at event.
 */
void blokProcessEventOnRightMouseDown(HWND hWindow, LPARAM mousepos);

/**
 * @brief Process the "WM_LBUTTONUP" event.
 * 
 * @param[in] hWindow    The window handle.
 * @param[in] mousepos   The mouse position at event.
 */
void blokProcessEventOnLeftMouseUp(HWND hWindow, LPARAM mousepos);

/**
 * @brief Process the "WM_RBUTTONUP" event.
 * 
 * @param[in] hWindow    The window handle.
 * @param[in] mousepos   The mouse position at event.
 */
void blokProcessEventOnRightMouseUp(HWND hWindow, LPARAM mousepos);

/**
 * @brief Process the "WM_SIZE" event.
 * 
 * @param[in] hWindow    The window handle.
 */
void blokProcessEventOnResize(HWND hWindow);

/**
 * @brief Process the "WM_MOUSEMOVE" event.
 * 
 * @param[in] hWindow    The window handle.
 * @param[in] mousepos   The mouse position at event.
 */
void blokProcessEventOnMouseHover(HWND hWindow, LPARAM mousepos);

#endif // _BLOK_PROCESS_H_