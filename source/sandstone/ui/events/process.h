#ifndef ST_PROCESS_H
#define ST_PROCESS_H

#include <windows.h>

void stProcessEventOnPaint(HWND hWindow);

void stProcessEventOnKeyDown(HWND hWindow, WPARAM virtualKey);

void stProcessEventOnLeftMouseDown(HWND hWindow, LPARAM mousepos);

void stProcessEventOnRightMouseDown(HWND hWindow, LPARAM mousepos);

void stProcessEventOnLeftMouseUp(HWND hWindow, LPARAM mousepos);

void stProcessEventOnRightMouseUp(HWND hWindow, LPARAM mousepos);

void stProcessEventOnResize(HWND hWindow);

void stProcessEventOnMouseHover(HWND hWindow, LPARAM mousepos);

#endif /* ST_PROCESS_H */