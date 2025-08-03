#include "action.h"
#include "../../fmt/convert.h"
#include <strsafe.h>

int stActionMoveBox(TViewport *pViewport, TObjectState *pState, HWND hWindow,
                    TDirection direction)
{
    if (pViewport == NULL || pState == NULL || hWindow == NULL)
    {
        return 0;
    }

    if (!stStateIsBoxMovable(pState, direction))
    {
        return 0;
    }

    int ok = stStateMoveBox(pState, direction);
    int thr = SUCCEEDED(StringCbPrintfW(pViewport->coordinatesText.data, 60, L"(%d, %d)",
                                        pState->box.position.x, pState->box.position.y));
    ok = ok && thr;

    RECT boxUpdateRgn = {
        pState->box.position.x - pState->box.size.x,
        pState->box.position.y - pState->box.size.y,
        pState->box.position.x + (pState->box.size.x * 2),
        pState->box.position.y + (pState->box.size.y * 2),
    };

    (void)InvalidateRect(hWindow, &boxUpdateRgn, FALSE);
    (void)InvalidateRect(hWindow, &pViewport->panel.region, FALSE);

    return ok;
}

int stActionToggleGridLines(TViewport *pViewport, HWND hWindow)
{
    if (pViewport == NULL || hWindow == NULL)
    {
        return 0;
    }

    pViewport->isGridVisible = !pViewport->isGridVisible;

    (void)InvalidateRect(hWindow, &pViewport->canvas.region, FALSE);

    return 1;
}

int stActionToggleInterface(TViewport *pViewport, HWND hWindow)
{
    if (pViewport == NULL || hWindow == NULL)
    {
        return 0;
    }

    pViewport->isInterfaceVisible = !pViewport->isInterfaceVisible;

    (void)InvalidateRect(hWindow, &pViewport->panel.region, FALSE);

    return 1;
}

int stActionToggleCanvasLock(TViewport *pViewport, HWND hWindow)
{
    if (pViewport == NULL || hWindow == NULL)
    {
        return 0;
    }

    pViewport->isCanvasLocked = !pViewport->isCanvasLocked;

    int result =
        stToggleUpdateSelected(&pViewport->lockedToggle, pViewport->isCanvasLocked);

    (void)InvalidateRect(hWindow, &pViewport->lockedToggle.region, FALSE);

    return result;
}

int stActionChangeTheme(TGraphics *pGraphics, HWND hWindow)
{
    if (pGraphics == NULL)
    {
        return 0;
    }

    int result = stGraphicsSwitchTheme(pGraphics);

    (void)InvalidateRect(hWindow, NULL, FALSE);

    return result;
}

int stActionAddObstruct(TViewport *pViewport, TObjectState *pState, HWND hWindow,
                        const POINT *pPoint)
{
    if (pViewport == NULL || pState == NULL || hWindow == NULL)
    {
        return 0;
    }

    TVector2 newNode = {0, 0};
    TVector2 scale = pState->box.size;

    if (pPoint == NULL)
    {
        newNode.x = ((rand() % pViewport->canvas.size.cx) / scale.x) * scale.x;
        newNode.y = ((rand() % pViewport->canvas.size.cy) / scale.y) * scale.y;
    }
    else
    {
        newNode.x = (pPoint->x / scale.x) * scale.x;
        newNode.y = (pPoint->y / scale.y) * scale.y;
    }

    int idx = stStateAddObstruct(pState, newNode);
    RECT updateRegion = stConvertRectFromVector2s(newNode, scale);

    int thr = SUCCEEDED(StringCbPrintfW(pViewport->obstructCountText.data, 60, L"%ld",
                                        pState->obstructs.size));

    int uc = stProgressBarUpdateValueEx(&pViewport->obstructMemoryBar, 0,
                                        pState->obstructs.max, pState->obstructs.size);

    (void)InvalidateRect(hWindow, &updateRegion, FALSE);
    (void)InvalidateRect(hWindow, &pViewport->obstructCountText.region, FALSE);
    (void)InvalidateRect(hWindow, &pViewport->obstructMemoryBar.region, FALSE);

    return (idx > -1) && thr && uc;
}

int stActionRemoveObstruct(TViewport *pViewport, TObjectState *pState, HWND hWindow,
                           const POINT point)
{
    if (pViewport == NULL || pState == NULL || hWindow == NULL)
    {
        return 0;
    }

    TVector2 scale = pState->box.size;
    TVector2 rp = {(point.x / scale.x) * scale.x, (point.y / scale.y) * scale.y};

    int idx = stStateRemoveObstruct(pState, rp);

    int thr = SUCCEEDED(StringCbPrintfW(pViewport->obstructCountText.data, 60, L"%ld",
                                        pState->obstructs.size));

    int uc = stProgressBarUpdateValueEx(&pViewport->obstructMemoryBar, 0,
                                        pState->obstructs.max, pState->obstructs.size);

    (void)InvalidateRect(hWindow, &pViewport->obstructCountText.region, FALSE);
    (void)InvalidateRect(hWindow, &pViewport->obstructMemoryBar.region, FALSE);
    (void)InvalidateRect(hWindow, &pViewport->canvas.region, FALSE);

    return (idx > -1) && thr && uc;
}

int stActionClearObstructs(TViewport *pViewport, TObjectState *pState, HWND hWindow)
{
    if (pViewport == NULL || pState == NULL || hWindow == NULL)
    {
        return 0;
    }

    int ok = stStateClearObstructs(pState);

    if (!ok)
    {
        return 0;
    }

    ok = stProgressBarUpdateValue(&pViewport->obstructMemoryBar, pState->obstructs.size);

    if (!ok)
    {
        return 0;
    }

    (void)StringCbPrintfW(pViewport->obstructCountText.data, 60, L"%ld",
                          pState->obstructs.size);

    (void)InvalidateRect(hWindow, &pViewport->obstructCountText.region, FALSE);
    (void)InvalidateRect(hWindow, &pViewport->obstructMemoryBar.region, FALSE);
    (void)InvalidateRect(hWindow, &pViewport->canvas.region, FALSE);

    return ok;
}

int stActionGenerateRandomObstructs(TViewport *pViewport, TObjectState *pState,
                                    HWND hWindow)
{
    if (pViewport == NULL || pState == NULL)
    {
        return 0;
    }

    int ok = stActionClearObstructs(pViewport, pState, hWindow);
    TVector2 scale = pState->box.size;
    TVector2 bounds = stConvertSizeVector2FromRect(pViewport->canvas.region);

    for (long yIdx = 0; yIdx < bounds.y; yIdx += scale.y)
    {
        for (long xIdx = 0; xIdx < bounds.x; xIdx += scale.x)
        {
            POINT pt = {xIdx, yIdx};
            int shouldCreate = rand() % 50;

            if (shouldCreate <= 10)
            {
                int result = stActionAddObstruct(pViewport, pState, hWindow, &pt);
                ok = (ok && result);
            }
        }
    }

    return ok;
}