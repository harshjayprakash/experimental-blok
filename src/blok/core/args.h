#ifndef BLOK_ARGS_H
#define BLOK_ARGS_H

#include <windows.h>

typedef struct _ParsedArgs
{
    unsigned int theme;
    unsigned int scaleX;
    unsigned int scaleY;
} TParsedArgs;

#define BLOK_ARGS_SCALE_DEFAULT 15

#define BLOK_ARGS_SET_DEFAULT(tParsedArgs)                                               \
    (tParsedArgs).theme = 0;                                                             \
    (tParsedArgs).scaleX = BLOK_ARGS_SCALE_DEFAULT;                                      \
    (tParsedArgs).scaleY = BLOK_ARGS_SCALE_DEFAULT

int BlokArgsParse(TParsedArgs *pParsedArgs, LPCWSTR pCommandLine);

#endif /* BLOK_ARGS_H */