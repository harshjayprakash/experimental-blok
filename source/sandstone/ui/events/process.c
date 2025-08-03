#include "process.h"
#include "../../core/context.h"
#include "../../fmt/convert.h"
#include "action.h"
#include <strsafe.h>
#include <windowsx.h>

#define BLOK_MOUSE_AT(rect, pos)                                                         \
    (pos.x > rect.left && pos.x < rect.right && pos.y > rect.top && pos.y < rect.bottom)

void stProcessEventOnPaint(HWND hWindow)
{
    TGraphics *pGraphics = stContextGetGraphics();
    TViewport *pViewport = stContextGetViewport();
    TObjectState *pState = stContextGetObjectState();
    TVector2 scaling = pState->box.size;

    PAINTSTRUCT paintstruct;
    HDC hSurface = BeginPaint(hWindow, &paintstruct);
    HDC hOffSurface = CreateCompatibleDC(hSurface);
    HBITMAP hOffSurfaceBitmap = CreateCompatibleBitmap(hSurface, pViewport->region.right,
                                                       pViewport->region.bottom);
    HBITMAP hSurfaceBitmap = SelectObject(hOffSurface, hOffSurfaceBitmap);
    HFONT hOldFont = NULL;
    HBRUSH hOldBrush =
        (HBRUSH)SelectObject(hOffSurface, pGraphics->renderTools.brushes.hBaseBackground);
    HPEN hOldPen =
        (HPEN)SelectObject(hOffSurface, pGraphics->renderTools.pens.hBaseForeground);
    INT oldBkMode = SetBkMode(hOffSurface, TRANSPARENT);
    COLORREF oldBkColour = SetBkColor(hOffSurface, pGraphics->palette.baseBackground);
    COLORREF oldTextColour = SetTextColor(hOffSurface, pGraphics->palette.baseForeground);

    if (pViewport->hFont != NULL)
    {
        HFONT oldFont = (HFONT)SelectObject(hOffSurface, pViewport->hFont);
    }

    (void)FillRect(hOffSurface, &pViewport->region,
                   pGraphics->renderTools.brushes.hBaseBackground);

    (void)SelectObject(hOffSurface, pGraphics->renderTools.pens.hBaseBorderFaded);

    if (pViewport->isGridVisible)
    {
        for (long xAxisIdx = 0; xAxisIdx < pViewport->canvas.region.right;
             xAxisIdx += scaling.x)
        {
            (void)MoveToEx(hOffSurface, xAxisIdx, 0, NULL);
            (void)LineTo(hOffSurface, xAxisIdx, pViewport->canvas.region.bottom);
        }

        for (long yAxisIdx = 0; yAxisIdx < pViewport->canvas.region.bottom;
             yAxisIdx += scaling.y)
        {
            (void)MoveToEx(hOffSurface, 0, yAxisIdx, NULL);
            (void)LineTo(hOffSurface, pViewport->canvas.region.right, yAxisIdx);
        }
    }

    (void)SelectObject(hOffSurface, pGraphics->renderTools.pens.hBaseForeground);

    RECT box = stConvertRectFromVector2s(pState->box.position, pState->box.size);
    INT innerBoxSF = 3;
    RECT innerBox = {
        box.left + (scaling.x / innerBoxSF), box.top + (scaling.y / innerBoxSF),
        box.right - (scaling.x / innerBoxSF), box.bottom - (scaling.y / innerBoxSF)};
    (void)FillRect(hOffSurface, &box, pGraphics->renderTools.brushes.hPrimaryBackground);
    (void)FillRect(hOffSurface, &innerBox,
                   pGraphics->renderTools.brushes.hBaseBackground);

    for (long obstructIdx = 0; obstructIdx < pState->obstructs.size; obstructIdx++)
    {
        RECT obstructiveRc =
            stConvertRectFromVector2s(pState->obstructs.pArr[obstructIdx].data, scaling);
        (void)FillRect(hOffSurface, &obstructiveRc,
                       pGraphics->renderTools.brushes.hBaseBackgroundMedium);
    }

    if (pViewport->isInterfaceVisible)
    {
        (void)FillRect(hOffSurface, &pViewport->panel.region,
                       pGraphics->renderTools.brushes.hBaseBackgroundFaded);

        (void)DrawTextW(hOffSurface, pViewport->coordinatesText.data, -1,
                        &pViewport->coordinatesText.region,
                        DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);

        (void)SelectObject(hOffSurface, BLOK_MOUSE_AT(pViewport->clearAllButton.region,
                                                      pViewport->mousePos)
                                            ? pGraphics->renderTools.pens.hPrimaryBorder
                                            : pGraphics->renderTools.pens.hBaseBorder);
        (void)SelectObject(
            hOffSurface,
            BLOK_MOUSE_AT(pViewport->clearAllButton.region, pViewport->mousePos)
                ? pGraphics->renderTools.brushes.hPrimaryBackgroundFaded
                : pGraphics->renderTools.brushes.hBaseBackground);

        (void)Rectangle(hOffSurface, pViewport->clearAllButton.region.left,
                        pViewport->clearAllButton.region.top,
                        pViewport->clearAllButton.region.right,
                        pViewport->clearAllButton.region.bottom);
        (void)DrawTextW(hOffSurface, pViewport->clearAllButton.text, -1,
                        &pViewport->clearAllButton.region,
                        DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);

        (void)SelectObject(hOffSurface, BLOK_MOUSE_AT(pViewport->generateButton.region,
                                                      pViewport->mousePos)
                                            ? pGraphics->renderTools.pens.hPrimaryBorder
                                            : pGraphics->renderTools.pens.hBaseBorder);
        (void)SelectObject(
            hOffSurface,
            BLOK_MOUSE_AT(pViewport->generateButton.region, pViewport->mousePos)
                ? pGraphics->renderTools.brushes.hPrimaryBackgroundFaded
                : pGraphics->renderTools.brushes.hBaseBackground);

        (void)Rectangle(hOffSurface, pViewport->generateButton.region.left,
                        pViewport->generateButton.region.top,
                        pViewport->generateButton.region.right,
                        pViewport->generateButton.region.bottom);
        (void)DrawTextW(hOffSurface, pViewport->generateButton.text, -1,
                        &pViewport->generateButton.region,
                        DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);

        (void)SelectObject(hOffSurface, pGraphics->renderTools.pens.hBaseBorder);
        (void)SelectObject(hOffSurface, pGraphics->renderTools.brushes.hBaseBackground);

        (void)DrawTextW(hOffSurface, pViewport->obstructCountText.data, -1,
                        &pViewport->obstructCountText.region,
                        DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);

        (void)Rectangle(hOffSurface, pViewport->obstructMemoryBar.region.left,
                        pViewport->obstructMemoryBar.region.top,
                        pViewport->obstructMemoryBar.region.right,
                        pViewport->obstructMemoryBar.region.bottom);
        (void)FillRect(hOffSurface, &pViewport->obstructMemoryBar.barRegion,
                       pGraphics->renderTools.brushes.hPrimaryBackground);

        (void)SelectObject(hOffSurface, BLOK_MOUSE_AT(pViewport->lockedToggle.region,
                                                      pViewport->mousePos)
                                            ? pGraphics->renderTools.pens.hPrimaryBorder
                                            : pGraphics->renderTools.pens.hBaseBorder);
        (void)SelectObject(
            hOffSurface,
            BLOK_MOUSE_AT(pViewport->lockedToggle.region, pViewport->mousePos)
                ? pGraphics->renderTools.brushes.hPrimaryBackgroundFaded
                : pGraphics->renderTools.brushes.hBaseBackground);

        (void)Rectangle(hOffSurface, pViewport->lockedToggle.region.left,
                        pViewport->lockedToggle.region.top,
                        pViewport->lockedToggle.region.right,
                        pViewport->lockedToggle.region.bottom);

        (void)SelectObject(hOffSurface, pGraphics->renderTools.pens.hBaseBorder);
        (void)SelectObject(hOffSurface, pGraphics->renderTools.brushes.hBaseBackground);

        if (pViewport->lockedToggle.selected)
        {
            (void)FillRect(hOffSurface, &pViewport->lockedToggle.selectRegion,
                           pGraphics->renderTools.brushes.hPrimaryBackground);
        }

        (void)DrawTextW(hOffSurface, pViewport->lockedToggleText.data, -1,
                        &pViewport->lockedToggleText.region,
                        DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);
    }

    (void)BitBlt(hSurface, 0, 0, pViewport->region.right, pViewport->region.bottom,
                 hOffSurface, 0, 0, SRCCOPY);

    if (pViewport->hFont != NULL)
    {
        (void)SelectObject(hOffSurface, hOldFont);
    }

    (void)SetTextColor(hOffSurface, oldTextColour);
    (void)SetBkColor(hOffSurface, oldBkColour);
    (void)SetBkMode(hOffSurface, oldBkMode);
    (void)SelectObject(hOffSurface, hOldPen);
    (void)SelectObject(hOffSurface, hOldBrush);
    (void)SelectObject(hOffSurface, hSurfaceBitmap);
    (void)DeleteObject(hOffSurfaceBitmap);
    (void)DeleteDC(hOffSurface);
    (void)EndPaint(hWindow, &paintstruct);
}

void stProcessEventOnKeyDown(HWND hWindow, WPARAM virtualKey)
{
    TObjectState *pState = stContextGetObjectState();
    TViewport *pViewport = stContextGetViewport();
    TGraphics *pGraphics = stContextGetGraphics();

    switch (virtualKey)
    {
    case VK_UP:
    case 'W':
        (void)stActionMoveBox(pViewport, pState, hWindow, BLOK_DIRECTION_NORTH);
        break;

    case VK_LEFT:
    case 'A':
        (void)stActionMoveBox(pViewport, pState, hWindow, BLOK_DIRECTION_WEST);
        break;

    case VK_DOWN:
    case 'S':
        (void)stActionMoveBox(pViewport, pState, hWindow, BLOK_DIRECTION_SOUTH);
        break;

    case VK_RIGHT:
    case 'D':
        (void)stActionMoveBox(pViewport, pState, hWindow, BLOK_DIRECTION_EAST);
        break;

    case 'G':
        (void)stActionToggleGridLines(pViewport, hWindow);
        break;

    case 'O':
        (void)stActionAddObstruct(pViewport, pState, hWindow, NULL);
        break;

    case 'I':
        (void)stActionToggleInterface(pViewport, hWindow);
        break;

    case 'T':
        (void)stActionChangeTheme(pGraphics, hWindow);
        break;

    case 'C':
        (void)stActionClearObstructs(pViewport, pState, hWindow);
        break;

    case 'L':
        (void)stActionToggleCanvasLock(pViewport, hWindow);
        break;

    case 'M':
        (void)stActionGenerateRandomObstructs(pViewport, pState, hWindow);
        break;
    }
}

void stProcessEventOnLeftMouseDown(HWND hWindow, LPARAM mousepos)
{
    TObjectState *pState = stContextGetObjectState();
    TViewport *pViewport = stContextGetViewport();
    TVector2 span = pState->box.size;
    POINT mpos = {(GET_X_LPARAM(mousepos) / span.x) * span.x,
                  (GET_Y_LPARAM(mousepos) / span.y) * span.y};

    pViewport->isLeftMouseDown = TRUE;

    if (BLOK_MOUSE_AT(pViewport->panel.region, mpos) && pViewport->isInterfaceVisible)
    {
        if (BLOK_MOUSE_AT(pViewport->generateButton.region, mpos))
        {
            (void)stActionAddObstruct(pViewport, pState, hWindow, NULL);
        }

        if (BLOK_MOUSE_AT(pViewport->clearAllButton.region, mpos))
        {
            (void)stActionClearObstructs(pViewport, pState, hWindow);
        }

        if (BLOK_MOUSE_AT(pViewport->lockedToggle.region, mpos))
        {
            (void)stActionToggleCanvasLock(pViewport, hWindow);
        }

        (void)InvalidateRect(hWindow, &pViewport->panel.region, FALSE);
        return;
    }

    if (pViewport->isCanvasLocked)
    {
        return;
    }

    (void)stActionAddObstruct(pViewport, pState, hWindow, &mpos);
}

void stProcessEventOnLeftMouseUp(HWND hWindow, LPARAM mousepos)
{
    TObjectState *pState = stContextGetObjectState();
    TViewport *pViewport = stContextGetViewport();

    pViewport->isLeftMouseDown = FALSE;
}

void stProcessEventOnResize(HWND hWindow)
{
    TViewport *pViewport = stContextGetViewport();
    TObjectState *pState = stContextGetObjectState();

    (void)GetClientRect(hWindow, &pViewport->region);
    (void)stPanelUpdate(&pViewport->panel, &pViewport->region);
    (void)stCanvasUpdate(&pViewport->canvas, &pViewport->region);
    (void)stTextUpdate(
        &pViewport->coordinatesText,
        &(POINT){pViewport->panel.region.left + 10, pViewport->panel.region.top + 10});
    (void)stButtonUpdate(&pViewport->clearAllButton,
                         &(POINT){pViewport->coordinatesText.region.right + 10,
                                  pViewport->coordinatesText.region.top});
    (void)stButtonUpdate(&pViewport->generateButton,
                         &(POINT){pViewport->clearAllButton.region.right + 10,
                                  pViewport->clearAllButton.region.top});
    (void)stTextUpdate(&pViewport->obstructCountText,
                       &(POINT){pViewport->generateButton.region.right + 10,
                                pViewport->generateButton.region.top});
    (void)stProgressBarUpdate(&pViewport->obstructMemoryBar,
                              &(POINT){pViewport->obstructCountText.region.right + 10,
                                       pViewport->obstructCountText.region.top});
    (void)stProgressBarUpdateMinMax(&pViewport->obstructMemoryBar, 0,
                                    pState->obstructs.max);
    (void)stProgressBarUpdateValue(&pViewport->obstructMemoryBar, pState->obstructs.size);
    (void)stToggleUpdate(&pViewport->lockedToggle,
                         &(POINT){pViewport->obstructMemoryBar.region.right + 10,
                                  pViewport->obstructMemoryBar.region.top});
    (void)stTextUpdate(&pViewport->lockedToggleText,
                       &(POINT){pViewport->lockedToggle.region.right + 10,
                                pViewport->lockedToggle.region.top});
}

void stProcessEventOnMouseHover(HWND hWindow, LPARAM mousepos)
{
    TViewport *pViewport = stContextGetViewport();
    TObjectState *pState = stContextGetObjectState();

    pViewport->mousePos.x = GET_X_LPARAM(mousepos);
    pViewport->mousePos.y = GET_Y_LPARAM(mousepos);

    if (pViewport->isCanvasLocked)
    {
        (void)InvalidateRect(hWindow, NULL, FALSE);
        return;
    }

    if (BLOK_MOUSE_AT(pViewport->panel.region, pViewport->mousePos) &&
        pViewport->isInterfaceVisible)
    {
        (void)InvalidateRect(hWindow, NULL, FALSE);
        return;
    }

    if (pViewport->isLeftMouseDown)
    {
        (void)stActionAddObstruct(pViewport, pState, hWindow, &pViewport->mousePos);
    }

    if (pViewport->isRightMouseDown)
    {
        (void)stActionRemoveObstruct(pViewport, pState, hWindow, pViewport->mousePos);
    }

    (void)InvalidateRect(hWindow, NULL, FALSE);
}

void stProcessEventOnRightMouseDown(HWND hWindow, LPARAM mousepos)
{
    TObjectState *pState = stContextGetObjectState();
    TViewport *pViewport = stContextGetViewport();

    pViewport->isRightMouseDown = TRUE;

    if (pViewport->isCanvasLocked)
    {
        return;
    }

    (void)stActionRemoveObstruct(pViewport, pState, hWindow, pViewport->mousePos);
}

void stProcessEventOnRightMouseUp(HWND hWindow, LPARAM mousepos)
{
    TViewport *pViewport = stContextGetViewport();

    pViewport->isRightMouseDown = FALSE;
}