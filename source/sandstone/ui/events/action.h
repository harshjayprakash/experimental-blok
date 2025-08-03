#ifndef ST_ACTION_H
#define ST_ACTION_H

#include "../../core/context.h"
#include "../../model/direction.h"
#include <windows.h>
#include <windowsx.h>

int stActionMoveBox(TViewport *pViewport, TObjectState *pState, HWND hWindow,
                    TDirection direction);

int stActionToggleGridLines(TViewport *pViewport, HWND hWindow);

int stActionToggleInterface(TViewport *pViewport, HWND hWindow);

int stActionToggleCanvasLock(TViewport *pViewport, HWND hWindow);

int stActionChangeTheme(TGraphics *pGraphics, HWND hWindow);

int stActionAddObstruct(TViewport *pViewport, TObjectState *pState, HWND hWindow,
                        const POINT *pPoint);

int stActionRemoveObstruct(TViewport *pViewport, TObjectState *pState, HWND hWindow,
                           const POINT point);

int stActionClearObstructs(TViewport *pViewport, TObjectState *pState, HWND hWindow);

int stActionGenerateRandomObstructs(TViewport *pViewport, TObjectState *pState,
                                    HWND hWindow);

#endif /* ST_ACTION_H */