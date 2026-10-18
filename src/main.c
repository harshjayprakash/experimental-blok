#include "blok/core/lifecycle.h"
#include <windows.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine,
                    int nShowCmd)
{
    (void)hPrevInstance;

    HANDLE hInstanceMutex = CreateMutexW(NULL, TRUE, L"BlokInstance");

    if (hInstanceMutex == NULL)
    {
        (void)MessageBoxW(NULL, L"Instance check failed. The program will now exit.",
                          L"Blok", MB_OK | MB_ICONERROR);

        return BLOK_EXIT_INSTANCE_CHECK_ERROR;
    }

    if (GetLastError() == ERROR_ALREADY_EXISTS)
    {
        (void)MessageBoxW(NULL,
                          L"An instance of Blok is already running. "
                          "Please close the other instance before starting a new one.",
                          L"Blok", MB_OK | MB_ICONERROR);

        (void)CloseHandle(hInstanceMutex);

        return BLOK_EXIT_INSTANCE_RUNNING;
    }

    int status = BlokSetup(hInstance, lpCmdLine, nShowCmd);

    (void)CloseHandle(hInstanceMutex);

    return status;
}