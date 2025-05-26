#ifndef _BLOK_TEXT_H_
#define _BLOK_TEXT_H_

#include <Windows.h>

typedef struct _Text {
    WCHAR data[60];
    RECT region;
    SIZE size;
    SIZE margin;
    POINT position;
} Text;

int blokTextUpdateEx(
    Text *pText, const POINT *pPoint, const SIZE *pSize, const SIZE *pMargin);

int blokTextUpdate(Text *pText, const POINT *pPosition);

#endif // _BLOK_TEXT_H_