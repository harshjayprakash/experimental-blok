#include "base/lifecycle.h"
#include <Windows.h>

int WINAPI wWinMain(
    HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd)
{
    (void) hPrevInstance;

    HANDLE instanceMutex = CreateMutexW(NULL, TRUE, L"BlokInstance");

    if (!instanceMutex)
    {
        (void) MessageBoxW(
            NULL, L"Mutex creation failed. The program will now exit.", L"Blok", 
            MB_OK | MB_ICONERROR);
        return 1;
    }

    if (GetLastError() == ERROR_ALREADY_EXISTS)
    {
        (void) MessageBoxW(
            NULL, L"An instance of Blok is already running. "
            "Please close the other instance before starting a new one.", L"Blok",
            MB_OK | MB_ICONERROR);
        (void) CloseHandle(instanceMutex);
        return 1;
    }

    Context *context = BlokContextGet();
    
    BlokInit(context, hInstance, lpCmdLine, nShowCmd);
    BlokRun(context);
    BlokFree(context);

    (void) CloseHandle(instanceMutex);
    
    return 0;
}