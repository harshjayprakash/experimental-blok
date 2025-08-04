/**
 * @file   viewport.c
 * @brief  Viewport Implementation.
 * @author harshjayprakash
 * @date   2025-07-23
 ****************************************************************************************/

#include "viewport.h"
#include <strsafe.h>
#include <time.h>

int stViewportInit(TViewport *pViewport, HINSTANCE hInstance)
{
    if (pViewport == NULL)
    {
        return 0;
    }

    srand((unsigned int)time(0));

    int success = stWindowInit(&pViewport->window, hInstance);

    if (!success)
    {
        return 0;
    }

    pViewport->isLeftMouseDown = 0;
    pViewport->isRightMouseDown = 0;
    pViewport->isInterfaceVisible = 1;
    pViewport->isGridVisible = 0;
    pViewport->isCanvasLocked = 0;

    pViewport->hFont =
        CreateFontW(16, 0, GM_COMPATIBLE, 0, FW_NORMAL, FALSE, FALSE, FALSE,
                    DEFAULT_CHARSET, OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS,
                    CLEARTYPE_QUALITY, FF_DONTCARE, L"Segoe UI");

    if (pViewport->hFont == NULL)
    {
        (void)MessageBoxW(0, L"Font Loading Failed.", L"Blok", MB_OK | MB_ICONERROR);
    }

    (void)GetClientRect(pViewport->window.hHandle, &pViewport->region);

    (void)stPanelUpdateEx(&pViewport->panel, &pViewport->region, &(SIZE){500, 40},
                          &(SIZE){0, 0});
    (void)stCanvasUpdate(&pViewport->canvas, &pViewport->region);

    (void)stTextUpdateEx(
        &pViewport->coordinatesText,
        &(POINT){pViewport->panel.region.left + 10, pViewport->panel.region.top + 10},
        &(SIZE){100, 20}, &(SIZE){0, 0});
    (void)StringCbPrintfW(pViewport->coordinatesText.data, ST_TEXT_SIZE, L"(0, 0)");

    (void)stButtonUpdateEx(&pViewport->clearAllButton,
                           &(POINT){pViewport->coordinatesText.region.right + 10,
                                    pViewport->coordinatesText.region.top},
                           &(SIZE){60, 20}, &(SIZE){0, 0});
    (void)StringCbPrintfW(pViewport->clearAllButton.text, ST_BUTTON_TEXT_SIZE, L"Clear All");

    (void)stButtonUpdateEx(&pViewport->generateButton,
                           &(POINT){pViewport->clearAllButton.region.right + 10,
                                    pViewport->clearAllButton.region.top},
                           &(SIZE){70, 20}, &(SIZE){0, 0});
    (void)StringCbPrintfW(pViewport->generateButton.text, ST_BUTTON_TEXT_SIZE,
                          L"Generate");

    (void)stTextUpdateEx(&pViewport->obstructCountText,
                         &(POINT){pViewport->generateButton.region.right + 10,
                                  pViewport->generateButton.region.top},
                         &(SIZE){25, 20}, &(SIZE){0, 0});
    (void)StringCbPrintfW(pViewport->obstructCountText.data, ST_TEXT_SIZE, L"0");

    (void)stProgressBarUpdateEx(&pViewport->obstructMemoryBar,
                                &(POINT){pViewport->obstructCountText.region.right + 10,
                                         pViewport->obstructCountText.region.top},
                                &(SIZE){70, 20}, &(SIZE){0, 0}, &(SIZE){3, 3});

    (void)stToggleUpdateEx(&pViewport->lockedToggle,
                           &(POINT){pViewport->obstructMemoryBar.region.right + 10,
                                    pViewport->obstructMemoryBar.region.top},
                           &(SIZE){20, 20}, &(SIZE){0, 0}, &(SIZE){5, 5});
    (void)stToggleUpdateSelected(&pViewport->lockedToggle, FALSE);

    (void)stTextUpdateEx(&pViewport->lockedToggleText,
                         &(POINT){pViewport->lockedToggle.region.right + 10,
                                  pViewport->lockedToggle.region.top},
                         &(SIZE){30, 20}, &(SIZE){0, 0});
    (void)StringCbPrintfW(pViewport->lockedToggleText.data, ST_TEXT_SIZE, L"Locked");

    return 1;
}

int stViewportShow(TViewport *pViewport, DWORD showFlag)
{
    if (pViewport == NULL)
    {
        return -1;
    }

    return stWindowShow(&pViewport->window, showFlag);
}

int stViewportFree(TViewport *pViewport, HINSTANCE hInstance)
{
    if (pViewport == NULL)
    {
        return 0;
    }

    if (pViewport->hFont != NULL)
    {
        (void)DeleteObject(pViewport->hFont);
    }

    return stWindowFree(&pViewport->window, hInstance);
}