#ifndef _BLOK_WINDOW_H_
#define _BLOK_WINDOW_H_

#include <Windows.h>

typedef struct _Window {
    HWND hHandle;
    WNDCLASSEXW klass;
    LPWSTR klassName;
    LPWSTR caption;
    ATOM klassAtomIdx;
} Window;

void blokWindowInit(Window *pWindow, HINSTANCE hInstance);

void blokWindowShow(Window *pWindow, DWORD showFlag);

void blokWindowFree(Window *pWindow, HINSTANCE hInstance);

#endif // _BLOK_WINDOW_H_