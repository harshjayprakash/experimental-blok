#include "args.h"
#include <strsafe.h>

#define __BLOK_ARGS_MODE_UNSET 0x0
#define __BLOK_ARGS_MODE_CUSTOM_SCALE_X 0x10
#define __BLOK_ARGS_MODE_CUSTOM_SCALE_Y 0x20
#define __BLOK_ARGS_MODE_CUSTOM_SCALE_A 0x30
#define __BLOK_DEFAULT_SCALE 15

void BlokArgsProcess(LPWSTR commandLine, ArgsInfo *result)
{
    if (!commandLine) { return; }
    if (!result) { return; }

    result->theme = 0;
    result->scaleX = __BLOK_DEFAULT_SCALE;
    result->scaleY = __BLOK_DEFAULT_SCALE;
    result->showConsole = 0;

    int argc = 0;
    LPWSTR *args = CommandLineToArgvW(commandLine, &argc);

    if (!args) { return; }

    int mode = 0;

    for (int argIdx = 0; argIdx < argc; ++argIdx)
    {
        if (_wcsnicmp(args[argIdx], L"--dark-theme", 13*sizeof(unsigned short)) == 0)
        {
            result->theme = 1;
        }
        if (_wcsnicmp(args[argIdx], L"--light-theme", 14*sizeof(unsigned short)) == 0)
        {
            result->theme = 2;
        }
        if (_wcsnicmp(args[argIdx], L"--show-console", 15*sizeof(unsigned short)) == 0)
        {
            result->showConsole = 1;
        }

        if (mode == __BLOK_ARGS_MODE_CUSTOM_SCALE_X)
        {
            int val = _wtoi(args[argIdx]);
            result->scaleX = (val != 0) ? val : __BLOK_DEFAULT_SCALE;
            mode = __BLOK_ARGS_MODE_UNSET;
        }
        if (mode == __BLOK_ARGS_MODE_CUSTOM_SCALE_Y)
        {
            int val = _wtoi(args[argIdx]);
            result->scaleY = (val != 0) ? val : __BLOK_DEFAULT_SCALE;
            mode = __BLOK_ARGS_MODE_UNSET;
        }
        if (mode == __BLOK_ARGS_MODE_CUSTOM_SCALE_A)
        {
            int val = _wtoi(args[argIdx]);
            result->scaleY = result->scaleX = (val != 0) ? val : __BLOK_DEFAULT_SCALE;
            mode = __BLOK_ARGS_MODE_UNSET;
        }

        if (_wcsnicmp(args[argIdx], L"--scale-x", 10*sizeof(unsigned short)) == 0)
        {
            mode = __BLOK_ARGS_MODE_CUSTOM_SCALE_X;
        }
        if (_wcsnicmp(args[argIdx], L"--scale-y", 10*sizeof(unsigned short)) == 0)
        {
            mode = __BLOK_ARGS_MODE_CUSTOM_SCALE_Y;
        }
        if (_wcsnicmp(args[argIdx], L"--scale", 8*sizeof(unsigned short)) == 0)
        {
            mode = __BLOK_ARGS_MODE_CUSTOM_SCALE_A;
        }
    }

    (void) LocalFree(args);
}