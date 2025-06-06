#ifndef _BLOK_PROCESS_H_
#define _BLOK_PROCESS_H_

#include <windows.h>

void blokProcessEventOnPaint(HWND hWindow);

void blokProcessEventOnKeyDown(HWND hWindow, WPARAM virtualKey);

void blokProcessEventOnLeftMouseDown(HWND hWindow, LPARAM mousepos);

void blokProcessEventOnRightMouseDown(HWND hWindow, LPARAM mousepos);

void blokProcessEventOnLeftMouseUp(HWND hWindow, LPARAM mousepos);

void blokProcessEventOnRightMouseUp(HWND hWindow, LPARAM mousepos);

void blokProcessEventOnResize(HWND hWindow);

void blokProcessEventOnMouseHover(HWND hWindow, LPARAM mousepos);

#endif /* _BLOK_PROCESS_H_ */