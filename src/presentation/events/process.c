#include "process.h"
#include "../../core/context.h"
#include "../../service/convert.h"
#include <strsafe.h>
#include <Windowsx.h>

#define __BLOK_MOUSE_AT_(rect, pos) \
    (pos.X > rect.left && pos.X < rect.right && pos.Y > rect.top && pos.Y < rect.bottom)

void BlokProcessEventOnPaint(HWND window)
{
    Graphics *graphics = BlokContextGetGraphics();
    Viewport *viewport = BlokContextGetViewport();
    State *state = BlokContextGetState();
    VectorII scaling = state->box.size;

    PAINTSTRUCT paintstruct;
    HDC surface = BeginPaint(window, &paintstruct);
    HDC offSurface = CreateCompatibleDC(surface);
    HBITMAP offSurfaceBitmap = CreateCompatibleBitmap(
        surface, viewport->region.right, viewport->region.bottom);
    HBITMAP surfaceBitmap = SelectObject(offSurface, offSurfaceBitmap);
    HFONT oldFont = (HFONT) 0;
    HBRUSH oldBrush = (HBRUSH) SelectObject(offSurface, graphics->tools.surfaceBrush);
    HPEN oldPen = (HPEN) SelectObject(offSurface, graphics->tools.onSurfacePen);
    INT oldBkMode = SetBkMode(offSurface, TRANSPARENT);
    COLORREF oldBkColour = SetBkColor(offSurface, graphics->colours.surface);
    COLORREF oldTextColour = SetTextColor(offSurface, graphics->colours.onSurface);

    if (viewport->font != (HFONT) 0)
    {
        HFONT oldFont = (HFONT) SelectObject(offSurface, viewport->font);
    }

    (void) FillRect(offSurface, &viewport->region, graphics->tools.surfaceBrush);

    (void) SelectObject(offSurface, graphics->tools.onSurfaceVariantPen);

    if (viewport->isGridVisible)
    {
        for (long xAxisIdx = 0; 
            xAxisIdx < viewport->canvas.region.right; 
            xAxisIdx += scaling.x)
        {
            (void) MoveToEx(offSurface, xAxisIdx, 0, NULL);
            (void) LineTo(offSurface, xAxisIdx, viewport->canvas.region.bottom);
        }

        for (long yAxisIdx = 0; 
            yAxisIdx < viewport->canvas.region.bottom; 
            yAxisIdx += scaling.y)
        {
            (void) MoveToEx(offSurface, 0, yAxisIdx, NULL);
            (void) LineTo(offSurface, viewport->canvas.region.right, yAxisIdx);
        }
    }

    RECT box = BlokConvertVectorRect(state->box.position, state->box.size);
    INT innerBoxSF = 3;
    RECT innerBox = {
        box.left + (scaling.x / innerBoxSF),
        box.top + (scaling.y / innerBoxSF),
        box.right - (scaling.x / innerBoxSF),
        box.bottom - (scaling.y / innerBoxSF)
    };
    (void) FillRect(offSurface, &box, graphics->tools.primaryBrush);
    (void) FillRect(offSurface, &innerBox, graphics->tools.surfaceBrush);

    for (long obstructIdx = 0; obstructIdx < state->obstructives.size; obstructIdx++)
    {
        RECT obstructiveRc = BlokConvertVectorRect(
            state->obstructives.arr[obstructIdx].data, scaling);
        (void) FillRect(offSurface, &obstructiveRc, graphics->tools.secondaryBrush);
    }

    if (viewport->isInterfaceVisible)
    {
        (void) FillRect(
            offSurface, &viewport->panel.region, graphics->tools.surfaceVariantBrush);
        
        (void) DrawTextW(
            offSurface, viewport->coordinatesText.data, -1, 
            &viewport->coordinatesText.region, 
            DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_TOP);

        (void) SelectObject(offSurface, 
            __BLOK_MOUSE_AT_(viewport->clearAllButton.region, viewport->mousePos) ?
            graphics->tools.onPrimaryVariantPen : graphics->tools.onSurfaceVariantPen);

        (void) Rectangle(
            offSurface, viewport->clearAllButton.region.left, 
            viewport->clearAllButton.region.top, viewport->clearAllButton.region.right, 
            viewport->clearAllButton.region.bottom);
        (void) DrawTextW(
            offSurface, viewport->clearAllButton.text, -1, 
            &viewport->clearAllButton.region, 
            DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);

        (void) SelectObject(offSurface, 
            __BLOK_MOUSE_AT_(viewport->generateButton.region, viewport->mousePos) ?
            graphics->tools.onPrimaryVariantPen : graphics->tools.onSurfaceVariantPen);

        (void) Rectangle(
            offSurface, viewport->generateButton.region.left, 
            viewport->generateButton.region.top, viewport->generateButton.region.right, 
            viewport->generateButton.region.bottom);
        (void) DrawTextW(
            offSurface, viewport->generateButton.text, -1, 
            &viewport->generateButton.region, 
            DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);

        (void) SelectObject(offSurface, graphics->tools.onSurfaceVariantPen);

        (void) DrawTextW(
            offSurface, viewport->obstructCountText.data, -1, 
            &viewport->obstructCountText.region, 
            DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);
        
        (void) Rectangle(
            offSurface, viewport->obstructMemoryBar.region.left, 
            viewport->obstructMemoryBar.region.top, 
            viewport->obstructMemoryBar.region.right, 
            viewport->obstructMemoryBar.region.bottom);
        (void) FillRect(
            offSurface, &viewport->obstructMemoryBar.barRegion, 
            graphics->tools.secondaryBrush);
        
        (void) SelectObject(offSurface, 
            __BLOK_MOUSE_AT_(viewport->lockedToggle.region, viewport->mousePos) ?
            graphics->tools.onPrimaryVariantPen : graphics->tools.onSurfaceVariantPen);
    
        (void) Rectangle(
            offSurface, viewport->lockedToggle.region.left, 
            viewport->lockedToggle.region.top, 
            viewport->lockedToggle.region.right, 
            viewport->lockedToggle.region.bottom);

        (void) SelectObject(offSurface, graphics->tools.onSurfaceVariantPen);

        if (viewport->lockedToggle.selected)
        {
            (void) FillRect(
                offSurface, &viewport->lockedToggle.selectRegion, 
                graphics->tools.secondaryBrush);
        }

        (void) DrawTextW(
            offSurface, viewport->lockedToggleText.data, -1, 
            &viewport->lockedToggleText.region, 
            DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);
    }

    (void) BitBlt(
        surface, 0, 0, viewport->region.right, viewport->region.bottom, 
        offSurface, 0, 0, SRCCOPY);
    
    if (viewport->font != (HFONT) 0) 
    { 
        (void) SelectObject(offSurface, oldFont); 
    }

    (void) SetTextColor(offSurface, oldTextColour);
    (void) SetBkColor(offSurface, oldBkColour);
    (void) SetBkMode(offSurface, oldBkMode);
    (void) SelectObject(offSurface, oldPen);
    (void) SelectObject(offSurface, oldBrush);
    (void) SelectObject(offSurface, surfaceBitmap);
    (void) DeleteObject(offSurfaceBitmap);
    (void) DeleteDC(offSurface);
    (void) EndPaint(window, &paintstruct);
}

void BlokProcessEventOnKeyDown(HWND window, WPARAM virtualKey)
{
    State *state = BlokContextGetState();
    Viewport *viewport = BlokContextGetViewport();
    Direction moveBoxOperation = 0;
    int changeGridVisibility = 0;
    int changeInterfaceVisibility = 0;
    int generateObstructive = 0;
    int changeTheme = 0;
    int clearObstructs = 0;
    int toggleLock = 0;

    switch (virtualKey)
    {
    case 'W': 
        moveBoxOperation = BLOK_DIRECTION_NORTH; 
        break;
    
    case 'A':
        moveBoxOperation = BLOK_DIRECTION_WEST;
        break;
    
    case 'S':
        moveBoxOperation = BLOK_DIRECTION_SOUTH;
        break;
    
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
        if (BlokStateBoxMovableInDirection(state, moveBoxOperation))
        {
            BlokStateMoveBox(&state->box, moveBoxOperation);
        }

        (void) StringCbPrintfW(
            viewport->coordinatesText.data, 60,
            L"(%d, %d)", state->box.position.x, state->box.position.y);
        
        RECT boxUpdateRegion = {
            state->box.position.x - state->box.size.x,
            state->box.position.y - state->box.size.x,
            state->box.position.x + (state->box.size.x * 2),
            state->box.position.y + (state->box.size.y * 2),
        };
        (void) InvalidateRect(window, &boxUpdateRegion, FALSE);
        (void) InvalidateRect(window, &viewport->panel.region, FALSE);
    }

    if (changeGridVisibility)
    {
        viewport->isGridVisible = !viewport->isGridVisible;
        (void) InvalidateRect(window, &viewport->canvas.region, FALSE);
    }

    if (changeInterfaceVisibility)
    {
        viewport->isInterfaceVisible = !viewport->isInterfaceVisible;
        (void) InvalidateRect(window, &viewport->panel.region, FALSE);
    }

    if (generateObstructive)
    {
        VectorII scale = state->box.size;

        VectorII obstruct = {
            ((rand() % viewport->canvas.size.cx) / scale.x) * scale.x,
            ((rand() % viewport->canvas.size.cy) / scale.y) * scale.y
        };

        Node node = {obstruct};
        (void) BlokDynListAdd(&state->obstructives, &node);

        RECT updateRegion = BlokConvertVectorRect(obstruct, state->box.size);

        (void) StringCbPrintfW(
            viewport->obstructCountText.data, 60, L"%ld", state->obstructives.size);

        BlokProgressBarUpdateMinMax(
            &viewport->obstructMemoryBar, 0, state->obstructives.max);
        BlokProgressBarUpdateValue(
            &viewport->obstructMemoryBar, state->obstructives.size);

        (void) InvalidateRect(window, &updateRegion, FALSE);
        (void) InvalidateRect(window, &viewport->obstructCountText.region, FALSE);
        (void) InvalidateRect(window, &viewport->obstructMemoryBar.region, FALSE);
    }

    if (changeTheme)
    {
        Graphics *graphics = BlokContextGetGraphics();
        int currentTheme = graphics->theme;
        BlokGraphicsFree(graphics);
        BlokGraphicsInit(
            graphics, 
            (currentTheme == 1 || currentTheme == 0) 
            ? BLOK_THEME_LIGHT : BLOK_THEME_DARK
        );
        (void) InvalidateRect(window, NULL, FALSE);
    }

    if (clearObstructs)
    {
        BlokDynListClear(&state->obstructives);
        BlokProgressBarUpdateValue(
            &viewport->obstructMemoryBar, state->obstructives.size);
        (void) StringCbPrintfW(
            viewport->obstructCountText.data, 60, L"%ld", state->obstructives.size);
        (void) InvalidateRect(window, &viewport->obstructCountText.region, FALSE);
        (void) InvalidateRect(window, &viewport->obstructMemoryBar.region, FALSE);
        (void) InvalidateRect(window, &viewport->canvas.region, FALSE);
    }

    if (toggleLock)
    {
        viewport->isCanvasLocked = !viewport->isCanvasLocked;
        BlokToggleUpdateSelected(&viewport->lockedToggle, viewport->isCanvasLocked);
        (void) InvalidateRect(window, &viewport->lockedToggle.region, FALSE);
    }
}

void BlokProcessEventOnLeftMouseDown(HWND window, LPARAM mousepos)
{
    State *state = BlokContextGetState();
    Viewport *viewport = BlokContextGetViewport();
    
    viewport->mouseDown = TRUE;

    VectorII span = state->box.size;

    VectorII mpos = {
        (GET_X_LPARAM(mousepos) / span.x) * span.x,
        (GET_Y_LPARAM(mousepos) / span.y) * span.y
    };

    if (mpos.x > viewport->panel.region.left && mpos.x < viewport->panel.region.right 
        && mpos.y > viewport->panel.region.top && mpos.y < viewport->panel.region.bottom
        && viewport->isInterfaceVisible)
    {
        if (__BLOK_MOUSE_AT_(viewport->generateButton.region, viewport->mousePos))
        {
            (void) SendMessageW(window, WM_KEYDOWN, (WPARAM)'O', 0);
        }

        if (__BLOK_MOUSE_AT_(viewport->clearAllButton.region, viewport->mousePos))
        {
            (void) SendMessageW(window, WM_KEYDOWN, (WPARAM)'C', 0);
        }

        if (__BLOK_MOUSE_AT_(viewport->lockedToggle.region, viewport->mousePos))
        {
            (void) SendMessageW(window, WM_KEYDOWN, (WPARAM)'L', 0);
        }

        (void) InvalidateRect(window, &viewport->panel.region, FALSE);
        return;
    }

    if (viewport->isCanvasLocked)
    {
        return;
    }

    Node node = {mpos};
    
    long r = BlokDynListAdd(&state->obstructives, &node);
    (void) wprintf(L"pushed to list at idx %ld (%d, %d)\n",r, mpos.x, mpos.y);

    (void) StringCbPrintfW(
        viewport->obstructCountText.data, 60, L"%ld", state->obstructives.size);

    BlokProgressBarUpdateMinMax(
        &viewport->obstructMemoryBar, 0, state->obstructives.max);
    BlokProgressBarUpdateValue(
        &viewport->obstructMemoryBar, state->obstructives.size);

    RECT refreshRegion = {
        mpos.x,
        mpos.y,
        mpos.x + span.x,
        mpos.y + span.y
    };

    (void) InvalidateRect(window, &refreshRegion, FALSE);
    (void) InvalidateRect(window, &viewport->obstructCountText.region, FALSE);
    (void) InvalidateRect(window, &viewport->obstructMemoryBar.region, FALSE);

}

void BlokProcessEventOnLeftMouseUp(HWND window, LPARAM mousepos)
{
    State *state = BlokContextGetState();
    Viewport *viewport = BlokContextGetViewport();

    viewport->mouseDown = FALSE;
}

void BlokProcessEventOnResize(HWND window)
{
    Viewport *viewport = BlokContextGetViewport();
    State *state = BlokContextGetState();

    (void) GetClientRect(window, &viewport->region);
    BlokPanelUpdate(&viewport->panel, &viewport->region);
    BlokCanvasUpdate(&viewport->canvas, &viewport->region);
    BlokTextUpdate(
        &viewport->coordinatesText, 
        &((POINT){viewport->panel.region.left+10, viewport->panel.region.top+10}));
    BlokButtonUpdate(
        &viewport->clearAllButton, 
        &((POINT){
            viewport->coordinatesText.region.right+10, 
            viewport->coordinatesText.region.top}
        ));
    BlokButtonUpdate(
        &viewport->generateButton, 
        &((POINT){
            viewport->clearAllButton.region.right+10, 
            viewport->clearAllButton.region.top}
        ));
    BlokTextUpdate(
        &viewport->obstructCountText,
        &((POINT){
            viewport->generateButton.region.right+10, 
            viewport->generateButton.region.top}
        ));
    BlokProgressBarUpdate(
        &viewport->obstructMemoryBar, 
        &((POINT){
            viewport->obstructCountText.region.right+10, 
            viewport->obstructCountText.region.top}));
    BlokProgressBarUpdateMinMax(
        &viewport->obstructMemoryBar, 0, state->obstructives.max);
    BlokProgressBarUpdateValue(
        &viewport->obstructMemoryBar, state->obstructives.size);
    BlokToggleUpdate(
        &viewport->lockedToggle,
        &((POINT){
            viewport->obstructMemoryBar.region.right+10,
            viewport->obstructMemoryBar.region.top}));
    BlokTextUpdate(
        &viewport->lockedToggleText, 
        &((POINT){
            viewport->lockedToggle.region.right+10, 
            viewport->lockedToggle.region.top}));
}

void BlokProcessEventOnMouseHover(HWND window, LPARAM mousepos)
{
    Viewport *viewport = BlokContextGetViewport();
    State *state = BlokContextGetState();
    VectorII scale = state->box.size;

    viewport->mousePos.X = GET_X_LPARAM(mousepos);
    viewport->mousePos.Y = GET_Y_LPARAM(mousepos);

    if (viewport->isCanvasLocked)
    {
        (void) InvalidateRect(window, NULL, FALSE);
        return;
    }

    if (__BLOK_MOUSE_AT_(viewport->panel.region, viewport->mousePos) 
        && viewport->isInterfaceVisible)
    {
        (void) InvalidateRect(window, NULL, FALSE);
        return;
    }

    if (viewport->mouseDown)
    {
        Node pos = {{
            (viewport->mousePos.X / scale.x) * scale.x,
            (viewport->mousePos.Y / scale.y) * scale.y
        }};
        if (BlokDynListExists(&state->obstructives, &pos)) { return; }
        BlokDynListAdd(&state->obstructives, &pos);
        RECT updateRegion = BlokConvertVectorRect(pos.data, scale);
        BlokProgressBarUpdateMinMax(
            &viewport->obstructMemoryBar, 0, state->obstructives.max);
        BlokProgressBarUpdateValue(
            &viewport->obstructMemoryBar, state->obstructives.size);
        (void) StringCbPrintfW(
            viewport->obstructCountText.data, 60, L"%ld", state->obstructives.size);
        (void) InvalidateRect(window, &updateRegion, FALSE);
        (void) InvalidateRect(window, &viewport->obstructCountText.region, FALSE);
        (void) InvalidateRect(window, &viewport->obstructMemoryBar.region, FALSE);
    }

    (void) InvalidateRect(window, NULL, FALSE);
}