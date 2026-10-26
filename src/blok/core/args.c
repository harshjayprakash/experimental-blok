#include "args.h"

#define _BLOK_VALIDATE_SCALING(assignTo, value)                                          \
    int scale = abs(_wtoi(value));                                                       \
    assignTo = (scale != 0) ? scale : BLOK_ARGS_SCALE_DEFAULT

typedef enum _ArgMode
{
    BLOK_ARGM_UNSET = 0,
    BLOK_ARGM_SCALE_X = 10,
    BLOK_ARGM_SCALE_Y = 20,
    BLOK_ARGM_SCALE_A = 30,
} TArgMode;

int BlokArgsParse(TParsedArgs *pParsedArgs, LPCWSTR pCommandLine)
{
    if (pParsedArgs == NULL || pCommandLine == NULL)
    {
        return 0;
    }

    BLOK_ARGS_SET_DEFAULT(*pParsedArgs);

    int argc = 0;
    TArgMode argm = BLOK_ARGM_UNSET;
    LPWSTR *ppArgv = CommandLineToArgvW(pCommandLine, &argc);

    if (ppArgv == NULL)
    {
        return 0;
    }

    for (int idx = 0; idx < argc; ++idx)
    {
        if (_wcsnicmp(ppArgv[idx], L"--dark-theme", 13 * sizeof(unsigned short)) == 0)
        {
            pParsedArgs->theme = 1;
        }

        if (_wcsnicmp(ppArgv[idx], L"--light-theme", 14 * sizeof(unsigned short)) == 0)
        {
            pParsedArgs->theme = 2;
        }

        if (argm == BLOK_ARGM_SCALE_A || argm == BLOK_ARGM_SCALE_X)
        {
            _BLOK_VALIDATE_SCALING(pParsedArgs->scaleX, ppArgv[idx]);
        }
        if (argm == BLOK_ARGM_SCALE_A || argm == BLOK_ARGM_SCALE_Y)
        {
            _BLOK_VALIDATE_SCALING(pParsedArgs->scaleY, ppArgv[idx]);
        }

        argm = BLOK_ARGM_UNSET;

        if (_wcsnicmp(ppArgv[idx], L"--scale-x", 10 * sizeof(unsigned short)) == 0)
        {
            argm = BLOK_ARGM_SCALE_X;
        }

        if (_wcsnicmp(ppArgv[idx], L"--scale-y", 10 * sizeof(unsigned short)) == 0)
        {
            argm = BLOK_ARGM_SCALE_Y;
        }

        if (_wcsnicmp(ppArgv[idx], L"--scale", 8 * sizeof(unsigned short)) == 0)
        {
            argm = BLOK_ARGM_SCALE_A;
        }
    }

    (void)LocalFree((HLOCAL)ppArgv);
    ppArgv = NULL;

    return 1;
}