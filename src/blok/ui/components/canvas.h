#ifndef BLOK_CANVAS_H
#define BLOK_CANVAS_H

#include <windows.h>

typedef struct _Canvas
{
    RECT region;
    SIZE size;
} TCanvas;

int BlokCanvasUpdate(TCanvas *pCanvas, const RECT *pWindowRgn);

#endif /* BLOK_CANVAS_H */