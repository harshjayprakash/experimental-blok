/**
 * \file CONSOLE.C
 * \date 21-05-2025
 * \brief Implementation of the console lifecycle routines.
 */

#include "console.h"
#include <Windows.h>

int blokConsoleInit(
    Console *pConhost)
{
    if (pConhost == NULL) {
        return 0;
    }

    pConhost->isInitialised = AllocConsole();
    
    if (pConhost->isInitialised == 0) {
        (void)MessageBoxW(
            NULL, L"Console initialisation failed", L"Blok", MB_OK | MB_ICONERROR);
        return 0;
    }

    pConhost->errorOnAlloc = _wfreopen_s(
        &pConhost->pStandardOut, L"CONOUT$", L"w", stdout);
    
    if (pConhost->errorOnAlloc != 0) {
        (void)MessageBoxW(
            NULL, L"Opening standard out file stream failed", L"Blok", 
            MB_OK | MB_ICONERROR);
        blokConsoleFree(pConhost);
        return 0;
    }

    (void)SetConsoleTitleW(L"Blok Console");

    return 1;
}

int blokConsoleFree(
    Console *pConhost)
{
    if (pConhost == NULL) {
        return 0;
    }

    if (pConhost->errorOnAlloc == 0) {
        (void)fclose(stdout);
    }

    if (pConhost->isInitialised != 0) {
        (void)FreeConsole();
    }

    return 1;
}
