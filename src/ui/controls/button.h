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

void BlokButtonUpdateEx(
    Button *button, const POINT *pos, const SIZE *size, const SIZE *margin);

void BlokButtonUpdate(Button *button, const POINT *position);

#endif // _BLOK_BUTTON_H_