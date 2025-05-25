/**
 * \file MAIN.C
 * \date 18.05.2025
 * \brief Implementation of the wWinMain entrypoint routine.
 */

#include "base/lifecycle.h"
#include <Windows.h>

/**
 * \brief Windows Program Entrypoint.
 * 
 * \details
 * First performs an instance check. If and only if the instance check succeeds, the
 * context will be initialised, starting the user interface.
 * 
 * \param[in] hInstance       The instance handle.
 * \param[in] hPrevInstance   NULL. Not used in modern Windows.
 * \param[in] lpCmdLine       The command line arguments.
 * \param[in] nShowCmd        The window display flag.
 * \return                    A zero value for success, non-zero for failure.
 */
int WINAPI wWinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPWSTR lpCmdLine,
    int nShowCmd)
{
    (void)hPrevInstance;

    HANDLE hInstanceMutex = CreateMutexW(NULL, TRUE, L"BlokInstance");

    if (hInstanceMutex == NULL) {
        (void)MessageBoxW(
            NULL, L"Instance check failed. The program will now exit.", L"Blok", 
            MB_OK | MB_ICONERROR);
        return 1;
    }

    if (GetLastError() == ERROR_ALREADY_EXISTS) {
        (void)MessageBoxW(
            NULL, L"An instance of Blok is already running. "
            "Please close the other instance before starting a new one.", L"Blok",
            MB_OK | MB_ICONERROR);
        (void)CloseHandle(hInstanceMutex);
        return 1;
    }

    Context *pContext = blokContextGet();
    (void)blokInit(pContext, hInstance, lpCmdLine, nShowCmd);
    (void)blokRun(pContext);
    (void)blokFree(pContext);

    (void)CloseHandle(hInstanceMutex);
    
    return 0;
}