/**
 * @file WINDOW.H
 * @date 27-05-2025
 * @brief Provides the Window structure and lifecycle functions.
 */

#ifndef _BLOK_WINDOW_H_
#define _BLOK_WINDOW_H_

#include <windows.h>

/**
 * @brief Window information.
 * 
 * @details
 * Represents the initialisation information.
 */
typedef struct _Window {
    HWND hHandle;        /**< The window handle. */
    WNDCLASSEXW klass;   /**< The window class. */
    LPWSTR klassName;    /**< The window class name. */
    LPWSTR caption;      /**< The window caption. */
    ATOM klassAtomIdx;   /**< The window class atom table index. */
} Window;

/**
 * @brief Initialise the window.
 * 
 * @details
 * Initialise and attempt to regsiter the window class. Then attempts to create the
 * window.
 * 
 * @param[in out] pWindow     The pointer to the window.
 * @param[in]     hInstance   The instance handle.
 * @return                    0 for failure, 1 for success.
 */
int blokWindowInit(Window *pWindow, HINSTANCE hInstance);

/**
 * @brief Show the window.
 * 
 * @details
 * Shows the window and starts the message loop.
 * 
 * @param[in out] pWindow    The pointer to the window.
 * @param[in]     showFlag   The window show flag.
 * @return                   -1 for failure, or the quit message exit code.
 */
int blokWindowShow(Window *pWindow, DWORD showFlag);

/**
 * @brief Free the window.
 * 
 * @details
 * Cleans up the resources allocated for the window class. The window class is
 * unregistered and the window itself destoyed.
 * 
 * @param[in out] pWindow     The pointer to the window.
 * @param[in]     hInstance   The instance handle.
 * @return                    0 for failure, 1 for success.
 */
int blokWindowFree(Window *pWindow, HINSTANCE hInstance);

#endif // _BLOK_WINDOW_H_