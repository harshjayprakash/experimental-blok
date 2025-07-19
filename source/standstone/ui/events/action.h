#ifndef _BLOK_ACTION_H_
#define _BLOK_ACTION_H_

#include "../../model/direction.h"
#include "../../context.h"
#include <windows.h>
#include <windowsx.h>

int blokActionMoveBox(
    TViewport *pViewport, TObjectState *pState, HWND hWindow, TDirection direction);

int blokActionToggleGridLines(TViewport *pViewport, HWND hWindow);

int blokActionToggleInterface(TViewport *pViewport, HWND hWindow);

int blokActionToggleCanvasLock(TViewport *pViewport, HWND hWindow);

int blokActionChangeTheme(TGraphics *pGraphics, HWND hWindow);

int blokActionAddObstruct(
    TViewport *pViewport, TObjectState *pState, HWND hWindow, const POINT *pPoint);

int blokActionRemoveObstruct(
    TViewport *pViewport, TObjectState *pState, HWND hWindow, const POINT point);

int blokActionClearObstructs(TViewport *pViewport, TObjectState *pState, HWND hWindow);

int blokActionGenerateRandomObstructs(
    TViewport *pViewport, TObjectState *pState, HWND hWindow);

#endif /* _BLOK_ACTION_H_ */