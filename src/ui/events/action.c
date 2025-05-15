#include "../../utils/convert.h"
#include "action.h"
#include <strsafe.h>

int blokActionMoveBox(Viewport *pViewport, State *pState, HWND hWindow, Direction direction)
{
    if (pViewport == NULL)
        return 0;

    if (pState == NULL)
        return 0;

    if (hWindow == NULL)
        return 0;

    int movable = blokStateIsBoxMovable(pState, direction);
    if (!movable)
        return 0;

    int result = blokStateMoveBox(pState, direction);

    (void)StringCbPrintfW(pViewport->coordinatesText.data, 60,
        L"(%d, %d)", pState->box.position.x, pState->box.position.y);
  
    RECT boxUpdateRgn = {
        pState->box.position.x - pState->box.size.x,
        pState->box.position.y - pState->box.size.y,
        pState->box.position.x + (pState->box.size.x * 2),
        pState->box.position.y + (pState->box.size.y * 2),
    };

    (void)InvalidateRect(hWindow, &boxUpdateRgn, FALSE);
    (void)InvalidateRect(hWindow, &(pViewport->panel.region), FALSE);

    return result;
}

int blokActionToggleGridLines(Viewport *pViewport, HWND hWindow)
{
    if (pViewport == NULL)
        return 0;

    if (hWindow == NULL)
        return 0;

    pViewport->isGridVisible = !pViewport->isGridVisible;

    (void)InvalidateRect(hWindow, &(pViewport->canvas.region), FALSE);

    return 1;
}

int blokActionToggleInterface(Viewport *pViewport, HWND hWindow)
{
    if (pViewport == NULL)
        return 0;

    if (hWindow == NULL)
        return 0;

    pViewport->isInterfaceVisible = !pViewport->isInterfaceVisible;

    (void)InvalidateRect(hWindow, &(pViewport->panel.region), FALSE);

    return 1;
}

int blokActionToggleCanvasLock(Viewport *pViewport, HWND hWindow)
{
    if (pViewport == NULL)
        return 0;

    if (hWindow == NULL)
        return 0;

    pViewport->isCanvasLocked = !pViewport->isCanvasLocked;

    (void)blokToggleUpdateSelected(&(pViewport->lockedToggle), pViewport->isCanvasLocked);
    (void)InvalidateRect(hWindow, &(pViewport->lockedToggle.region), FALSE);

    return 1;
}

int blokActionChangeTheme(Graphics *pGraphics, HWND hWindow)
{
    if (pGraphics == NULL)
        return 0;

    Theme currrentTheme = pGraphics->theme;
        
    (void)blokGraphicsFree(pGraphics);
    (void)blokGraphicsInit(pGraphics,
        (currrentTheme == 1 || currrentTheme == 0) ? BLOK_THEME_LIGHT : BLOK_THEME_DARK);

    wprintf(L"THEME: %d", pGraphics->theme);

    (void)InvalidateRect(hWindow, NULL, FALSE);

    return 1;
}

int blokActionAddObstruct(Viewport *pViewport, State *pState, HWND hWindow, const POINT *pPoint)
{
    if (pViewport == NULL)
        return 0;

    if (pState == NULL)
        return 0;

    if (hWindow == NULL)
        return 0;

    VectorII newNode = {0, 0};
    VectorII scale = pState->box.size;

    if (pPoint == NULL)
    {
        newNode.x = ((rand() % pViewport->canvas.size.cx) / scale.x) * scale.x;
        newNode.y = ((rand() % pViewport->canvas.size.cy) / scale.y) * scale.y;
    }
    else
    {
        newNode.x = ((pPoint->x) / scale.x) * scale.x;
        newNode.y = ((pPoint->y) / scale.y) * scale.y;
    }
    
    int result = blokStateAddObstruct(pState, newNode);
    RECT updateRegion = blokConvertVectorRect(newNode, pState->box.size);

    (void)StringCbPrintfW(
        pViewport->obstructCountText.data, 60, L"%ld", pState->obstructives.size);

    (void)blokProgressBarUpdateMinMax(
        &pViewport->obstructMemoryBar, 0, pState->obstructives.max);
    (void)blokProgressBarUpdateValue(
        &pViewport->obstructMemoryBar, pState->obstructives.size);

    (void)InvalidateRect(hWindow, &updateRegion, FALSE);
    (void)InvalidateRect(hWindow, &pViewport->obstructCountText.region, FALSE);
    (void)InvalidateRect(hWindow, &pViewport->obstructMemoryBar.region, FALSE);

    return (result > -1);
}

int blokActionRemoveObstruct(Viewport *pViewport, State *pState, HWND hWindow, const POINT point)
{
    if (pViewport == NULL)
        return 0;

    if (pState == NULL)
        return 0;

    if (hWindow == NULL)
        return 0;

    VectorII scale = pState->box.size;
    VectorII rp = {
        ((point.x) / scale.x) * scale.x,
        ((point.y) / scale.y) * scale.y
    };

    int result = blokStateRemoveObstruct(pState, rp);

    (void)StringCbPrintfW(
        pViewport->obstructCountText.data, 60, L"%ld", pState->obstructives.size);

    (void)blokProgressBarUpdateMinMax(
        &pViewport->obstructMemoryBar, 0, pState->obstructives.max);
    (void)blokProgressBarUpdateValue(
        &pViewport->obstructMemoryBar, pState->obstructives.size);

    (void)InvalidateRect(hWindow, &pViewport->obstructCountText.region, FALSE);
    (void)InvalidateRect(hWindow, &pViewport->obstructMemoryBar.region, FALSE);
    (void)InvalidateRect(hWindow, &pViewport->canvas.region, FALSE);

    return (result > -1);
}

int blokActionClearObstructs(Viewport *pViewport, State *pState, HWND hWindow)
{
    if (pViewport == NULL)
        return 0;

    if (pState == NULL)
        return 0;

    if (hWindow == NULL)
        return 0;

    int result = blokStateClearObstructs(pState);
    (void)blokProgressBarUpdateValue(
        &pViewport->obstructMemoryBar, pState->obstructives.size);
    (void)StringCbPrintfW(
        pViewport->obstructCountText.data, 60, L"%ld", pState->obstructives.size);
    (void)InvalidateRect(hWindow, &pViewport->obstructCountText.region, FALSE);
    (void)InvalidateRect(hWindow, &pViewport->obstructMemoryBar.region, FALSE);
    (void)InvalidateRect(hWindow, &pViewport->canvas.region, FALSE);

    return result;
}