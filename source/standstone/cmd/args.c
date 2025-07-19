/**
 * @file args.c
 * @brief Argument parsing implementation for command-line options.
 * @author harshjayprakash
 * @date 2025-07-19
 ****************************************************************************************/

#include "args.h"

/**
 * @defgroup Argument Parsing Macros.
 * @brief Utility macros used during parsing and scale evaluation.
 * @{
 */

#define ST_SCALE_DEF 15
#define ST_ARGM_UNSET 0
#define ST_ARGM_SCALE_X 10
#define ST_ARGM_SCALE_Y 20
#define ST_ARGM_SCALE_A 30

#define ST_EVALUATE_SCALE(assignTo, value)                                             \
    int scale = abs(_wtoi(value));                                                       \
    assignTo = (scale != 0) ? scale : ST_SCALE_DEF

/** @} */

int stArgsProcess(
    TArgsResult *pArgs, 
    LPCWSTR pCommandLine)
{
    if (pArgs == NULL || pCommandLine == NULL)
    {
        return 0;
    }

    pArgs->theme = 0;
    pArgs->scaleX = ST_SCALE_DEF;
    pArgs->scaleY = ST_SCALE_DEF;
    pArgs->showConsole = 0;

    int argc = 0;
    int argm = ST_ARGM_UNSET;
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

        if (_wcsnicmp(ppArgv[idx], L"--show-console", 15 * sizeof(unsigned short)) == 0)
        {
            pArgs->showConsole = 1;
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