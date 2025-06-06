#include "args.h"
#include <strsafe.h>

#define BLOK_SCALE_DEF    15
#define BLOK_ARGM_UNSET   0
#define BLOK_ARGM_SCALE_X 10
#define BLOK_ARGM_SCALE_Y 20
#define BLOK_ARGM_SCALE_A 30

#define BLOK_EVALUATE_SCALE(assignTo, value)                                             \
    int scale = abs(_wtoi(value));                                                       \
    assignTo = (scale != 0) ? scale : BLOK_SCALE_DEF

int blokArgsProcess(
    TArgsResult *pArgs, 
    LPCWSTR pCommandLine)
{
    if (pCommandLine == NULL) {
        return 0;
    }
    
    if (pArgs == NULL) {
        return 0;
    }
    
    pArgs->theme = 0;
    pArgs->scaleX = BLOK_SCALE_DEF;
    pArgs->scaleY = BLOK_SCALE_DEF;
    pArgs->showConsole = 0;

    int argc = 0;
    int argm = BLOK_ARGM_UNSET;
    LPWSTR *ppArgv = CommandLineToArgvW(pCommandLine, &argc);

    if (ppArgv == NULL) {
        return 0;
    }

    for (int idx = 0; idx < argc; ++idx) {
        if (_wcsnicmp(ppArgv[idx], L"--dark-theme", 13*sizeof(unsigned short)) == 0) {
            pArgs->theme = 1;
        }

        if (_wcsnicmp(ppArgv[idx], L"--light-theme", 14*sizeof(unsigned short)) == 0) {
            pArgs->theme = 2;
        }

        if (_wcsnicmp(ppArgv[idx], L"--show-console", 15*sizeof(unsigned short)) == 0) {
            pArgs->showConsole = 1;
        }

        
        if (argm == BLOK_ARGM_SCALE_A || argm == BLOK_ARGM_SCALE_X) {
            BLOK_EVALUATE_SCALE(pArgs->scaleX, ppArgv[idx]);
        }
        if (argm == BLOK_ARGM_SCALE_A || argm == BLOK_ARGM_SCALE_Y) {
            BLOK_EVALUATE_SCALE(pArgs->scaleY, ppArgv[idx]);
        }

        argm = BLOK_ARGM_UNSET;


        if (_wcsnicmp(ppArgv[idx], L"--scale-x", 10*sizeof(unsigned short)) == 0) {
            argm = BLOK_ARGM_SCALE_X;
        }

        if (_wcsnicmp(ppArgv[idx], L"--scale-y", 10*sizeof(unsigned short)) == 0) {
            argm = BLOK_ARGM_SCALE_Y;
        }

        if (_wcsnicmp(ppArgv[idx], L"--scale", 8*sizeof(unsigned short)) == 0) {
            argm = BLOK_ARGM_SCALE_A;
        }
    }

    (void)LocalFree(ppArgv);

    return 1;
}