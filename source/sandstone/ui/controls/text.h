#ifndef ST_TEXT_H
#define ST_TEXT_H

#include <windows.h>

typedef struct _Text
{
    WCHAR data[60];
    RECT region;
    SIZE size;
    SIZE margin;
    POINT position;
} TText;

int stTextUpdateEx(TText *pText, const POINT *pPoint, const SIZE *pSize,
                   const SIZE *pMargin);

int stTextUpdate(TText *pText, const POINT *pPosition);

#endif /* ST_TEXT_H */