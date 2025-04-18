#ifndef _BLOK_ARGS_H_
#define _BLOK_ARGS_H_

#include <Windows.h>

typedef struct _ArgsInfo {
    int theme;
    int scaleX;
    int scaleY;
    int showConsole;
} ArgsInfo;

void BlokArgsProcess(LPWSTR commandLine, ArgsInfo *result);

#endif // _BLOK_ARGS_H_