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

void BlokTextUpdateEx(
    Text *text, const POINT *point, const SIZE *size, const SIZE *margin);

void BlokTextUpdate(Text *text, const POINT *position);

#endif // _BLOK_TEXT_H_