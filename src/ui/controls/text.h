#ifndef _BLOK_TEXT_H_
#define _BLOK_TEXT_H_

#include <Windows.h>

#define _BLOK_TEXT_SIZE 60

typedef struct _Text {
    WCHAR data[_BLOK_TEXT_SIZE];
    RECT region;
    SIZE size;
    SIZE margin;
    POINT position;
} Text;

void blokTextUpdateEx(
    Text *pText, const POINT *pPoint, const SIZE *pSize, const SIZE *pMargin);

void blokTextUpdate(Text *pText, const POINT *pPosition);

#endif // _BLOK_TEXT_H_