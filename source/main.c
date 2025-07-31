/**
 * @file main.c
 * @brief Entrypoint.
 * @author harshjayprakash
 * @date 2025-07-31
 ****************************************************************************************/

#include "sandstone/core/lifecycle.h"
#include <windows.h>

/**
 * @brief Entrypoint for the Windows Application.
 *
 * @details
 * This function initialises the application, delegating the setup to the `stSetup`
 * function. It performs a single-instance check unless the build-time toggle
 * `STF_NO_SINGLE_INSTANCE` is defined.
 * 
 * The instance check uses a named mutex (`blokInstance`) to prevent multiple launches.
 * If a previous instance is detected, the user is notified via a message box, terminating
 * the program with an appropriate `TExitStatus` code.
 *
 * @param[in] hInstance     Handle to the application instance.
 * @param[in] hPrevInstance Legacy instance handle (unused).
 * @param[in] lpCmdLine     Unicode command-line arguments.
 * @param[in] nShowCmd      Initial window display state.
 * @return Exit status from `stSetup()` or early termination if instance check fails.
 *         Refer to `TExitStatus` for specific codes.
 */
int WINAPI wWinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPWSTR lpCmdLine,
    int nShowCmd)
{
    (void)hPrevInstance;
    
#ifndef STF_NO_SINGLE_INSTANCE
    HANDLE hInstanceMutex = CreateMutexW(NULL, TRUE, L"BlokInstance");

    if (hInstanceMutex == NULL)
    {
        (void)MessageBoxW(NULL, L"Instance check failed. The program will now exit.",
                          L"Blok", MB_OK | MB_ICONERROR);

        return ST_EXIT_INSTANCE_CHECK_ERROR;
    }

    if (GetLastError() == ERROR_ALREADY_EXISTS)
    {
        (void)MessageBoxW(NULL,
                          L"An instance of Blok is already running. "
                          "Please close the other instance before starting a new one.",
                          L"Blok", MB_OK | MB_ICONERROR);

        (void)CloseHandle(hInstanceMutex);

        return ST_EXIT_INSTANCE_RUNNING;
    }
#endif

    int status = stSetup(hInstance, lpCmdLine, nShowCmd);

#ifndef STF_NO_SINGLE_INSTANCE
    (void)CloseHandle(hInstanceMutex);
#endif

    return status;
}