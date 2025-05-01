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
    Toggle *toggle, const POINT *position, const SIZE *size, const SIZE *margin, 
    const SIZE *selectMargin);

void blokToggleUpdate(Toggle *toggle, const POINT *position);

void blokToggleUpdateSelected(Toggle *toggle, const BOOL selected);

#endif // _BLOK_TOGGLE_H_