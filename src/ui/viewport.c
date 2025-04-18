#include "viewport.h"
#include <strsafe.h>
#include <time.h>

void BlokViewportInit(Viewport *viewport, HINSTANCE instance)
{
    if (!viewport) { return; }

    srand((unsigned int) time(0));

    BlokWindowInit(&viewport->window, instance);

    viewport->mouseDown = 0;
    viewport->isInterfaceVisible = 1;
    viewport->isGridVisible = 0;
    viewport->isCanvasLocked = 0;

    viewport->font = CreateFontW(
        16, 0, GM_COMPATIBLE, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
        OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, CLEARTYPE_QUALITY, FF_DONTCARE, 
        L"Segoe UI");
    
    if (!viewport->font)
    {
        (void) MessageBoxW(0, L"Font Loading Failed.", L"Blok", MB_OK | MB_ICONERROR);
    }

    (void) GetClientRect(viewport->window.handle, &viewport->region);

    BlokPanelUpdateEx(
        &viewport->panel, &viewport->region, &((COORD){500, 40}), &((COORD){0, 0}));
    BlokCanvasUpdate(&viewport->canvas, &viewport->region);
    
    BlokTextUpdateEx(
        &viewport->coordinatesText, 
        &((POINT){viewport->panel.region.left +10, viewport->panel.region.top +10}), 
        &((SIZE){100, 20}), &((SIZE){0, 0}));
    (void) StringCbPrintfW(viewport->coordinatesText.data, 60, L"(0, 0)");

    BlokButtonUpdateEx(
        &viewport->clearAllButton, 
        &((POINT){
            viewport->coordinatesText.region.right+10, 
            viewport->coordinatesText.region.top}), 
        &((SIZE){60, 20}), &((SIZE){0, 0}));
    (void) StringCbPrintfW(viewport->clearAllButton.text, 60, L"Clear All");

    BlokButtonUpdateEx(
        &viewport->generateButton, 
        &((POINT){
            viewport->clearAllButton.region.right+10, 
            viewport->clearAllButton.region.top}), 
        &((SIZE){70, 20}), &((SIZE){0, 0}));
    (void) StringCbPrintfW(viewport->generateButton.text, 60, L"Generate");

    BlokTextUpdateEx(
        &viewport->obstructCountText, 
        &((POINT){
            viewport->generateButton.region.right+10, 
            viewport->generateButton.region.top}),
        &((SIZE){25, 20}),
        &((SIZE){0, 0}));
    (void) StringCbPrintfW(viewport->obstructCountText.data, 60, L"0");

    BlokProgressBarUpdateEx(
        &viewport->obstructMemoryBar, 
        &((POINT){
            viewport->obstructCountText.region.right+10, 
            viewport->obstructCountText.region.top}),
        &((SIZE){70, 20}),
        &((SIZE){0, 0}),
        &((SIZE){3, 3}));
    
    BlokToggleUpdateEx(
        &viewport->lockedToggle,
        &((POINT){
            viewport->obstructMemoryBar.region.right+10,
            viewport->obstructMemoryBar.region.top}),
        &((SIZE){20, 20}), &((SIZE){0, 0}), &((SIZE){5, 5}));
    BlokToggleUpdateSelected(&viewport->lockedToggle, FALSE);

    BlokTextUpdateEx(
        &viewport->lockedToggleText, 
        &((POINT){
            viewport->lockedToggle.region.right+10, 
            viewport->lockedToggle.region.top}),
        &((SIZE){30, 20}),
        &((SIZE){0, 0}));
    (void) StringCbPrintfW(viewport->lockedToggleText.data, 60, L"Locked");
}

void BlokViewportShow(Viewport *viewport, DWORD showFlag)
{
    if (!viewport) { return; }

    BlokWindowShow(&viewport->window, showFlag);
}

void BlokViewportFree(Viewport *viewport, HINSTANCE instance)
{
    if (!viewport) { return; }

    if (viewport->font != (HFONT) 0)
    {
        (void) DeleteObject(viewport->font);
    }

    BlokWindowFree(&viewport->window, instance);
}