/**
 * @file args.c
 * @brief Argument Parsing Implementation.
 * @author harshjayprakash
 * @date 2025-07-20
 ****************************************************************************************/

#include "args.h"

/**
 * @defgroup stArgsEvaluateScale Argument Scaling Validation
 * @{
 */

#define ST_EVALUATE_SCALE(assignTo, value)                                               \
    int scale = abs(_wtoi(value));                                                       \
    assignTo = (scale != 0) ? scale : ST_ARGS_SCALE_DEFAULT

/** @} */

/**
 * @brief Argument Parsing Mode.
 * 
 * @details
 *  Used as a series of flags for the argument parser, when looking for values to store.
 */
typedef enum _ArgMode
{
    /**
     * @brief Unset.
     */
    ST_ARGM_UNSET = 0,

    /**
     * @brief X Scaling Parsing Mode.
     */
    ST_ARGM_SCALE_X = 10,

    /**
     * @brief Y Scaling Parsing Mode.
     */
    ST_ARGM_SCALE_Y = 20,

    /**
     * @brief X and Y Scaling Parsing Mode.
     */
    ST_ARGM_SCALE_A = 30
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
            ST_EVALUATE_SCALE(pParsedArgs->scaleX, ppArgv[idx]);
        }
        if (argm == ST_ARGM_SCALE_A || argm == ST_ARGM_SCALE_Y)
        {
            ST_EVALUATE_SCALE(pParsedArgs->scaleY, ppArgv[idx]);
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