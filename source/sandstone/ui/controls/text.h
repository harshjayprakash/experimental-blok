/**
 * @file   text.h
 * @brief  Text Declarations
 * @author harshjayprakash
 * @date   2025-08-04
 ****************************************************************************************/

#ifndef ST_TEXT_H
#define ST_TEXT_H

#include <windows.h>

#define ST_TEXT_SIZE 60

typedef struct _Text
{
    WCHAR data[ST_TEXT_SIZE];
    RECT region;
    SIZE size;
    SIZE margin;
    POINT position;
} TText;

int stTextUpdateEx(TText *pText, const POINT *pPoint, const SIZE *pSize,
                   const SIZE *pMargin);

int stTextUpdate(TText *pText, const POINT *pPosition);

#endif /* ST_TEXT_H */