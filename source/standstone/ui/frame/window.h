#ifndef ST_WINDOW_H
#define ST_WINDOW_H

#include <windows.h>

typedef struct _Window
{
    HWND hHandle;
    WNDCLASSEXW klass;
    LPWSTR klassName;
    LPWSTR caption;
    ATOM klassAtomIdx;
} TWindow;

int stWindowInit(TWindow *pWindow, HINSTANCE hInstance);

int stWindowShow(TWindow *pWindow, DWORD showFlag);

int stWindowFree(TWindow *pWindow, HINSTANCE hInstance);

#endif /* ST_WINDOW_H */