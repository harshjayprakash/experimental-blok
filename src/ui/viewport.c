#include "viewport.h"
#include <strsafe.h>
#include <time.h>

int blokViewportInit(Viewport *pViewport, HINSTANCE hInstance)
{
    if (pViewport == NULL)
        return 0;

    srand((unsigned int) time(0));

    blokWindowInit(&pViewport->window, hInstance);

    pViewport->isLeftMouseDown = 0;
    pViewport->isRightMouseDown = 0;
    pViewport->isInterfaceVisible = 1;
    pViewport->isGridVisible = 0;
    pViewport->isCanvasLocked = 0;

    pViewport->hFont = CreateFontW(
        16, 0, GM_COMPATIBLE, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
        OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, CLEARTYPE_QUALITY, FF_DONTCARE, 
        L"Segoe UI");
    
    if (pViewport->hFont == NULL)
    {
        (void)MessageBoxW(0, L"Font Loading Failed.", L"Blok", MB_OK | MB_ICONERROR);
    }

    (void) GetClientRect(pViewport->window.hHandle, &pViewport->region);

    blokPanelUpdateEx(
        &pViewport->panel, &pViewport->region, &((COORD){500, 40}), &((COORD){0, 0}));
    blokCanvasUpdate(&pViewport->canvas, &pViewport->region);
    
    blokTextUpdateEx(
        &pViewport->coordinatesText, 
        &((POINT){pViewport->panel.region.left +10, pViewport->panel.region.top +10}), 
        &((SIZE){100, 20}), &((SIZE){0, 0}));
    (void) StringCbPrintfW(pViewport->coordinatesText.data, 60, L"(0, 0)");

    blokButtonUpdateEx(
        &pViewport->clearAllButton, 
        &((POINT){
            pViewport->coordinatesText.region.right+10, 
            pViewport->coordinatesText.region.top}), 
        &((SIZE){60, 20}), &((SIZE){0, 0}));
    (void) StringCbPrintfW(pViewport->clearAllButton.text, 60, L"Clear All");

    blokButtonUpdateEx(
        &pViewport->generateButton, 
        &((POINT){
            pViewport->clearAllButton.region.right+10, 
            pViewport->clearAllButton.region.top}), 
        &((SIZE){70, 20}), &((SIZE){0, 0}));
    (void) StringCbPrintfW(pViewport->generateButton.text, 60, L"Generate");

    blokTextUpdateEx(
        &pViewport->obstructCountText, 
        &((POINT){
            pViewport->generateButton.region.right+10, 
            pViewport->generateButton.region.top}),
        &((SIZE){25, 20}),
        &((SIZE){0, 0}));
    (void) StringCbPrintfW(pViewport->obstructCountText.data, 60, L"0");

    blokProgressBarUpdateEx(
        &pViewport->obstructMemoryBar, 
        &((POINT){
            pViewport->obstructCountText.region.right+10, 
            pViewport->obstructCountText.region.top}),
        &((SIZE){70, 20}),
        &((SIZE){0, 0}),
        &((SIZE){3, 3}));
    
    blokToggleUpdateEx(
        &pViewport->lockedToggle,
        &((POINT){
            pViewport->obstructMemoryBar.region.right+10,
            pViewport->obstructMemoryBar.region.top}),
        &((SIZE){20, 20}), &((SIZE){0, 0}), &((SIZE){5, 5}));
    blokToggleUpdateSelected(&pViewport->lockedToggle, FALSE);

    blokTextUpdateEx(
        &pViewport->lockedToggleText, 
        &((POINT){
            pViewport->lockedToggle.region.right+10, 
            pViewport->lockedToggle.region.top}),
        &((SIZE){30, 20}),
        &((SIZE){0, 0}));
    (void) StringCbPrintfW(pViewport->lockedToggleText.data, 60, L"Locked");

    return 1;
}

int blokViewportShow(Viewport *pViewport, DWORD showFlag)
{
    if (pViewport == NULL)
        return 0;

    blokWindowShow(&pViewport->window, showFlag);

    return 1;
}

int blokViewportFree(Viewport *pViewport, HINSTANCE hInstance)
{
    if (pViewport == NULL)
        return 0;

    if (pViewport->hFont != NULL)
    {
        (void)DeleteObject(pViewport->hFont);
    }

    return blokWindowFree(&pViewport->window, hInstance);
}