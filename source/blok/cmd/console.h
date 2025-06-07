#ifndef _BLOK_CONSOLE_H_
#define _BLOK_CONSOLE_H_

#include <stdio.h>

typedef struct _ConsoleInfo {
    int isInitialised;
    int errorOnAlloc;
    FILE *pStandardOut;
} TConsoleInfo;

int blokConsoleInit(TConsoleInfo *pConhost);
int blokConsoleInit(TConsoleInfo *pConsoleInfo);

int blokConsoleFree(TConsoleInfo *pConhost);
int blokConsoleFree(TConsoleInfo *pConsoleInfo);

#endif /* _BLOK_CONSOLE_H_ */