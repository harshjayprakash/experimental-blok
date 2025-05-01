#ifndef _BLOK_WINDOW_H_
#define _BLOK_WINDOW_H_

#include <Windows.h>

typedef struct _Window {
    HWND handle;
    WNDCLASSEXW klass;
    LPWSTR klassName;
    LPWSTR caption;
    ATOM klassAtomIdx;
} Window;

void blokWindowInit(Window *window, HINSTANCE instance);

void blokWindowShow(Window *window, DWORD showFlag);

void blokWindowFree(Window *window, HINSTANCE instance);

#endif // _BLOK_WINDOW_H_