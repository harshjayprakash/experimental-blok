#include "args.h"
#include <strsafe.h>

#define __BLOK_ARGS_MODE_UNSET 0x0
#define __BLOK_ARGS_MODE_CUSTOM_SCALE_X 0x10
#define __BLOK_ARGS_MODE_CUSTOM_SCALE_Y 0x20
#define __BLOK_ARGS_MODE_CUSTOM_SCALE_A 0x30
#define __BLOK_DEFAULT_SCALE 15

void blokArgsProcess(LPWSTR pCommandLine, ArgsInfo *pArgs)
{
    if (!pCommandLine) { return; }
    if (!pArgs) { return; }

    pArgs->theme = 0;
    pArgs->scaleX = __BLOK_DEFAULT_SCALE;
    pArgs->scaleY = __BLOK_DEFAULT_SCALE;
    pArgs->showConsole = 0;

    int argc = 0;
    LPWSTR *ppArgv = CommandLineToArgvW(pCommandLine, &argc);

    if (!ppArgv) { return; }

    int mode = 0;

    for (int argIdx = 0; argIdx < argc; ++argIdx)
    {
        if (_wcsnicmp(ppArgv[argIdx], L"--dark-theme", 13*sizeof(unsigned short)) == 0)
        {
            pArgs->theme = 1;
        }
        if (_wcsnicmp(ppArgv[argIdx], L"--light-theme", 14*sizeof(unsigned short)) == 0)
        {
            pArgs->theme = 2;
        }
        if (_wcsnicmp(ppArgv[argIdx], L"--show-console", 15*sizeof(unsigned short)) == 0)
        {
            pArgs->showConsole = 1;
        }

        if (mode == __BLOK_ARGS_MODE_CUSTOM_SCALE_X)
        {
            int val = _wtoi(ppArgv[argIdx]);
            pArgs->scaleX = (val != 0) ? val : __BLOK_DEFAULT_SCALE;
            mode = __BLOK_ARGS_MODE_UNSET;
        }
        if (mode == __BLOK_ARGS_MODE_CUSTOM_SCALE_Y)
        {
            int val = _wtoi(ppArgv[argIdx]);
            pArgs->scaleY = (val != 0) ? val : __BLOK_DEFAULT_SCALE;
            mode = __BLOK_ARGS_MODE_UNSET;
        }
        if (mode == __BLOK_ARGS_MODE_CUSTOM_SCALE_A)
        {
            int val = _wtoi(ppArgv[argIdx]);
            pArgs->scaleY = pArgs->scaleX = (val != 0) ? val : __BLOK_DEFAULT_SCALE;
            mode = __BLOK_ARGS_MODE_UNSET;
        }

        if (_wcsnicmp(ppArgv[argIdx], L"--scale-x", 10*sizeof(unsigned short)) == 0)
        {
            mode = __BLOK_ARGS_MODE_CUSTOM_SCALE_X;
        }
        if (_wcsnicmp(ppArgv[argIdx], L"--scale-y", 10*sizeof(unsigned short)) == 0)
        {
            mode = __BLOK_ARGS_MODE_CUSTOM_SCALE_Y;
        }
        if (_wcsnicmp(ppArgv[argIdx], L"--scale", 8*sizeof(unsigned short)) == 0)
        {
            mode = __BLOK_ARGS_MODE_CUSTOM_SCALE_A;
        }
    }

    (void) LocalFree(ppArgv);
}