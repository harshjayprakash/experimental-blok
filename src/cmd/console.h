#ifndef _BLOK_CONSOLE_H_
#define _BLOK_CONSOLE_H_

#include <stdio.h>

typedef struct _Console {
    int initialised;
    int conResult;
    int fileResult;
    FILE *output;
} Console;

void blokConsoleInit(Console *con);

void blokConsoleFree(Console *con);

#endif // _BLOK_CONSOLE_H_