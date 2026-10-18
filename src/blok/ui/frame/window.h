#ifndef BLOK_WINDOW_H
#define BLOK_WINDOW_H

#include <windows.h>

typedef struct _Window
{
    HWND hHandle;
    WNDCLASSEXW klass;
    LPWSTR klassName;
    LPWSTR caption;
    ATOM klassAtomIdx;
} TWindow;

int BlokWindowInit(TWindow *pWindow, HINSTANCE hInstance);

int BlokWindowShow(TWindow *pWindow, DWORD showFlag);

int BlokWindowFree(TWindow *pWindow, HINSTANCE hInstance);

#endif /* BLOK_WINDOW_H */