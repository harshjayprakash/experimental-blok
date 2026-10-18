#ifndef BLOK_TEXT_H
#define BLOK_TEXT_H

#include <windows.h>

#define BLOK_TEXT_SIZE 60

typedef struct _Text
{
    WCHAR data[BLOK_TEXT_SIZE];
    RECT region;
    SIZE size;
    SIZE margin;
    POINT position;
} TText;

int BlokTextUpdateEx(TText *pText, const POINT *pPoint, const SIZE *pSize,
                   const SIZE *pMargin);

int BlokTextUpdate(TText *pText, const POINT *pPosition);

#endif /* BLOK_TEXT_H */