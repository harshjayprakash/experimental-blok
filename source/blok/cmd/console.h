#ifndef _BLOK_CONSOLE_H_
#define _BLOK_CONSOLE_H_

#include <stdio.h>

typedef struct _ConsoleInfo {
    int isInitialised;
    int errorOnAlloc;
    FILE *pStandardOut;
} TConsoleInfo;

int blokConsoleInit(TConsoleInfo *pConhost);

int blokConsoleFree(TConsoleInfo *pConhost);

#endif /* _BLOK_CONSOLE_H_ */