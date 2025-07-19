/**
 * @file console.c
 * @brief Console lifecycle implementation.
 * @author harshjayprakash
 * @date 2025-07-19
 ****************************************************************************************/

#include "console.h"
#include <windows.h>

int blokConsoleInit(
    TConsoleInfo *pConsoleInfo)
{
    if (pConsoleInfo == NULL)
    {
        return 0;
    }

    if (pConsoleInfo->isInitialised)
    {
        return 0;
    }

    pConsoleInfo->isInitialised = AllocConsole();

    if (pConsoleInfo->isInitialised == 0)
    {
        return 0;
    }

    pConsoleInfo->errorOnAlloc = _wfreopen_s(
        &pConsoleInfo->pStandardOut, L"CONOUT$", L"w", stdout);

    if (pConsoleInfo->errorOnAlloc != 0)
    {
        blokConsoleFree(pConsoleInfo);
        return 0;
    }

    (void)SetConsoleTitleW(L"Blok Console");

    return 1;
}

int blokConsoleFree(
    TConsoleInfo *pConsoleInfo)
{
    if (pConsoleInfo == NULL)
    {
        return 0;
    }

    if (!pConsoleInfo->isInitialised)
    {
        return 0;
    }

    int streamNotClosed = fclose(stdout);
    int consoleClosed = FreeConsole();

    int result = (!streamNotClosed && consoleClosed);

    if (result == 1)
    {
        pConsoleInfo->isInitialised = 0;
    }

    return result;
}
