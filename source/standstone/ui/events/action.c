#include "../../fmt/convert.h"
#include "action.h"
#include <strsafe.h>

int stActionMoveBox(
    TViewport *pViewport,
    TObjectState *pState,
    HWND hWindow,
    TDirection direction)
{
    if (pViewport == NULL)
    {
        return 0;
    }

    if (pState == NULL)
    {
        return 0;
    }

    if (hWindow == NULL)
    {
        return 0;
    }

    int movable = stStateIsBoxMovable(pState, direction);
    if (!movable)
    {
        return 0;
    }

    int result = stStateMoveBox(pState, direction);

    (void)StringCbPrintfW(pViewport->coordinatesText.data, 60,
        L"(%d, %d)", pState->box.position.x, pState->box.position.y);
  
    RECT boxUpdateRgn = {
        pState->box.position.x - pState->box.size.x,
        pState->box.position.y - pState->box.size.y,
        pState->box.position.x + (pState->box.size.x * 2),
        pState->box.position.y + (pState->box.size.y * 2),
    };

    (void)InvalidateRect(hWindow, &boxUpdateRgn, FALSE);
    (void)InvalidateRect(hWindow, &pViewport->panel.region, FALSE);

    (void)wprintf(L"Move Box: Direction - %d, New Position (%d, %d)\n", direction,
        pState->box.position.x, pState->box.position.y);

    return result;
}

int stActionToggleGridLines(
    TViewport *pViewport,
    HWND hWindow)
{
    if (pViewport == NULL)
    {
        return 0;
    }

    if (hWindow == NULL)
    {
        return 0;
    }

    pViewport->isGridVisible = !pViewport->isGridVisible;

    (void)InvalidateRect(hWindow, &pViewport->canvas.region, FALSE);

    (void)wprintf(L"Toggle Gridlines: %ls\n",
        pViewport->isGridVisible ? L"Visible" : L"Invisible");

    return 1;
}

int stActionToggleInterface(
    TViewport *pViewport,
    HWND hWindow)
{
    if (pViewport == NULL)
    {
        return 0;
    }

    if (hWindow == NULL)
    {
        return 0;
    }

    pViewport->isInterfaceVisible = !pViewport->isInterfaceVisible;

    (void)InvalidateRect(hWindow, &pViewport->panel.region, FALSE);

    (void)wprintf(L"Toggle Interface: %ls\n",
        pViewport->isInterfaceVisible ? L"Visible" : L"Invisible");

    return 1;
}

int stActionToggleCanvasLock(
    TViewport *pViewport,
    HWND hWindow)
{
    if (pViewport == NULL)
    {
        return 0;
    }

    if (hWindow == NULL)
    {
        return 0;
    }

    pViewport->isCanvasLocked = !pViewport->isCanvasLocked;

    (void)stToggleUpdateSelected(&pViewport->lockedToggle, pViewport->isCanvasLocked);
    (void)InvalidateRect(hWindow, &pViewport->lockedToggle.region, FALSE);

    (void)wprintf(L"Toggle Canvas Lock: %ls\n",
        (pViewport->isCanvasLocked) ? L"Locked" : L"Unlocked");

    return 1;
}

int stActionChangeTheme(
    TGraphics *pGraphics,
    HWND hWindow)
{
    if (pGraphics == NULL)
    {
        return 0;
    }

    TTheme currrentTheme = pGraphics->currentTheme;
        
    (void)stGraphicsFree(pGraphics);
    (void)stGraphicsInit(pGraphics,
        (currrentTheme == 1 || currrentTheme == 0) ? ST_THEME_LIGHT : ST_THEME_DARK);

    (void)InvalidateRect(hWindow, NULL, FALSE);

    (void)wprintf(L"Re-initialising Graphics Context: Update Theme\n");

    return 1;
}

int stActionAddObstruct(
    TViewport *pViewport,
    TObjectState *pState,
    HWND hWindow,
    const POINT *pPoint)
{
    if (pViewport == NULL)
    {
        return 0;
    }

    if (pState == NULL)
    {
        return 0;
    }

    if (hWindow == NULL)
    {
        return 0;
    }

    TVector2 newNode = { 0, 0 };
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
    
    int result = stStateAddObstruct(pState, newNode);
    RECT updateRegion = stConvertRectFromVector2s(newNode, pState->box.size);

    (void)StringCbPrintfW(
        pViewport->obstructCountText.data, 60, L"%ld", pState->obstructs.size);

    (void)stProgressBarUpdateMinMax(
        &pViewport->obstructMemoryBar, 0, pState->obstructs.max);
    (void)stProgressBarUpdateValue(
        &pViewport->obstructMemoryBar, pState->obstructs.size);

    (void)InvalidateRect(hWindow, &updateRegion, FALSE);
    (void)InvalidateRect(hWindow, &pViewport->obstructCountText.region, FALSE);
    (void)InvalidateRect(hWindow, &pViewport->obstructMemoryBar.region, FALSE);

    (void)wprintf(L"Add Obstruct: ");

    if (result > -1)
    {
        (void)wprintf(L"New Node (%d, %d), Idx %d\n", newNode.x, newNode.y, result);
    }
    else
    {
        (void)wprintf(L"Exists - Skipping\n");
    }

    return (result > -1);
}

int stActionRemoveObstruct(
    TViewport *pViewport,
    TObjectState *pState,
    HWND hWindow,
    const POINT point)
{
    if (pViewport == NULL)
    {
        return 0;
    }

    if (pState == NULL)
    {
        return 0;
    }

    if (hWindow == NULL)
    {
        return 0;
    }

    TVector2 scale = pState->box.size;
    TVector2 rp = {
        (point.x / scale.x) * scale.x,
        (point.y / scale.y) * scale.y
    };

    int result = stStateRemoveObstruct(pState, rp);

    (void)StringCbPrintfW(
        pViewport->obstructCountText.data, 60, L"%ld", pState->obstructs.size);

    (void)stProgressBarUpdateMinMax(
        &pViewport->obstructMemoryBar, 0, pState->obstructs.max);
    (void)stProgressBarUpdateValue(
        &pViewport->obstructMemoryBar, pState->obstructs.size);

    (void)InvalidateRect(hWindow, &pViewport->obstructCountText.region, FALSE);
    (void)InvalidateRect(hWindow, &pViewport->obstructMemoryBar.region, FALSE);
    (void)InvalidateRect(hWindow, &pViewport->canvas.region, FALSE);

    (void)wprintf(L"Remove Obstruct: At Node (%d, %d) at IDX %d\n", rp.x, rp.y, result);

    return (result > -1);
}

int stActionClearObstructs(
    TViewport *pViewport,
    TObjectState *pState,
    HWND hWindow)
{
    if (pViewport == NULL)
    {
        return 0;
    }

    if (pState == NULL)
    {
        return 0;
    }

    if (hWindow == NULL)
    {
        return 0;
    }

    int result = stStateClearObstructs(pState);
    (void)stProgressBarUpdateValue(
        &pViewport->obstructMemoryBar, pState->obstructs.size);
    (void)StringCbPrintfW(
        pViewport->obstructCountText.data, 60, L"%ld", pState->obstructs.size);
    (void)InvalidateRect(hWindow, &pViewport->obstructCountText.region, FALSE);
    (void)InvalidateRect(hWindow, &pViewport->obstructMemoryBar.region, FALSE);
    (void)InvalidateRect(hWindow, &pViewport->canvas.region, FALSE);

    (void)wprintf(L"Clear Obstructs: %d\n", result);

    return result;
}

int stActionGenerateRandomObstructs(
    TViewport *pViewport,
    TObjectState *pState,
    HWND hWindow)
{
    if (pViewport == NULL || pState == NULL)
    {
        return 0;
    }

    (void)stActionClearObstructs(pViewport, pState, hWindow);

    TVector2 maxRgnObstructs = { 0, 0 };
    TVector2 scale = pState->box.size;
    TVector2 _d = stConvertSizeVector2FromRect(pViewport->canvas.region);

    maxRgnObstructs.x = _d.x / scale.x;
    maxRgnObstructs.y = _d.y / scale.y;

    long _nNodes = (
        (rand() % maxRgnObstructs.x) +
        (rand() % maxRgnObstructs.y)
    );

    int result = 0;
    
    for (int idx = 0; idx < _nNodes; idx++)
    {
        result = (stActionAddObstruct(pViewport, pState, hWindow, NULL) || result);
    }

    (void)wprintf(L"Generate Random Obstruct: %d New Nodes\n", _nNodes);

    return 1;
}