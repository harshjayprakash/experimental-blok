/**
 * @file args.c
 * @brief Argument parsing implementation for command-line options.
 * @author harshjayprakash
 * @date 2025-07-19
 ****************************************************************************************/

#include "args.h"

#define ST_EVALUATE_SCALE(assignTo, value)                                               \
    int scale = abs(_wtoi(value));                                                       \
    assignTo = (scale != 0) ? scale : ST_ARGS_SCALE_DEFAULT

typedef enum _ArgMode
{
    ST_ARGM_UNSET = 0,
    ST_ARGM_SCALE_X = 10,
    ST_ARGM_SCALE_Y = 20,
    ST_ARGM_SCALE_A = 30
} TArgMode;

int stArgsProcess(
    TParsedArgs *pArgs, 
    LPCWSTR pCommandLine)
{
    if (pArgs == NULL || pCommandLine == NULL)
    {
        return 0;
    }

    ST_ARGS_SET_DEFAULT((*pArgs));

    int argc = 0;
    TArgMode argm = ST_ARGM_UNSET;
    LPWSTR *ppArgv = CommandLineToArgvW(pCommandLine, &argc);

    if (ppArgv == NULL)
    {
        return 0;
    }

    for (int idx = 0; idx < argc; ++idx)
    {
        if (_wcsnicmp(ppArgv[idx], L"--dark-theme", 13 * sizeof(unsigned short)) == 0)
        {
            pArgs->theme = 1;
        }

        if (_wcsnicmp(ppArgv[idx], L"--light-theme", 14 * sizeof(unsigned short)) == 0)
        {
            pArgs->theme = 2;
        }

        if (argm == ST_ARGM_SCALE_A || argm == ST_ARGM_SCALE_X)
        {
            ST_EVALUATE_SCALE(pArgs->scaleX, ppArgv[idx]);
        }
        if (argm == ST_ARGM_SCALE_A || argm == ST_ARGM_SCALE_Y)
        {
            ST_EVALUATE_SCALE(pArgs->scaleY, ppArgv[idx]);
        }

        argm = ST_ARGM_UNSET;

        if (_wcsnicmp(ppArgv[idx], L"--scale-x", 10 * sizeof(unsigned short)) == 0)
        {
            argm = ST_ARGM_SCALE_X;
        }

        if (_wcsnicmp(ppArgv[idx], L"--scale-y", 10 * sizeof(unsigned short)) == 0)
        {
            argm = ST_ARGM_SCALE_Y;
        }

        if (_wcsnicmp(ppArgv[idx], L"--scale", 8 * sizeof(unsigned short)) == 0)
        {
            argm = ST_ARGM_SCALE_A;
        }
    }

    (void)LocalFree((HLOCAL)ppArgv);
    ppArgv = NULL;

    return 1;
}