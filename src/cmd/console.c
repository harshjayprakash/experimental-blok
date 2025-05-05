#include "console.h"
#include <Windows.h>

void blokConsoleInit(Console *pConhost)
{
    if (!pConhost) { return; }

    pConhost->initialised = 1;
    pConhost->conResult = AllocConsole();

    if (pConhost->conResult == 0)
    {
        (void) MessageBoxW(
            0, L"Console Initialisation Failed.", L"Blok", MB_OK | MB_ICONERROR);
        return;
    }

    pConhost->fileResult = freopen_s(&pConhost->pOutput, "CONOUT$", "w", stdout);

    if (pConhost->fileResult != 0)
    {
        (void) MessageBoxW(
            0, L"Opening StdOut Failed.", L"Blok", MB_OK | MB_ICONERROR);
    }

    (void) SetConsoleTitleW(L"Blok Console");
}

void blokConsoleFree(Console *pConhost)
{
    if (!pConhost) { return; }
    if (!pConhost->initialised) { return; }

    if (pConhost->fileResult == 0)
    {
        (void) fclose(stdout);
    }

    if (pConhost->conResult != 0)
    {
        (void) FreeConsole();
    }
}