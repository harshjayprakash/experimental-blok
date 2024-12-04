#ifndef __BLOK_WINDOW_H
#define __BLOK_WINDOW_H

#define STRICT 1
#include <Windows.h>

typedef struct bkWindow
{
	HWND hWindow;
	WNDCLASSEXW klass;
} bkWindow;

void bkWindowInit(bkWindow* pWindow, HINSTANCE hInstance, int showFlag);

void bkWindowFree(bkWindow* pWindow, HINSTANCE hInstance);

#endif // !__BLOK_WINDOW_H
