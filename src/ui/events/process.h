#ifndef _BLOK_PROCESS_H_
#define _BLOK_PROCESS_H_

#include <Windows.h>

void blokProcessEventOnPaint(HWND window);

void blokProcessEventOnKeyDown(HWND window, WPARAM virtualKey);

void blokProcessEventOnLeftMouseDown(HWND window, LPARAM mousepos);

void blokProcessEventOnRightMouseDown(HWND window, LPARAM mousepos);

void blokProcessEventOnLeftMouseUp(HWND window, LPARAM mousepos);

void blokProcessEventOnRightMouseUp(HWND window, LPARAM mousepos);

void blokProcessEventOnResize(HWND window);

void blokProcessEventOnMouseHover(HWND window, LPARAM mousepos);

#endif // _BLOK_PROCESS_H_