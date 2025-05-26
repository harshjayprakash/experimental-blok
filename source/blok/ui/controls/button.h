#ifndef _BLOK_BUTTON_H_
#define _BLOK_BUTTON_H_

#include <Windows.h>

typedef struct _Button {
    WCHAR text[60];
    RECT region;
    SIZE size;
    SIZE margin;
    POINT position;
} Button;

int blokButtonUpdateEx(
    Button *pButton, const POINT *pPos, const SIZE *pSize, const SIZE *pMargin);

int blokButtonUpdate(Button *pButton, const POINT *pPos);

#endif // _BLOK_BUTTON_H_