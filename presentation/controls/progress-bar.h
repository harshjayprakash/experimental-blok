#ifndef __BLOK_PROGRESSBAR_H
#define __BLOK_PROGRESSBAR_H

#include <Windows.h>

typedef struct bkProgressBarControl
{
	WCHAR text[MAX_PATH];
	SIZE_T maxTextSize;
	COORD textPosition;
	RECT barOutline;
	RECT bar;
	RECT region;
	int barMin;
	int barMax;
	int barSpan;
} bkProgressBarControl;

#endif // !__BLOK_PROGRESSBAR_H
