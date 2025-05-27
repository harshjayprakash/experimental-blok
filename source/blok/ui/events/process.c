/**
 * @file PROCESS.C
 * @date 27-05-2025
 * @brief Implementation of the event provessing routines.
 */

#include "process.h"
#include "../../context.h"
#include "../../fmt/convert.h"
#include "action.h"
#include <strsafe.h>
#include <windowsx.h>

#define BLOK_MOUSE_AT(rect, pos) \
    (pos.x > rect.left && pos.x < rect.right && pos.y > rect.top && pos.y < rect.bottom)

void blokProcessEventOnPaint(
    HWND hWindow)
{
    Graphics *pGraphics = blokContextGetGraphics();
    Viewport *pViewport = blokContextGetViewport();
    State *pState = blokContextGetState();
    VectorII scaling = pState->box.size;

    PAINTSTRUCT paintstruct;
    HDC hSurface = BeginPaint(hWindow, &paintstruct);
    HDC hOffSurface = CreateCompatibleDC(hSurface);
    HBITMAP hOffSurfaceBitmap = CreateCompatibleBitmap(
        hSurface, pViewport->region.right, pViewport->region.bottom);
    HBITMAP hSurfaceBitmap = SelectObject(hOffSurface, hOffSurfaceBitmap);
    HFONT hOldFont = NULL;
    HBRUSH hOldBrush = (HBRUSH)SelectObject(hOffSurface, pGraphics->tools.hSurfaceBrush);
    HPEN hOldPen = (HPEN)SelectObject(hOffSurface, pGraphics->tools.hOnSurfacePen);
    INT oldBkMode = SetBkMode(hOffSurface, TRANSPARENT);
    COLORREF oldBkColour = SetBkColor(hOffSurface, pGraphics->colours.surface);
    COLORREF oldTextColour = SetTextColor(hOffSurface, pGraphics->colours.onSurface);

    if (pViewport->hFont != NULL) {
        HFONT oldFont = (HFONT)SelectObject(hOffSurface, pViewport->hFont);
    }

    (void)FillRect(hOffSurface, &pViewport->region, pGraphics->tools.hSurfaceBrush);

    (void)SelectObject(hOffSurface, pGraphics->tools.hOnSurfaceVariantPen);

    if (pViewport->isGridVisible) {
        for (long xAxisIdx = 0; 
            xAxisIdx < pViewport->canvas.region.right; 
            xAxisIdx += scaling.x) {
            (void)MoveToEx(hOffSurface, xAxisIdx, 0, NULL);
            (void)LineTo(hOffSurface, xAxisIdx, pViewport->canvas.region.bottom);
        }

        for (long yAxisIdx = 0; 
            yAxisIdx < pViewport->canvas.region.bottom; 
            yAxisIdx += scaling.y) {
            (void)MoveToEx(hOffSurface, 0, yAxisIdx, NULL);
            (void)LineTo(hOffSurface, pViewport->canvas.region.right, yAxisIdx);
        }
    }

    RECT box = blokConvertVectorRect(pState->box.position, pState->box.size);
    INT innerBoxSF = 3;
    RECT innerBox = {
        box.left + (scaling.x / innerBoxSF),
        box.top + (scaling.y / innerBoxSF),
        box.right - (scaling.x / innerBoxSF),
        box.bottom - (scaling.y / innerBoxSF)
    };
    (void)FillRect(hOffSurface, &box, pGraphics->tools.hPrimaryBrush);
    (void)FillRect(hOffSurface, &innerBox, pGraphics->tools.hSurfaceBrush);

    for (long obstructIdx = 0; obstructIdx < pState->obstructs.size; obstructIdx++) {
        RECT obstructiveRc = blokConvertVectorRect(
            pState->obstructs.pArr[obstructIdx].data, scaling);
        (void)FillRect(hOffSurface, &obstructiveRc, pGraphics->tools.hSecondaryBrush);
    }

    if (pViewport->isInterfaceVisible) {
        (void)FillRect(
            hOffSurface, &pViewport->panel.region, pGraphics->tools.hSurfaceVariantBrush);
        
        (void)DrawTextW(
            hOffSurface, pViewport->coordinatesText.data, -1, 
            &pViewport->coordinatesText.region, 
            DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_TOP);

        (void)SelectObject(hOffSurface, 
            BLOK_MOUSE_AT(pViewport->clearAllButton.region, pViewport->mousePos)
            ? pGraphics->tools.hOnPrimaryVariantPen
            : pGraphics->tools.hOnSurfaceVariantPen);

        (void)Rectangle(
            hOffSurface, pViewport->clearAllButton.region.left, 
            pViewport->clearAllButton.region.top, pViewport->clearAllButton.region.right, 
            pViewport->clearAllButton.region.bottom);
        (void)DrawTextW(
            hOffSurface, pViewport->clearAllButton.text, -1, 
            &pViewport->clearAllButton.region, 
            DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);

        (void)SelectObject(hOffSurface, 
            BLOK_MOUSE_AT(pViewport->generateButton.region, pViewport->mousePos)
            ? pGraphics->tools.hOnPrimaryVariantPen
            : pGraphics->tools.hOnSurfaceVariantPen);

        (void)Rectangle(
            hOffSurface, pViewport->generateButton.region.left, 
            pViewport->generateButton.region.top, pViewport->generateButton.region.right, 
            pViewport->generateButton.region.bottom);
        (void)DrawTextW(
            hOffSurface, pViewport->generateButton.text, -1, 
            &pViewport->generateButton.region, 
            DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);

        (void)SelectObject(hOffSurface, pGraphics->tools.hOnSurfaceVariantPen);

        (void)DrawTextW(
            hOffSurface, pViewport->obstructCountText.data, -1, 
            &pViewport->obstructCountText.region, 
            DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);
        
        (void)Rectangle(
            hOffSurface, pViewport->obstructMemoryBar.region.left, 
            pViewport->obstructMemoryBar.region.top,
            pViewport->obstructMemoryBar.region.right, 
            pViewport->obstructMemoryBar.region.bottom);
        (void)FillRect(
            hOffSurface, &pViewport->obstructMemoryBar.barRegion, 
            pGraphics->tools.hSecondaryBrush);
        
        (void)SelectObject(hOffSurface, 
            BLOK_MOUSE_AT(pViewport->lockedToggle.region, pViewport->mousePos)
            ? pGraphics->tools.hOnPrimaryVariantPen
            : pGraphics->tools.hOnSurfaceVariantPen);
    
        (void)Rectangle(
            hOffSurface, pViewport->lockedToggle.region.left, 
            pViewport->lockedToggle.region.top, 
            pViewport->lockedToggle.region.right, 
            pViewport->lockedToggle.region.bottom);

        (void)SelectObject(hOffSurface, pGraphics->tools.hOnSurfaceVariantPen);

        if (pViewport->lockedToggle.selected) {
            (void)FillRect(
                hOffSurface, &pViewport->lockedToggle.selectRegion, 
                pGraphics->tools.hSecondaryBrush);
        }

        (void)DrawTextW(
            hOffSurface, pViewport->lockedToggleText.data, -1, 
            &pViewport->lockedToggleText.region, 
            DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);
    }

    (void)BitBlt(
        hSurface, 0, 0, pViewport->region.right, pViewport->region.bottom, 
        hOffSurface, 0, 0, SRCCOPY);
    
    if (pViewport->hFont != NULL) { 
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

void blokProcessEventOnKeyDown(
    HWND hWindow,
    WPARAM virtualKey)
{
    State *pState = blokContextGetState();
    Viewport *pViewport = blokContextGetViewport();
    Graphics *pGraphics = blokContextGetGraphics();

    switch (virtualKey) {
    case VK_UP:
    case 'W': 
        (void)blokActionMoveBox(pViewport, pState, hWindow, BLOK_DIRECTION_NORTH);
        break;
    
    case VK_LEFT:
    case 'A':
        (void)blokActionMoveBox(pViewport, pState, hWindow, BLOK_DIRECTION_WEST);
        break;
    
    case VK_DOWN:
    case 'S':
        (void)blokActionMoveBox(pViewport, pState, hWindow, BLOK_DIRECTION_SOUTH);
        break;
    
    case VK_RIGHT:
    case 'D':
        (void)blokActionMoveBox(pViewport, pState, hWindow, BLOK_DIRECTION_EAST);
        break;

    case 'G':
        (void)blokActionToggleGridLines(pViewport, hWindow);
        break;
    
    case 'O':
        (void)blokActionAddObstruct(pViewport, pState, hWindow, NULL);
        break;

    case 'I':
        (void)blokActionToggleInterface(pViewport, hWindow);
        break;
    
    case 'T':
        (void)blokActionChangeTheme(pGraphics, hWindow);
        break;
    
    case 'C':
        (void)blokActionClearObstructs(pViewport, pState, hWindow);
        break;
    
    case 'L':
        (void)blokActionToggleCanvasLock(pViewport, hWindow);
        break;
    }
}

void blokProcessEventOnLeftMouseDown(
    HWND hWindow,
    LPARAM mousepos)
{
    State *pState = blokContextGetState();
    Viewport *pViewport = blokContextGetViewport();
    VectorII span = pState->box.size;
    POINT mpos = {
        (GET_X_LPARAM(mousepos) / span.x) * span.x,
        (GET_Y_LPARAM(mousepos) / span.y) * span.y
    };
    
    pViewport->isLeftMouseDown = TRUE;

    if (BLOK_MOUSE_AT(pViewport->panel.region, mpos) && pViewport->isInterfaceVisible) {
        if (BLOK_MOUSE_AT(pViewport->generateButton.region, mpos)) {
            (void)blokActionAddObstruct(pViewport, pState, hWindow, NULL);
        }

        if (BLOK_MOUSE_AT(pViewport->clearAllButton.region, mpos)) {
            (void)blokActionClearObstructs(pViewport, pState, hWindow);
        }

        if (BLOK_MOUSE_AT(pViewport->lockedToggle.region, mpos)) {
            (void)blokActionToggleCanvasLock(pViewport, hWindow);
        }

        (void)InvalidateRect(hWindow, &pViewport->panel.region, FALSE);
        return;
    }

    if (pViewport->isCanvasLocked) {
        return;
    }

    (void)blokActionAddObstruct(pViewport, pState, hWindow, &mpos);
}

void blokProcessEventOnLeftMouseUp(
    HWND hWindow,
    LPARAM mousepos)
{
    State *pState = blokContextGetState();
    Viewport *pViewport = blokContextGetViewport();

    pViewport->isLeftMouseDown = FALSE;
}

void blokProcessEventOnResize(
    HWND hWindow)
{
    Viewport *pViewport = blokContextGetViewport();
    State *pState = blokContextGetState();

    (void)GetClientRect(hWindow, &pViewport->region);
    (void)blokPanelUpdate(&pViewport->panel, &pViewport->region);
    (void)blokCanvasUpdate(&pViewport->canvas, &pViewport->region);
    (void)blokTextUpdate(
        &pViewport->coordinatesText, 
        &(POINT){
            pViewport->panel.region.left + 10, 
            pViewport->panel.region.top + 10 });
    (void)blokButtonUpdate(
        &pViewport->clearAllButton, 
        &(POINT){
            pViewport->coordinatesText.region.right + 10, 
            pViewport->coordinatesText.region.top });
    (void)blokButtonUpdate(
        &pViewport->generateButton, 
        &(POINT){
            pViewport->clearAllButton.region.right + 10, 
            pViewport->clearAllButton.region.top });
    (void)blokTextUpdate(
        &pViewport->obstructCountText,
        &(POINT){
            pViewport->generateButton.region.right + 10, 
            pViewport->generateButton.region.top });
    (void)blokProgressBarUpdate(
        &pViewport->obstructMemoryBar, 
        &(POINT){
            pViewport->obstructCountText.region.right + 10, 
            pViewport->obstructCountText.region.top });
    (void)blokProgressBarUpdateMinMax(
        &pViewport->obstructMemoryBar, 0, pState->obstructs.max);
    (void)blokProgressBarUpdateValue(
        &pViewport->obstructMemoryBar, pState->obstructs.size);
    (void)blokToggleUpdate(
        &pViewport->lockedToggle,
        &(POINT){
            pViewport->obstructMemoryBar.region.right + 10,
            pViewport->obstructMemoryBar.region.top });
    (void)blokTextUpdate(
        &pViewport->lockedToggleText, 
        &(POINT){
            pViewport->lockedToggle.region.right + 10, 
            pViewport->lockedToggle.region.top });
}

void blokProcessEventOnMouseHover(
    HWND hWindow,
    LPARAM mousepos)
{
    Viewport *pViewport = blokContextGetViewport();
    State *pState = blokContextGetState();

    pViewport->mousePos.x = GET_X_LPARAM(mousepos);
    pViewport->mousePos.y = GET_Y_LPARAM(mousepos);

    if (pViewport->isCanvasLocked) {
        (void)InvalidateRect(hWindow, NULL, FALSE);
        return;
    }

    if (BLOK_MOUSE_AT(pViewport->panel.region, pViewport->mousePos) 
        && pViewport->isInterfaceVisible) {
        (void)InvalidateRect(hWindow, NULL, FALSE);
        return;
    }

    if (pViewport->isLeftMouseDown) {
        (void)blokActionAddObstruct(pViewport, pState, hWindow, &pViewport->mousePos);
    }

    if (pViewport->isRightMouseDown) {
        (void)blokActionRemoveObstruct(pViewport, pState, hWindow, pViewport->mousePos);
    }

    (void)InvalidateRect(hWindow, NULL, FALSE);
}

void blokProcessEventOnRightMouseDown(
    HWND hWindow,
    LPARAM mousepos)
{
    State *pState = blokContextGetState();
    Viewport *pViewport = blokContextGetViewport();

    pViewport->isRightMouseDown = TRUE;

    if (pViewport->isCanvasLocked) {
        return;
    }

    (void)blokActionRemoveObstruct(pViewport, pState, hWindow, pViewport->mousePos);
}

void blokProcessEventOnRightMouseUp(
    HWND hWindow,
    LPARAM mousepos)
{
    Viewport *pViewport = blokContextGetViewport();

    pViewport->isRightMouseDown = FALSE;
}