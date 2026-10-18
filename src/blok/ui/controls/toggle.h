#ifndef BLOK_TOGGLE_H
#define BLOK_TOGGLE_H

#include <windows.h>

typedef struct _Toggle
{
    RECT region;
    POINT position;
    SIZE size;
    SIZE margin;
    RECT selectRegion;
    SIZE selectMargin;
    BOOL selected;
} TToggle;

int BlokToggleUpdateEx(TToggle *pToggle, const POINT *pPosition, const SIZE *pSize,
                     const SIZE *pMargin, const SIZE *pSelectMargin);

int BlokToggleUpdate(TToggle *pToggle, const POINT *pPosition);

int BlokToggleUpdateSelected(TToggle *pToggle, const BOOL selected);

#endif /* BLOK_TOGGLE_H */