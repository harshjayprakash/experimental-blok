#ifndef _BLOK_CONSOLE_H_
#define _BLOK_CONSOLE_H_

#include <stdio.h>

typedef struct _Console {
    int initialised;
    int conResult;
    int fileResult;
    FILE *pOutput;
} Console;

void blokConsoleInit(Console *pConhost);

void blokConsoleFree(Console *pConhost);

#endif // _BLOK_CONSOLE_H_