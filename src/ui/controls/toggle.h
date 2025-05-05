#ifndef _BLOK_TOGGLE_H_
#define _BLOK_TOGGLE_H_

#include <Windows.h>

typedef struct _Toggle {
    RECT region;
    POINT position;
    SIZE size;
    SIZE margin;
    RECT selectRegion;
    SIZE selectMargin;
    BOOL selected;
} Toggle;

void blokToggleUpdateEx(
    Toggle *pToggle, const POINT *pPosition, const SIZE *pSize, const SIZE *pMargin, 
    const SIZE *pSelectMargin);

void blokToggleUpdate(Toggle *pToggle, const POINT *pPosition);

void blokToggleUpdateSelected(Toggle *pToggle, const BOOL selected);

#endif // _BLOK_TOGGLE_H_