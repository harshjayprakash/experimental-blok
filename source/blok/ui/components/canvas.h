#ifndef _BLOK_CANVAS_H_
#define _BLOK_CANVAS_H_

#include <windows.h>

typedef struct _Canvas
{
    RECT region;
    SIZE size;
} TCanvas;

int blokCanvasUpdate(TCanvas *pCanvas, const RECT *pWindowRgn);

#endif /* _BLOK_CANVAS_H_ */