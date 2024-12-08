#ifndef __BLOK_TOGGLEBUTTON_H
#define __BLOK_TOGGLEBUTTON_H

#define STRICT 1
#include <Windows.h>

typedef struct bkToggleButtonControl
{
	WCHAR text[MAX_PATH];
	SIZE_T max;
	COORD textPosition;
	RECT wholeArea;
	RECT buttonArea;
	RECT selectedArea;
	int selected;
} bkToggleButtonControl;

#endif // !__BLOK_TOGGLEBUTTON_H
