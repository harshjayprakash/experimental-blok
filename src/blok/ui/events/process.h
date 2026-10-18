#ifndef BLOK_PROCESS_H
#define BLOK_PROCESS_H

#include <windows.h>

void BlokProcessEventOnPaint(HWND hWindow);

void BlokProcessEventOnKeyDown(HWND hWindow, WPARAM virtualKey);

void BlokProcessEventOnLeftMouseDown(HWND hWindow, LPARAM mousepos);

void BlokProcessEventOnRightMouseDown(HWND hWindow, LPARAM mousepos);

void BlokProcessEventOnLeftMouseUp(HWND hWindow, LPARAM mousepos);

void BlokProcessEventOnRightMouseUp(HWND hWindow, LPARAM mousepos);

void BlokProcessEventOnResize(HWND hWindow);

void BlokProcessEventOnMouseHover(HWND hWindow, LPARAM mousepos);

#endif /* BLOK_PROCESS_H */