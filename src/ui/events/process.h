#ifndef _BLOK_PROCESS_H_
#define _BLOK_PROCESS_H_

#include <Windows.h>

void BlokProcessEventOnPaint(HWND window);

void BlokProcessEventOnKeyDown(HWND window, WPARAM virtualKey);

void BlokProcessEventOnLeftMouseDown(HWND window, LPARAM mousepos);

void BlokProcessEventOnLeftMouseUp(HWND window, LPARAM mousepos);

void BlokProcessEventOnResize(HWND window);

void BlokProcessEventOnMouseHover(HWND window, LPARAM mousepos);

#endif // _BLOK_PROCESS_H_