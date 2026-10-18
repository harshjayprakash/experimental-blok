#include "viewport.h"
#include <strsafe.h>
#include <time.h>

int BlokViewportInit(TViewport *pViewport, HINSTANCE hInstance)
{
    if (pViewport == NULL)
    {
        return 0;
    }

    srand((unsigned int)time(0));

    int success = BlokWindowInit(&pViewport->window, hInstance);

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

    (void)BlokPanelUpdateEx(&pViewport->panel, &pViewport->region, &(SIZE){500, 40},
                          &(SIZE){0, 0});
    (void)BlokCanvasUpdate(&pViewport->canvas, &pViewport->region);

    (void)BlokTextUpdateEx(
        &pViewport->coordinatesText,
        &(POINT){pViewport->panel.region.left + 10, pViewport->panel.region.top + 10},
        &(SIZE){100, 20}, &(SIZE){0, 0});
    (void)StringCbPrintfW(pViewport->coordinatesText.data, BLOK_TEXT_SIZE, L"(0, 0)");

    (void)BlokButtonUpdateEx(&pViewport->clearAllButton,
                           &(POINT){pViewport->coordinatesText.region.right + 10,
                                    pViewport->coordinatesText.region.top},
                           &(SIZE){60, 20}, &(SIZE){0, 0});
    (void)StringCbPrintfW(pViewport->clearAllButton.text, BLOK_BUTTON_TEXT_SIZE, L"Clear All");

    (void)BlokButtonUpdateEx(&pViewport->generateButton,
                           &(POINT){pViewport->clearAllButton.region.right + 10,
                                    pViewport->clearAllButton.region.top},
                           &(SIZE){70, 20}, &(SIZE){0, 0});
    (void)StringCbPrintfW(pViewport->generateButton.text, BLOK_BUTTON_TEXT_SIZE,
                          L"Generate");

    (void)BlokTextUpdateEx(&pViewport->obstructCountText,
                         &(POINT){pViewport->generateButton.region.right + 10,
                                  pViewport->generateButton.region.top},
                         &(SIZE){25, 20}, &(SIZE){0, 0});
    (void)StringCbPrintfW(pViewport->obstructCountText.data, BLOK_TEXT_SIZE, L"0");

    (void)BlokProgressBarUpdateEx(&pViewport->obstructMemoryBar,
                                &(POINT){pViewport->obstructCountText.region.right + 10,
                                         pViewport->obstructCountText.region.top},
                                &(SIZE){70, 20}, &(SIZE){0, 0}, &(SIZE){3, 3});

    (void)BlokToggleUpdateEx(&pViewport->lockedToggle,
                           &(POINT){pViewport->obstructMemoryBar.region.right + 10,
                                    pViewport->obstructMemoryBar.region.top},
                           &(SIZE){20, 20}, &(SIZE){0, 0}, &(SIZE){5, 5});
    (void)BlokToggleUpdateSelected(&pViewport->lockedToggle, FALSE);

    (void)BlokTextUpdateEx(&pViewport->lockedToggleText,
                         &(POINT){pViewport->lockedToggle.region.right + 10,
                                  pViewport->lockedToggle.region.top},
                         &(SIZE){30, 20}, &(SIZE){0, 0});
    (void)StringCbPrintfW(pViewport->lockedToggleText.data, BLOK_TEXT_SIZE, L"Locked");

    return 1;
}

int BlokViewportShow(TViewport *pViewport, DWORD showFlag)
{
    if (pViewport == NULL)
    {
        return -1;
    }

    return BlokWindowShow(&pViewport->window, showFlag);
}

int BlokViewportFree(TViewport *pViewport, HINSTANCE hInstance)
{
    if (pViewport == NULL)
    {
        return 0;
    }

    if (pViewport->hFont != NULL)
    {
        (void)DeleteObject(pViewport->hFont);
    }

    return BlokWindowFree(&pViewport->window, hInstance);
}