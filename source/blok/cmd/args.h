#ifndef _BLOK_ARGS_H_
#define _BLOK_ARGS_H_

#include <windows.h>

typedef struct _ArgsInfo {
    int theme;
    int scaleX;
    int scaleY;
    int showConsole;
} ArgsInfo;

int blokArgsProcess(ArgsInfo *pArgs, LPCWSTR pCommandLine);

#endif // _BLOK_ARGS_H_