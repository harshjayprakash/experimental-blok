#ifndef _BLOK_ARGS_H_
#define _BLOK_ARGS_H_

#include <windows.h>

typedef struct _ArgsResult {
    int theme;
    int scaleX;
    int scaleY;
    int showConsole;
} TArgsResult;

int blokArgsProcess(TArgsResult *pArgs, LPCWSTR pCommandLine);

#endif /* _BLOK_ARGS_H_ */