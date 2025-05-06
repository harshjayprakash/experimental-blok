#include "process.h"
#include "../../base/context.h"
#include "../../utils/convert.h"
#include <strsafe.h>
#include <Windowsx.h>

#define BLOK_MOUSE_AT(rect, pos) \
    (pos.X > rect.left && pos.X < rect.right && pos.Y > rect.top && pos.Y < rect.bottom)

void blokProcessEventOnPaint(HWND hWindow)
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
    HBRUSH hOldBrush = (HBRUSH) SelectObject(hOffSurface, pGraphics->tools.hSurfaceBrush);
    HPEN hOldPen = (HPEN) SelectObject(hOffSurface, pGraphics->tools.hOnSurfacePen);
    INT oldBkMode = SetBkMode(hOffSurface, TRANSPARENT);
    COLORREF oldBkColour = SetBkColor(hOffSurface, pGraphics->colours.surface);
    COLORREF oldTextColour = SetTextColor(hOffSurface, pGraphics->colours.onSurface);

    if (pViewport->hFont != NULL)
    {
        HFONT oldFont = (HFONT) SelectObject(hOffSurface, pViewport->hFont);
    }

    (void) FillRect(hOffSurface, &pViewport->region, pGraphics->tools.hSurfaceBrush);

    (void) SelectObject(hOffSurface, pGraphics->tools.hOnSurfaceVariantPen);

    if (pViewport->isGridVisible)
    {
        for (long xAxisIdx = 0; 
            xAxisIdx < pViewport->canvas.region.right; 
            xAxisIdx += scaling.x)
        {
            (void) MoveToEx(hOffSurface, xAxisIdx, 0, NULL);
            (void) LineTo(hOffSurface, xAxisIdx, pViewport->canvas.region.bottom);
        }

        for (long yAxisIdx = 0; 
            yAxisIdx < pViewport->canvas.region.bottom; 
            yAxisIdx += scaling.y)
        {
            (void) MoveToEx(hOffSurface, 0, yAxisIdx, NULL);
            (void) LineTo(hOffSurface, pViewport->canvas.region.right, yAxisIdx);
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
    (void) FillRect(hOffSurface, &box, pGraphics->tools.hPrimaryBrush);
    (void) FillRect(hOffSurface, &innerBox, pGraphics->tools.hSurfaceBrush);

    for (long obstructIdx = 0; obstructIdx < pState->obstructives.size; obstructIdx++)
    {
        RECT obstructiveRc = blokConvertVectorRect(
            pState->obstructives.pArr[obstructIdx].data, scaling);
        (void) FillRect(hOffSurface, &obstructiveRc, pGraphics->tools.hSecondaryBrush);
    }

    if (pViewport->isInterfaceVisible)
    {
        (void) FillRect(
            hOffSurface, &pViewport->panel.region, pGraphics->tools.hSurfaceVariantBrush);
        
        (void) DrawTextW(
            hOffSurface, pViewport->coordinatesText.data, -1, 
            &pViewport->coordinatesText.region, 
            DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_TOP);

        (void) SelectObject(hOffSurface, 
            BLOK_MOUSE_AT(pViewport->clearAllButton.region, pViewport->mousePos) ?
            pGraphics->tools.hOnPrimaryVariantPen : pGraphics->tools.hOnSurfaceVariantPen);

        (void) Rectangle(
            hOffSurface, pViewport->clearAllButton.region.left, 
            pViewport->clearAllButton.region.top, pViewport->clearAllButton.region.right, 
            pViewport->clearAllButton.region.bottom);
        (void) DrawTextW(
            hOffSurface, pViewport->clearAllButton.text, -1, 
            &pViewport->clearAllButton.region, 
            DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);

        (void) SelectObject(hOffSurface, 
            BLOK_MOUSE_AT(pViewport->generateButton.region, pViewport->mousePos) ?
            pGraphics->tools.hOnPrimaryVariantPen : pGraphics->tools.hOnSurfaceVariantPen);

        (void) Rectangle(
            hOffSurface, pViewport->generateButton.region.left, 
            pViewport->generateButton.region.top, pViewport->generateButton.region.right, 
            pViewport->generateButton.region.bottom);
        (void) DrawTextW(
            hOffSurface, pViewport->generateButton.text, -1, 
            &pViewport->generateButton.region, 
            DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);

        (void) SelectObject(hOffSurface, pGraphics->tools.hOnSurfaceVariantPen);

        (void) DrawTextW(
            hOffSurface, pViewport->obstructCountText.data, -1, 
            &pViewport->obstructCountText.region, 
            DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);
        
        (void) Rectangle(
            hOffSurface, pViewport->obstructMemoryBar.region.left, 
            pViewport->obstructMemoryBar.region.top, 
            pViewport->obstructMemoryBar.region.right, 
            pViewport->obstructMemoryBar.region.bottom);
        (void) FillRect(
            hOffSurface, &pViewport->obstructMemoryBar.barRegion, 
            pGraphics->tools.hSecondaryBrush);
        
        (void) SelectObject(hOffSurface, 
            BLOK_MOUSE_AT(pViewport->lockedToggle.region, pViewport->mousePos) ?
            pGraphics->tools.hOnPrimaryVariantPen : pGraphics->tools.hOnSurfaceVariantPen);
    
        (void) Rectangle(
            hOffSurface, pViewport->lockedToggle.region.left, 
            pViewport->lockedToggle.region.top, 
            pViewport->lockedToggle.region.right, 
            pViewport->lockedToggle.region.bottom);

        (void) SelectObject(hOffSurface, pGraphics->tools.hOnSurfaceVariantPen);

        if (pViewport->lockedToggle.selected)
        {
            (void) FillRect(
                hOffSurface, &pViewport->lockedToggle.selectRegion, 
                pGraphics->tools.hSecondaryBrush);
        }

        (void) DrawTextW(
            hOffSurface, pViewport->lockedToggleText.data, -1, 
            &pViewport->lockedToggleText.region, 
            DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);
    }

    (void) BitBlt(
        hSurface, 0, 0, pViewport->region.right, pViewport->region.bottom, 
        hOffSurface, 0, 0, SRCCOPY);
    
    if (pViewport->hFont != NULL) 
    { 
        (void) SelectObject(hOffSurface, hOldFont); 
    }

    (void) SetTextColor(hOffSurface, oldTextColour);
    (void) SetBkColor(hOffSurface, oldBkColour);
    (void) SetBkMode(hOffSurface, oldBkMode);
    (void) SelectObject(hOffSurface, hOldPen);
    (void) SelectObject(hOffSurface, hOldBrush);
    (void) SelectObject(hOffSurface, hSurfaceBitmap);
    (void) DeleteObject(hOffSurfaceBitmap);
    (void) DeleteDC(hOffSurface);
    (void) EndPaint(hWindow, &paintstruct);
}

void blokProcessEventOnKeyDown(HWND hWindow, WPARAM virtualKey)
{
    State *pState = blokContextGetState();
    Viewport *pViewport = blokContextGetViewport();
    Direction moveBoxOperation = 0;
    int changeGridVisibility = 0;
    int changeInterfaceVisibility = 0;
    int generateObstructive = 0;
    int changeTheme = 0;
    int clearObstructs = 0;
    int toggleLock = 0;

    switch (virtualKey)
    {
    case VK_UP:
    case 'W': 
        moveBoxOperation = BLOK_DIRECTION_NORTH; 
        break;
    
    case VK_LEFT:
    case 'A':
        moveBoxOperation = BLOK_DIRECTION_WEST;
        break;
    
    case VK_DOWN:
    case 'S':
        moveBoxOperation = BLOK_DIRECTION_SOUTH;
        break;
    
    case VK_RIGHT:
    case 'D':
        moveBoxOperation = BLOK_DIRECTION_EAST;
        break;

    case 'G':
        changeGridVisibility = 1;
        break;
    
    case 'O':
        generateObstructive = 1;
        break;

    case 'I':
        changeInterfaceVisibility = 1;
        break;
    
    case 'T':
        changeTheme = 1;
        break;
    
    case 'C':
        clearObstructs = 1;
        break;
    
    case 'L':
        toggleLock = 1;
        break;
    }

    if (moveBoxOperation)
    {
        if (blokStateBoxMovableInDirection(pState, moveBoxOperation))
        {
            blokStateMoveBox(&pState->box, moveBoxOperation);
        }

        (void) StringCbPrintfW(
            pViewport->coordinatesText.data, 60,
            L"(%d, %d)", pState->box.position.x, pState->box.position.y);
        
        RECT boxUpdateRegion = {
            pState->box.position.x - pState->box.size.x,
            pState->box.position.y - pState->box.size.x,
            pState->box.position.x + (pState->box.size.x * 2),
            pState->box.position.y + (pState->box.size.y * 2),
        };
        (void) InvalidateRect(hWindow, &boxUpdateRegion, FALSE);
        (void) InvalidateRect(hWindow, &pViewport->panel.region, FALSE);
    }

    if (changeGridVisibility)
    {
        pViewport->isGridVisible = !pViewport->isGridVisible;
        (void) InvalidateRect(hWindow, &pViewport->canvas.region, FALSE);
    }

    if (changeInterfaceVisibility)
    {
        pViewport->isInterfaceVisible = !pViewport->isInterfaceVisible;
        (void) InvalidateRect(hWindow, &pViewport->panel.region, FALSE);
    }

    if (generateObstructive)
    {
        VectorII scale = pState->box.size;

        VectorII obstruct = {
            ((rand() % pViewport->canvas.size.cx) / scale.x) * scale.x,
            ((rand() % pViewport->canvas.size.cy) / scale.y) * scale.y
        };

        Node node = {obstruct};
        (void) blokDynListAdd(&pState->obstructives, &node);

        RECT updateRegion = blokConvertVectorRect(obstruct, pState->box.size);

        (void) StringCbPrintfW(
            pViewport->obstructCountText.data, 60, L"%ld", pState->obstructives.size);

        blokProgressBarUpdateMinMax(
            &pViewport->obstructMemoryBar, 0, pState->obstructives.max);
        blokProgressBarUpdateValue(
            &pViewport->obstructMemoryBar, pState->obstructives.size);

        (void) InvalidateRect(hWindow, &updateRegion, FALSE);
        (void) InvalidateRect(hWindow, &pViewport->obstructCountText.region, FALSE);
        (void) InvalidateRect(hWindow, &pViewport->obstructMemoryBar.region, FALSE);
    }

    if (changeTheme)
    {
        Graphics *pGraphics = blokContextGetGraphics();
        int currentTheme = pGraphics->theme;
        blokGraphicsFree(pGraphics);
        blokGraphicsInit(
            pGraphics, 
            (currentTheme == 1 || currentTheme == 0) 
            ? BLOK_THEME_LIGHT : BLOK_THEME_DARK
        );
        (void) InvalidateRect(hWindow, NULL, FALSE);
    }

    if (clearObstructs)
    {
        blokDynListClear(&pState->obstructives);
        blokProgressBarUpdateValue(
            &pViewport->obstructMemoryBar, pState->obstructives.size);
        (void) StringCbPrintfW(
            pViewport->obstructCountText.data, 60, L"%ld", pState->obstructives.size);
        (void) InvalidateRect(hWindow, &pViewport->obstructCountText.region, FALSE);
        (void) InvalidateRect(hWindow, &pViewport->obstructMemoryBar.region, FALSE);
        (void) InvalidateRect(hWindow, &pViewport->canvas.region, FALSE);
    }

    if (toggleLock)
    {
        pViewport->isCanvasLocked = !pViewport->isCanvasLocked;
        blokToggleUpdateSelected(&pViewport->lockedToggle, pViewport->isCanvasLocked);
        (void) InvalidateRect(hWindow, &pViewport->lockedToggle.region, FALSE);
    }
}

void blokProcessEventOnLeftMouseDown(HWND hWindow, LPARAM mousepos)
{
    State *pState = blokContextGetState();
    Viewport *pViewport = blokContextGetViewport();
    
    pViewport->isLeftMouseDown = TRUE;

    VectorII span = pState->box.size;

    VectorII mpos = {
        (GET_X_LPARAM(mousepos) / span.x) * span.x,
        (GET_Y_LPARAM(mousepos) / span.y) * span.y
    };

    if (mpos.x > pViewport->panel.region.left && mpos.x < pViewport->panel.region.right 
        && mpos.y > pViewport->panel.region.top && mpos.y < pViewport->panel.region.bottom
        && pViewport->isInterfaceVisible)
    {
        if (BLOK_MOUSE_AT(pViewport->generateButton.region, pViewport->mousePos))
        {
            (void) SendMessageW(hWindow, WM_KEYDOWN, (WPARAM)'O', 0);
        }

        if (BLOK_MOUSE_AT(pViewport->clearAllButton.region, pViewport->mousePos))
        {
            (void) SendMessageW(hWindow, WM_KEYDOWN, (WPARAM)'C', 0);
        }

        if (BLOK_MOUSE_AT(pViewport->lockedToggle.region, pViewport->mousePos))
        {
            (void) SendMessageW(hWindow, WM_KEYDOWN, (WPARAM)'L', 0);
        }

        (void) InvalidateRect(hWindow, &pViewport->panel.region, FALSE);
        return;
    }

    if (pViewport->isCanvasLocked)
    {
        return;
    }

    Node node = {mpos};
    
    int exists = blokDynListExists(&pState->obstructives, &node);
    if (exists) { return; }

    long r = blokDynListAdd(&pState->obstructives, &node);
    (void) wprintf(L"pushed to list at idx %ld (%d, %d)\n",r, mpos.x, mpos.y);

    (void) StringCbPrintfW(
        pViewport->obstructCountText.data, 60, L"%ld", pState->obstructives.size);

    blokProgressBarUpdateMinMax(
        &pViewport->obstructMemoryBar, 0, pState->obstructives.max);
    blokProgressBarUpdateValue(
        &pViewport->obstructMemoryBar, pState->obstructives.size);

    RECT refreshRegion = {
        mpos.x,
        mpos.y,
        mpos.x + span.x,
        mpos.y + span.y
    };

    (void) InvalidateRect(hWindow, &refreshRegion, FALSE);
    (void) InvalidateRect(hWindow, &pViewport->obstructCountText.region, FALSE);
    (void) InvalidateRect(hWindow, &pViewport->obstructMemoryBar.region, FALSE);

}

void blokProcessEventOnLeftMouseUp(HWND hWindow, LPARAM mousepos)
{
    State *pState = blokContextGetState();
    Viewport *pViewport = blokContextGetViewport();

    pViewport->isLeftMouseDown = FALSE;
}

void blokProcessEventOnResize(HWND hWindow)
{
    Viewport *pViewport = blokContextGetViewport();
    State *pState = blokContextGetState();

    (void) GetClientRect(hWindow, &pViewport->region);
    blokPanelUpdate(&pViewport->panel, &pViewport->region);
    blokCanvasUpdate(&pViewport->canvas, &pViewport->region);
    blokTextUpdate(
        &pViewport->coordinatesText, 
        &((POINT){pViewport->panel.region.left+10, pViewport->panel.region.top+10}));
    blokButtonUpdate(
        &pViewport->clearAllButton, 
        &((POINT){
            pViewport->coordinatesText.region.right+10, 
            pViewport->coordinatesText.region.top}
        ));
    blokButtonUpdate(
        &pViewport->generateButton, 
        &((POINT){
            pViewport->clearAllButton.region.right+10, 
            pViewport->clearAllButton.region.top}
        ));
    blokTextUpdate(
        &pViewport->obstructCountText,
        &((POINT){
            pViewport->generateButton.region.right+10, 
            pViewport->generateButton.region.top}
        ));
    blokProgressBarUpdate(
        &pViewport->obstructMemoryBar, 
        &((POINT){
            pViewport->obstructCountText.region.right+10, 
            pViewport->obstructCountText.region.top}));
    blokProgressBarUpdateMinMax(
        &pViewport->obstructMemoryBar, 0, pState->obstructives.max);
    blokProgressBarUpdateValue(
        &pViewport->obstructMemoryBar, pState->obstructives.size);
    blokToggleUpdate(
        &pViewport->lockedToggle,
        &((POINT){
            pViewport->obstructMemoryBar.region.right+10,
            pViewport->obstructMemoryBar.region.top}));
    blokTextUpdate(
        &pViewport->lockedToggleText, 
        &((POINT){
            pViewport->lockedToggle.region.right+10, 
            pViewport->lockedToggle.region.top}));
}

void blokProcessEventOnMouseHover(HWND hWindow, LPARAM mousepos)
{
    Viewport *pViewport = blokContextGetViewport();
    State *pState = blokContextGetState();
    VectorII scale = pState->box.size;

    pViewport->mousePos.X = GET_X_LPARAM(mousepos);
    pViewport->mousePos.Y = GET_Y_LPARAM(mousepos);

    if (pViewport->isCanvasLocked)
    {
        (void) InvalidateRect(hWindow, NULL, FALSE);
        return;
    }

    if (BLOK_MOUSE_AT(pViewport->panel.region, pViewport->mousePos) 
        && pViewport->isInterfaceVisible)
    {
        (void) InvalidateRect(hWindow, NULL, FALSE);
        return;
    }

    if (pViewport->isLeftMouseDown)
    {
        Node pos = {{
            (pViewport->mousePos.X / scale.x) * scale.x,
            (pViewport->mousePos.Y / scale.y) * scale.y
        }};
        if (blokDynListExists(&pState->obstructives, &pos)) { return; }
        blokDynListAdd(&pState->obstructives, &pos);
        RECT updateRegion = blokConvertVectorRect(pos.data, scale);
        blokProgressBarUpdateMinMax(
            &pViewport->obstructMemoryBar, 0, pState->obstructives.max);
        blokProgressBarUpdateValue(
            &pViewport->obstructMemoryBar, pState->obstructives.size);
        (void) StringCbPrintfW(
            pViewport->obstructCountText.data, 60, L"%ld", pState->obstructives.size);
        (void) InvalidateRect(hWindow, &updateRegion, FALSE);
        (void) InvalidateRect(hWindow, &pViewport->obstructCountText.region, FALSE);
        (void) InvalidateRect(hWindow, &pViewport->obstructMemoryBar.region, FALSE);
    }

    if (pViewport->isRightMouseDown)
    {
        Node pos = {{
            (pViewport->mousePos.X / scale.x) * scale.x,
            (pViewport->mousePos.Y / scale.y) * scale.y
        }};
        if (!blokDynListExists(&pState->obstructives, &pos)) { return; }
        (void) blokDynListRemove(&pState->obstructives, pos);
        RECT updateRegion = blokConvertVectorRect(pos.data, scale);
        blokProgressBarUpdateMinMax(
            &pViewport->obstructMemoryBar, 0, pState->obstructives.max);
        blokProgressBarUpdateValue(
            &pViewport->obstructMemoryBar, pState->obstructives.size);
        (void) StringCbPrintfW(
            pViewport->obstructCountText.data, 60, L"%ld", pState->obstructives.size);
        (void) InvalidateRect(hWindow, &updateRegion, FALSE);
        (void) InvalidateRect(hWindow, &pViewport->obstructCountText.region, FALSE);
        (void) InvalidateRect(hWindow, &pViewport->obstructMemoryBar.region, FALSE);
    }

    (void) InvalidateRect(hWindow, NULL, FALSE);
}

void blokProcessEventOnRightMouseDown(HWND hWindow, LPARAM mousepos)
{
    State *pState = blokContextGetState();
    Viewport *pViewport = blokContextGetViewport();

    pViewport->isRightMouseDown = TRUE;

    VectorII span = pState->box.size;

    VectorII mpos = {
        (GET_X_LPARAM(mousepos) / span.x) * span.x,
        (GET_Y_LPARAM(mousepos) / span.y) * span.y
    };

    if (pViewport->isCanvasLocked) { return; }

    Node node = {mpos};

    if (blokDynListExists(&pState->obstructives, &node))
    {
        (void) blokDynListRemove(&pState->obstructives, node);

        RECT updateRegion = blokConvertVectorRect(node.data, pState->box.size);

        blokProgressBarUpdateMinMax(
            &pViewport->obstructMemoryBar, 0, pState->obstructives.max);
        blokProgressBarUpdateValue(
            &pViewport->obstructMemoryBar, pState->obstructives.size);
        (void) StringCbPrintfW(
            pViewport->obstructCountText.data, 60, L"%ld", pState->obstructives.size);
        (void) InvalidateRect(hWindow, &updateRegion, FALSE);
        (void) InvalidateRect(hWindow, &pViewport->obstructCountText.region, FALSE);
        (void) InvalidateRect(hWindow, &pViewport->obstructMemoryBar.region, FALSE);
    }

}

void blokProcessEventOnRightMouseUp(HWND hWindow, LPARAM mousepos)
{
    Viewport *pViewport = blokContextGetViewport();

    pViewport->isRightMouseDown = FALSE;
}