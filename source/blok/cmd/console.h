#ifndef _BLOK_CONSOLE_H_
#define _BLOK_CONSOLE_H_

#include <stdio.h>

typedef struct _Console {
    int isInitialised;
    int errorOnAlloc;
    FILE *pStandardOut;
} Console;

int blokConsoleInit(Console *pConhost);

int blokConsoleFree(Console *pConhost);

#endif /* _BLOK_CONSOLE_H_ */