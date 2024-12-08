#ifndef __BLOK_TEXT_H
#define __BLOK_TEXT_H

#define STRICT 1
#include <Windows.h>

typedef struct bkTextControl
{
	WCHAR text[MAX_PATH];
	SIZE_T max;
	COORD position;
	RECT area;
} bkTextControl;

#endif // !__BLOK_TEXT_H
