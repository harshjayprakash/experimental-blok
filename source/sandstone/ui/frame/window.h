/**
 * @file window.h
 * @brief Native Window Declarations.
 * @author harshjayprakash
 * @date 2025-07-22
 ****************************************************************************************/

#ifndef ST_WINDOW_H
#define ST_WINDOW_H

#include <windows.h>

/**
 * @brief Native Window.
 */
typedef struct _Window
{
    /**
     * @brief The handle to the Window.
     */
    HWND hHandle;

    /**
     * @brief The native window class.
     */
    WNDCLASSEXW klass;

    /**
     * @brief The window class name.
     */
    LPWSTR klassName;

    /**
     * @brief The window title caption.
     */
    LPWSTR caption;

    /**
     * @brief The registered window class atom index.
     */
    ATOM klassAtomIdx;
} TWindow;

/**
 * @brief Initialise the window.
 *
 * @details
 *  Registers the window class, then attempts to create the window.
 *
 * @param[in, out] pWindow   A valid pointer to the TWindow.
 * @param[in]      hInstance The handle to the application instance.
 * @return 0 for failure, 1 for success.
 *
 * @remark
 *  The corresponding free function (stWindowFree) must be used to clean-up the allocated
 *  and registered resources.
 */
int stWindowInit(TWindow *pWindow, HINSTANCE hInstance);

/**
 * @brief Show the window.
 *
 * @details
 *  Shows the window and runs the message loop.
 *
 * @param[in, out] pWindow  A valid pointer to the TWindow.
 * @param[in]      showFlag How the window will be displayed.
 * @return The exit code, -1 for failure.
 */
int stWindowShow(TWindow *pWindow, DWORD showFlag);

/**
 * @brief Free the window.
 *
 * @details
 *  Cleans-up the allocated resources and unregister the window class.
 *
 * @param[in, out] pWindow   A valid pointer to the TWindow.
 * @param[in]      hInstance The handle to the application instance.
 * @return 0 for failure, 1 for success.
 */
int stWindowFree(TWindow *pWindow, HINSTANCE hInstance);

#endif /* ST_WINDOW_H */