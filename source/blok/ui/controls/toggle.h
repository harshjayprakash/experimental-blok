#ifndef _BLOK_TOGGLE_H_
#define _BLOK_TOGGLE_H_

#include <windows.h>

typedef struct _Toggle {
    RECT region;
    POINT position;
    SIZE size;
    SIZE margin;
    RECT selectRegion;
    SIZE selectMargin;
    BOOL selected;
} TToggle;

int blokToggleUpdateEx(
    TToggle *pToggle, const POINT *pPosition, const SIZE *pSize, const SIZE *pMargin, 
    const SIZE *pSelectMargin);

int blokToggleUpdate(TToggle *pToggle, const POINT *pPosition);

int blokToggleUpdateSelected(TToggle *pToggle, const BOOL selected);

#endif /* _BLOK_TOGGLE_H_ */