#include "base/lifecycle.h"
#include <Windows.h>

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
            NULL, L"Mutex creation failed. The program will now exit.", L"Blok", 
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
    blokInit(pContext, hInstance, lpCmdLine, nShowCmd);
    blokRun(pContext);
    blokFree(pContext);

    (void)CloseHandle(hInstanceMutex);
    
    return 0;
}