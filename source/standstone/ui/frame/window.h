#ifndef _BLOK_WINDOW_H_
#define _BLOK_WINDOW_H_

#include <windows.h>

typedef struct _Window
{
    HWND hHandle;
    WNDCLASSEXW klass;
    LPWSTR klassName;
    LPWSTR caption;
    ATOM klassAtomIdx;
} TWindow;

int blokWindowInit(TWindow *pWindow, HINSTANCE hInstance);

int blokWindowShow(TWindow *pWindow, DWORD showFlag);

int blokWindowFree(TWindow *pWindow, HINSTANCE hInstance);

#endif /* _BLOK_WINDOW_H_ */