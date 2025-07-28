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
    
    return stSetup(hInstance, lpCmdLine, nShowCmd);
}