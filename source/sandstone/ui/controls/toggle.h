/**
 * @file   toggle.h
 * @brief  Toggle Button Declarations
 * @author harshjayprakash
 * @date   2025-08-04
 ****************************************************************************************/

#ifndef ST_TOGGLE_H
#define ST_TOGGLE_H

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

int stToggleUpdateEx(TToggle *pToggle, const POINT *pPosition, const SIZE *pSize,
                     const SIZE *pMargin, const SIZE *pSelectMargin);

int stToggleUpdate(TToggle *pToggle, const POINT *pPosition);

int stToggleUpdateSelected(TToggle *pToggle, const BOOL selected);

#endif /* ST_TOGGLE_H */