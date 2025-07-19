/**
 * @file main.c
 * @brief Entrypoint.
 * @author harshjayprakash
 * @date 2025-07-19
 ****************************************************************************************/

#include "standstone/core/lifecycle.h"
#include <windows.h>

/**
 * @brief Windows application entrypoint.
 * 
 * @details
 * Attempts to perform an instance check. If there is no other instance running, the
 * program will continue to execute, else it will exit.
 * 
 * @param[in] hInstance     The handle to the application instance.
 * @param[in] hPrevInstance Always NULL.
 * @param[in] lpCmdLine     The zero-terminated string of command line arguments.
 * @param[in] nShowCmd      The flag on how the window will be displayed.
 * @return Zero for success, non-zero for failure.
 * 
 * @remarks
 * - Application start-up can be prevented by using the same mutex string.
 * - Unicode-only. Wide character version functions are specifically used.
 */
int WINAPI wWinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPWSTR lpCmdLine,
    int nShowCmd)
{
    (void)hPrevInstance;
    
    return stSetup(hInstance, lpCmdLine, nShowCmd);
}