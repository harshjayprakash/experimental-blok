#ifndef BLOK_ACTION_H
#define BLOK_ACTION_H

#include "../../core/context.h"
#include "../../model/direction.h"
#include <windows.h>
#include <windowsx.h>

int BlokActionMoveBox(TViewport *pViewport, TObjectState *pState, HWND hWindow,
                    TDirection direction);

int BlokActionToggleGridLines(TViewport *pViewport, HWND hWindow);

int BlokActionToggleInterface(TViewport *pViewport, HWND hWindow);

int BlokActionToggleCanvasLock(TViewport *pViewport, HWND hWindow);

int BlokActionChangeTheme(TGraphics *pGraphics, HWND hWindow);

int BlokActionAddObstruct(TViewport *pViewport, TObjectState *pState, HWND hWindow,
                        const POINT *pPoint);

int BlokActionRemoveObstruct(TViewport *pViewport, TObjectState *pState, HWND hWindow,
                           const POINT point);

int BlokActionClearObstructs(TViewport *pViewport, TObjectState *pState, HWND hWindow);

int BlokActionGenerateRandomObstructs(TViewport *pViewport, TObjectState *pState,
                                    HWND hWindow);

#endif /* BLOK_ACTION_H */