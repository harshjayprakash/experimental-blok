/**
 * @file   args.c
 * @brief  Argument parser implementation.
 * @author harshjayprakash
 * @date   2025-07-30
 ****************************************************************************************/

#include "args.h"

#define _ST_VALIDATE_SCALING(assignTo, value)                                            \
    int scale = abs(_wtoi(value));                                                       \
    assignTo = (scale != 0) ? scale : ST_ARGS_SCALE_DEFAULT

/**
 * @brief Modes used during argument parsing.
 *
 * @details
 * This enumeration represents flags that guide the argument parser in extracting values
 * based on the previous contextual argument.
 */
typedef enum _ArgMode
{
    ST_ARGM_UNSET   =  0, /**< No parsing mode set. */
    ST_ARGM_SCALE_X = 10, /**< Parse horizontal (x-axis) scaling value only. */
    ST_ARGM_SCALE_Y = 20, /**< Parse vertical (y-axis) scaling value only. */
    ST_ARGM_SCALE_A = 30, /**< Parse both horizontal and vertical scaling values. */
} TArgMode;

int stArgsParse(
    TParsedArgs *pParsedArgs, 
    LPCWSTR pCommandLine)
{
    if (pParsedArgs == NULL || pCommandLine == NULL)
    {
        return 0;
    }

    ST_ARGS_SET_DEFAULT((*pParsedArgs));

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
            pParsedArgs->theme = 1;
        }

        if (_wcsnicmp(ppArgv[idx], L"--light-theme", 14 * sizeof(unsigned short)) == 0)
        {
            pParsedArgs->theme = 2;
        }

        if (argm == ST_ARGM_SCALE_A || argm == ST_ARGM_SCALE_X)
        {
            _ST_VALIDATE_SCALING(pParsedArgs->scaleX, ppArgv[idx]);
        }
        if (argm == ST_ARGM_SCALE_A || argm == ST_ARGM_SCALE_Y)
        {
            _ST_VALIDATE_SCALING(pParsedArgs->scaleY, ppArgv[idx]);
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