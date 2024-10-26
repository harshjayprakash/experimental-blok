/**
 * \file panel.c
 * \date 07-09-2024
 * \brief Function implementation for the panel component.
 *
 * This file contains the function implementation for the panel component for intialising,
 * rendering, releasing resources and state changes.
 */

#include "panel.h"
#include "../components/canvas.h"
#include "../controls/button.h"
#include "../controls/progress-bar.h"
#include "../controls/text.h"
#include "../controls/toggle-button.h"
#include "../graphics/drawing.h"
#include "../graphics/theme.h"
#include "../objects/block.h"
#include "../objects/obstructables.h"
#include "../window.h"
#include <Windows.h>
#include <wchar.h>
#include <wingdi.h>

static RECT mPanelArea = {0};
static BlokTextControl mCoordinateText = {0};
static BlokButtonControl mClearAllButton = {0};
static BlokToggleButtonControl mLockedToggle = {0};
static BlokProgressBarControl mVectorMemory = {0};
static BlokButtonControl mRandomGeneration = {0};

void __BlokUpdatePanelArea(void)
{
    RECT windowArea = BlokGetWindowArea();

    mPanelArea = (RECT){windowArea.left + 2, windowArea.bottom - 40, windowArea.right - 1,
                        windowArea.bottom - 1};
}

void __BlokUpdateControlPositions(void)
{
    mCoordinateText.area.left = 12;
    mCoordinateText.area.top = mPanelArea.top + 10;
    mCoordinateText.area.right = mCoordinateText.area.left + 140;
    mCoordinateText.area.bottom = mCoordinateText.area.top + 20;
    mCoordinateText.position.Y = mPanelArea.top + 10;
    mCoordinateText.position.X = 15;

    mClearAllButton.area.left = 157;
    mClearAllButton.area.top = mPanelArea.top + 10;
    mClearAllButton.area.right = mClearAllButton.area.left + 62;
    mClearAllButton.area.bottom = mClearAllButton.area.top + 20;
    mClearAllButton.alignment.X = mClearAllButton.area.left + 3;
    mClearAllButton.alignment.Y = mClearAllButton.area.top + 1;

    mLockedToggle.buttonArea.left = mClearAllButton.area.right + 10;
    mLockedToggle.buttonArea.top = mPanelArea.top + 10;
    mLockedToggle.buttonArea.right = mLockedToggle.buttonArea.left + 20;
    mLockedToggle.buttonArea.bottom = mLockedToggle.buttonArea.top + 20;

    mLockedToggle.selectedArea.left = mLockedToggle.buttonArea.left + 4;
    mLockedToggle.selectedArea.top = mLockedToggle.buttonArea.top + 4;
    mLockedToggle.selectedArea.right = mLockedToggle.buttonArea.right - 5;
    mLockedToggle.selectedArea.bottom = mLockedToggle.buttonArea.bottom - 5;

    mLockedToggle.textPosition.X = mLockedToggle.buttonArea.right + 10;
    mLockedToggle.textPosition.Y = mLockedToggle.buttonArea.top + 1;

    mLockedToggle.wholeArea.left = mLockedToggle.buttonArea.left;
    mLockedToggle.wholeArea.top = mLockedToggle.buttonArea.top;
    mLockedToggle.wholeArea.right = mLockedToggle.wholeArea.left + 85;
    mLockedToggle.wholeArea.bottom = mLockedToggle.wholeArea.top + 20;

    mVectorMemory.area.left = mLockedToggle.wholeArea.right + 30;
    mVectorMemory.area.top = mPanelArea.top + 10;
    mVectorMemory.area.right = mVectorMemory.area.left + 120;
    mVectorMemory.area.bottom = mVectorMemory.area.top + 20;

    mVectorMemory.barOutline.left = mVectorMemory.area.left + 40;
    mVectorMemory.barOutline.top = mVectorMemory.area.top;
    mVectorMemory.barOutline.right = mVectorMemory.area.right;
    mVectorMemory.barOutline.bottom = mVectorMemory.area.bottom;

    mVectorMemory.textPosition.X = mVectorMemory.area.left + 3;
    mVectorMemory.textPosition.Y = mVectorMemory.area.top + 1;

    mRandomGeneration.area.left = mVectorMemory.area.right + 20;
    mRandomGeneration.area.top = mPanelArea.top + 10;
    mRandomGeneration.area.right = mRandomGeneration.area.left + 70;
    mRandomGeneration.area.bottom = mRandomGeneration.area.top + 20;
    mRandomGeneration.alignment.X = mRandomGeneration.area.left + 3;
    mRandomGeneration.alignment.Y = mRandomGeneration.area.top + 1;
}

void BlokInitPanelComponent(void)
{
    __BlokUpdatePanelArea();

    mCoordinateText = (BlokTextControl){L"( X: 0, Y: 0 )", 60, {0, 0}, {0, 0, 0, 0}};

    mClearAllButton = (BlokButtonControl){L"Clear All", 60, {0, 0}, {0, 0, 0, 0}};

    mLockedToggle = (BlokToggleButtonControl){
        L"Locked", 60, {0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, 0};

    mVectorMemory = (BlokProgressBarControl){
        L"0", 60, {0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, 0, 0, 0};

    mRandomGeneration = (BlokButtonControl){L"Generate", 60, {0, 0}, {0, 0, 0, 0}};

    __BlokUpdateControlPositions();

    mVectorMemory.bar.left = mVectorMemory.barOutline.left + 2;
    mVectorMemory.bar.top = mVectorMemory.barOutline.top + 2;
    mVectorMemory.bar.right = mVectorMemory.barOutline.right - 3;
    mVectorMemory.bar.bottom = mVectorMemory.barOutline.bottom - 3;

    mVectorMemory.barMin = mVectorMemory.bar.left;
    mVectorMemory.barMax = mVectorMemory.bar.right;
    mVectorMemory.barSpan = mVectorMemory.bar.right - mVectorMemory.bar.left;

    BlokUpdatePanelSize();
}

void BlokRenderPanelComponent(HDC displayContext)
{
    (void)SelectObject(displayContext, BlokGetBackgroundBrush());
    (void)SelectObject(displayContext, BlokGetForegroundPen());
    (void)SetBkColor(displayContext, BlokGetBackgroundColour());
    (void)SetTextColor(displayContext, BlokGetForegroundColour());

    (void)Rectangle(displayContext, mPanelArea.left, mPanelArea.top, mPanelArea.right,
                    mPanelArea.bottom);
    (void)TextOutW(displayContext, mCoordinateText.position.X, mCoordinateText.position.Y,
                   mCoordinateText.text, (int)wcslen(mCoordinateText.text));
    (void)Rectangle(displayContext, mClearAllButton.area.left, mClearAllButton.area.top,
                    mClearAllButton.area.right, mClearAllButton.area.bottom);
    (void)TextOutW(displayContext, mClearAllButton.alignment.X,
                   mClearAllButton.alignment.Y, mClearAllButton.text,
                   (int)wcslen(mClearAllButton.text));
    (void)Rectangle(displayContext, mLockedToggle.wholeArea.left,
                    mLockedToggle.wholeArea.top, mLockedToggle.wholeArea.right,
                    mLockedToggle.wholeArea.bottom);
    (void)Rectangle(displayContext, mLockedToggle.buttonArea.left,
                    mLockedToggle.buttonArea.top, mLockedToggle.buttonArea.right,
                    mLockedToggle.buttonArea.bottom);
    (void)TextOutW(displayContext, mLockedToggle.textPosition.X,
                   mLockedToggle.textPosition.Y, mLockedToggle.text,
                   (int)wcslen(mLockedToggle.text));

    if (mLockedToggle.selected)
    {
        (void)FillRect(displayContext, &mLockedToggle.selectedArea,
                       BlokGetForegroundBrush());
    }

    (void)Rectangle(displayContext, mVectorMemory.area.left, mVectorMemory.area.top,
                    mVectorMemory.area.right, mVectorMemory.area.bottom);
    (void)Rectangle(displayContext, mVectorMemory.barOutline.left,
                    mVectorMemory.barOutline.top, mVectorMemory.barOutline.right,
                    mVectorMemory.barOutline.bottom);
    (void)FillRect(displayContext, &mVectorMemory.bar, BlokGetForegroundBrush());
    (void)TextOutW(displayContext, mVectorMemory.textPosition.X,
                   mVectorMemory.textPosition.Y, mVectorMemory.text,
                   (int)wcslen(mVectorMemory.text));

    (void)Rectangle(displayContext, mRandomGeneration.area.left,
                    mRandomGeneration.area.top, mRandomGeneration.area.right,
                    mRandomGeneration.area.bottom);
    (void)TextOutW(displayContext, mRandomGeneration.alignment.X,
                   mRandomGeneration.alignment.Y, mRandomGeneration.text,
                   (int)wcslen(mRandomGeneration.text));
}

void BlokUpdateCoordinatesText(void)
{
    BlokPosition squarePosition = BlokGetBlockPosition();

    (void)swprintf(mCoordinateText.text, 60, L"( X: %d, Y: %d )", squarePosition.x,
                   squarePosition.y);
}

void BlokUpdateSquareCountText(void)
{
    (void)swprintf(mVectorMemory.text, 60, L"%d", BlokGetObstrutableCount());
}

void BlokUpdatePanelSize(void)
{
    __BlokUpdatePanelArea();
    __BlokUpdateControlPositions();
    BlokUpdateVectorMemoryBar();
}

void BlokUpdateVectorMemoryBar(void)
{
    mVectorMemory.bar.left = mVectorMemory.barOutline.left + 2;
    mVectorMemory.bar.top = mVectorMemory.barOutline.top + 2;
    mVectorMemory.bar.bottom = mVectorMemory.barOutline.bottom - 3;
    mVectorMemory.bar.right = mVectorMemory.barOutline.left + 2 +
                              (mVectorMemory.barSpan * BlokGetVectorMemoryPercentage());
    BlokUpdateSquareCountText();
}

int BlokIsInClearButtonArea(const int x, const int y)
{
    return (x > mClearAllButton.area.left - 1 && x < mClearAllButton.area.right + 1 &&
            y > mClearAllButton.area.top - 1 && y < mClearAllButton.area.bottom + 1);
}

int BlokIsInLockToggleArea(const int x, const int y)
{
    return (
        x > mLockedToggle.buttonArea.left - 1 && x < mLockedToggle.buttonArea.right + 1 &&
        y > mLockedToggle.buttonArea.top - 1 && y < mLockedToggle.buttonArea.bottom + 1);
}

int BlokIsInGenerateButtonArea(const int x, const int y)
{
    return (x > mRandomGeneration.area.left - 1 && x < mRandomGeneration.area.right + 1 &&
            y > mRandomGeneration.area.top - 1 && y < mRandomGeneration.area.bottom + 1);
}

int BlokIsInPanelArea(const int x, const int y)
{
    return (x > mPanelArea.left - 1 && x < mPanelArea.right + 1 &&
            y > mPanelArea.top - 1 && y < mPanelArea.bottom + 1);
}

void BlokInvalidateCoordinateTextArea(void)
{
    (void)InvalidateRect(BlokGetWindowHandle(), &mCoordinateText.area, FALSE);
}

void BlokInvalidateClearAllButtonArea(void)
{
    (void)InvalidateRect(BlokGetWindowHandle(), &mClearAllButton.area, FALSE);
}

void BlokInvalidateLockedToggleArea(void)
{
    (void)InvalidateRect(BlokGetWindowHandle(), &mLockedToggle.buttonArea, FALSE);
}

void BlokInvalidateProgressBarArea(void)
{
    (void)InvalidateRect(BlokGetWindowHandle(), &mVectorMemory.area, FALSE);
}

void BlokInvalidateRandomButtonArea(void)
{
    (void)InvalidateRect(BlokGetWindowHandle(), &mRandomGeneration.area, FALSE);
}

void BlokHandleLockToggleButtonClick(void)
{
    mLockedToggle.selected = (mLockedToggle.selected) ? 0 : 1;
    BlokToggleCanvasLock();
}

void BlokFreePanelComponent(void)
{
}