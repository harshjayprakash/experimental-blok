#ifndef _BLOK_ARGS_H_
#define _BLOK_ARGS_H_

#include <windows.h>

typedef struct _ArgsResult {
    unsigned int theme;
    unsigned int scaleX;
    unsigned int scaleY;
    unsigned int showConsole;
} TArgsResult;

int blokArgsProcess(TArgsResult *pArgs, LPCWSTR pCommandLine);

#endif /* _BLOK_ARGS_H_ */