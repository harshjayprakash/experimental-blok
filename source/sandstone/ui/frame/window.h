/**
 * @file   window.h
 * @brief  Native Window Declarations.
 * @author harshjayprakash
 * @date   2025-08-03
 ****************************************************************************************/

#ifndef ST_WINDOW_H
#define ST_WINDOW_H

#include <windows.h>

/**
 * @brief Native Window.
 */
typedef struct _Window
{
    HWND hHandle;      /**< Handle to the window. */
    WNDCLASSEXW klass; /**< Native window class. */
    LPWSTR klassName;  /**< Window class name. */
    LPWSTR caption;    /**< Window text. */
    ATOM klassAtomIdx; /**< Registered window class atom index. */
} TWindow;

/**
 * @brief Initialise the window.
 *
 * @details
 * Registers the window class, then attempts to create the window.
 *
 * @param[in, out] pWindow     Pointer to the window structure.
 * @param[in]      hInstance   Handle to the application instance.
 * @return `0` for failure, `1` for success.
 *
 * @remark
 * - The corresponding free function (stWindowFree) must be used to clean-up the allocated
 *   and registered resources.
 */
int stWindowInit(TWindow *pWindow, HINSTANCE hInstance);

/**
 * @brief Show the window.
 *
 * @details
 * Shows the window and runs the message loop.
 *
 * @param[in, out] pWindow     Pointer to the window structure.
 * @param[in]      showFlag    Initial window display state.
 * @return The exit code, `-1` for failure.
 */
int stWindowShow(TWindow *pWindow, DWORD showFlag);

/**
 * @brief Free the window.
 *
 * @details
 * Cleans-up the allocated resources and unregister the window class.
 *
 * @param[in, out] pWindow     Pointer to the window structure.
 * @param[in]      hInstance   Handle to the application instance.
 * @return `0` for failure, `1` for success.
 */
int stWindowFree(TWindow *pWindow, HINSTANCE hInstance);

#endif /* ST_WINDOW_H */