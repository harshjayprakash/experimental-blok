#include "console.h"
#include <windows.h>

int blokConsoleInit(TConsoleInfo *pConsoleInfo)
{
    if (pConsoleInfo == NULL) {
        return 0;
    }

    if (pConsoleInfo->isInitialised) {
        return 0;
    }

    pConsoleInfo->isInitialised = AllocConsole();

    if (pConsoleInfo->isInitialised == 0) {
        return 0;
    }

    pConsoleInfo->errorOnAlloc =
        _wfreopen_s(&pConsoleInfo->pStandardOut, L"CONOUT$", L"w", stdout);

    if (pConsoleInfo->errorOnAlloc != 0) {
        blokConsoleFree(pConsoleInfo);
        return 0;
    }

    (void)SetConsoleTitleW(L"Blok Console");

    return 1;
}

int blokConsoleFree(TConsoleInfo *pConsoleInfo)
{
    if (pConsoleInfo == NULL) {
        return 0;
    }

    int streamNotClosed = 1;
    int consoleClosed = 0;

    if (pConsoleInfo->errorOnAlloc == 0) {
        streamNotClosed = fclose(stdout);
    }

    if (pConsoleInfo->isInitialised != 0) {
        consoleClosed = FreeConsole();
    }

    return (!streamNotClosed && consoleClosed);
}
