/**
 * @file   button.h
 * @brief  Button Declarations
 * @author harshjayprakash
 * @date   2025-08-04
 ****************************************************************************************/

#ifndef ST_BUTTON_H
#define ST_BUTTON_H

#include <windows.h>

#define ST_BUTTON_TEXT_SIZE 60

typedef struct _Button
{
    WCHAR text[ST_BUTTON_TEXT_SIZE];
    RECT region;
    SIZE size;
    SIZE margin;
    POINT position;
} TButton;

int stButtonUpdateEx(TButton *pButton, const POINT *pPos, const SIZE *pSize,
                     const SIZE *pMargin);

int stButtonUpdate(TButton *pButton, const POINT *pPos);

#endif /* ST_BUTTON_H */