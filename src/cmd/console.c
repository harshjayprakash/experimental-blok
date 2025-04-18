#include "console.h"
#include <Windows.h>

void BlokConsoleInit(Console *con)
{
    if (!con) { return; }

    con->initialised = 1;
    con->conResult = AllocConsole();

    if (con->conResult == 0)
    {
        (void) MessageBoxW(
            0, L"Console Initialisation Failed.", L"Blok", MB_OK | MB_ICONERROR);
        return;
    }

    con->fileResult = freopen_s(&con->output, "CONOUT$", "w", stdout);

    if (con->fileResult != 0)
    {
        (void) MessageBoxW(
            0, L"Opening StdOut Failed.", L"Blok", MB_OK | MB_ICONERROR);
    }

    (void) SetConsoleTitleW(L"Blok Console");
}

void BlokConsoleFree(Console *con)
{
    if (!con) { return; }
    if (!con->initialised) { return; }

    if (con->fileResult == 0)
    {
        (void) fclose(stdout);
    }

    if (con->conResult != 0)
    {
        (void) FreeConsole();
    }
}