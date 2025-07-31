/**
 * @file main.c
 * @brief Entrypoint.
 * @author harshjayprakash
 * @date 2025-07-20
 ****************************************************************************************/

#include "sandstone/core/lifecycle.h"
#include <windows.h>

/**
 * @brief Windows application entrypoint.
 *
 * @details
 *  Provides a wrapper for calling the stSetup.
 *
 * @param[in] hInstance     The handle to the application instance.
 * @param[in] hPrevInstance Always NULL.
 * @param[in] lpCmdLine     The null-terminated string of command line arguments.
 * @param[in] nShowCmd      How the window will be displayed.
 * @return Zero on success, non-zero indicates failure. For specific return values, refer
 *         to the TExitStatus enum.
 */
int WINAPI wWinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPWSTR lpCmdLine,
    int nShowCmd)
{
    (void)hPrevInstance;
    
#ifdef __ST_FEATURE_SINGLE_INSTANCE
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

#ifdef __ST_FEATURE_SINGLE_INSTANCE
    (void)CloseHandle(hInstanceMutex);
#endif

    return status;
}