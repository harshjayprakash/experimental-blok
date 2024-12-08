#ifndef __BLOK_BUTTON_H
#define __BLOK_BUTTON_H

#include <Windows.h>

typedef struct bkButtonControl
{
	WCHAR text[MAX_PATH];
	SIZE_T max;
	COORD alignment;
	RECT region;
} bkButtonControl;

#endif // !__BLOK_BUTTON_H
