#ifndef _BLOK_ACTION_H_
#define _BLOK_ACTION_H_

#include "../../model/direction.h"
#include "../../context.h"
#include <windows.h>
#include <windowsx.h>

int blokActionMoveBox(
    Viewport *pViewport, State *pState, HWND hWindow, Direction direction);

int blokActionToggleGridLines(Viewport *pViewport, HWND hWindow);

int blokActionToggleInterface(Viewport *pViewport, HWND hWindow);

int blokActionToggleCanvasLock(Viewport *pViewport, HWND hWindow);

int blokActionChangeTheme(Graphics *pGraphics, HWND hWindow);

int blokActionAddObstruct(
    Viewport *pViewport, State *pState, HWND hWindow, const POINT *pPoint);

int blokActionRemoveObstruct(
    Viewport *pViewport, State *pState, HWND hWindow, const POINT point);

int blokActionClearObstructs(Viewport *pViewport, State *pState, HWND hWindow);

#endif // _BLOK_ACTION_H_