#ifndef _BLOK_WINDOW_H_
#define _BLOK_WINDOW_H_

#include <windows.h>

typedef struct _Window {
    HWND hHandle;
    WNDCLASSEXW klass;
    LPWSTR klassName;
    LPWSTR caption;
    ATOM klassAtomIdx;
} Window;

int blokWindowInit(Window *pWindow, HINSTANCE hInstance);

int blokWindowShow(Window *pWindow, DWORD showFlag);

int blokWindowFree(Window *pWindow, HINSTANCE hInstance);

#endif /* _BLOK_WINDOW_H_ */