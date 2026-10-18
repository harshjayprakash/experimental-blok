#ifndef ST_BUTTON_H
#define ST_BUTTON_H

#include <windows.h>

#define BLOK_BUTTON_TEXT_SIZE 60

typedef struct _Button
{
    WCHAR text[BLOK_BUTTON_TEXT_SIZE];
    RECT region;
    SIZE size;
    SIZE margin;
    POINT position;
} TButton;

int BlokButtonUpdateEx(TButton *pButton, const POINT *pPos, const SIZE *pSize,
                     const SIZE *pMargin);

int BlokButtonUpdate(TButton *pButton, const POINT *pPos);

#endif /* ST_BUTTON_H */